#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "Simulationsobjekt.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Fahrausnahme.h"
#include "SimuClient.h"

using namespace std;
double dEpsilon = 0.001;
double dGlobaleZeit = 0.0;

void vAufgabe_AB1()
{

    int l = 0; // Laufindex für gezielte AUsgabe
    vector<int> ausgabe{15};
    double dTakt = 0.3;

    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
    vecFahrzeuge.push_back(make_unique<PKW>("Audi", 231, 11.4));
    vecFahrzeuge.push_back(make_unique<Fahrrad>("BMX", 19.8));
    for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
    {
        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
        if (itL != ausgabe.end())
        {
            std::cout << std::endl
                      << l << " Globalezeit = " << dGlobaleZeit << std::endl;
            Fahrzeug::vKopf();
        }

        for (int i = 0; i < vecFahrzeuge.size(); i++)
        {
            vecFahrzeuge[i]->vSimulieren();
            if (fabs(dGlobaleZeit - 3.0) < dTakt / 2)
            {
                vecFahrzeuge[i]->dTanken();
            }
            if (itL != ausgabe.end())
            {
                std::cout << *vecFahrzeuge[i] << endl;
            }
        }
        l++;
    }
    char c;
    std::cin >> c;
}

void vAufgabe_1()
{
    Fahrzeug statishes("Porsche");
    Fahrzeug *p_dynamisches = new Fahrzeug("Audi");
    std::unique_ptr<Fahrzeug> ptr1 = std::make_unique<Fahrzeug>("a");
    std::unique_ptr<Fahrzeug> ptr2 = std::make_unique<Fahrzeug>("b");
    std::shared_ptr<Fahrzeug> ptr3 = std::make_shared<Fahrzeug>("c");
    std::shared_ptr<Fahrzeug> ptr4 = std::make_shared<Fahrzeug>("d");
    std::cout << "Vorher ptr3" << ptr3.use_count() << std::endl;

    std::shared_ptr<Fahrzeug> ptr5 = ptr3;

    std::cout << "Nachher ptr3" << ptr3.use_count() << std::endl;
    // std::shared_ptr<Fahrzeug> ptr6 = ptr1;
    // Dies klappt nicht da nur einen Besitzer möglich man braucht sowas wie move

    ptr4 = std::move(ptr2);

    std::vector<std::shared_ptr<Fahrzeug>> v_ptr1 = {ptr3, ptr4};
    // Ich kann hiert nur shared ptr Objekte Speichern.
    v_ptr1[0].use_count();
    v_ptr1[1].use_count();

    Fahrzeug::vKopf();
    for (const auto &pFahrzeug : v_ptr1)
    {
        std::cout << *pFahrzeug << std::endl;
        std::cout << std::endl;
    }
    v_ptr1.clear();

    delete p_dynamisches;
}

void vAufgabe_1a()
{
    std::vector<std::unique_ptr<Fahrzeug>> vFahrzeug;

    for (int i = 0; i < 3; i++)
    {
        std::string sAutoName;
        double dAutoSpeed;
        std::cout << "Bitte Auto Name " << i + 1 << " eingeben: ";
        std::cin >> sAutoName;
        std::cout << "Bitte MaxGeschwi. eingeben: ";
        std::cin >> dAutoSpeed;
        auto pFahrzeug = std::make_unique<Fahrzeug>(sAutoName, dAutoSpeed);
        vFahrzeug.push_back(std::move(pFahrzeug));
    }

    double dZeittakt = 0.5;
    for (dGlobaleZeit = dZeittakt; dGlobaleZeit <= 3.0; dGlobaleZeit += dZeittakt)
    {
        std::cout << "Globale Teit:" << dGlobaleZeit << std::endl
                  << std::endl;
        Fahrzeug::vKopf();
        for (const auto &pFahrzeug : vFahrzeug)
        {
            pFahrzeug->vSimulieren();
            std::cout << *pFahrzeug << std::endl;
        }
        std::cout << std::endl;
    }
}

void vAufgabe_2()
{
    std::vector<std::unique_ptr<Fahrzeug>> vFahrzeuge;

    int iAnzahlPKW = 0;
    int iAnzahlFahrrad = 0;

    std::cout << "Wie viele PKWs sollen erzeugt? ";
    std::cin >> iAnzahlPKW;
    for (int i = 0; i < iAnzahlPKW; i++)
    {
        std::string sName;
        double dSpeed, dVerbrauch, dTankvolumen;
        std::cout << "PKW " << i + 1 << " Name, MaxGeschwindigkeit, Verbrauch, Tankvolumen: ";
        std::cin >> sName >> dSpeed >> dVerbrauch >> dTankvolumen;
        vFahrzeuge.push_back(std::make_unique<PKW>(sName, dSpeed, dVerbrauch, dTankvolumen));
    }
    std::cout << "Wie viele Fahrraeder sollen erzeugt?  ";
    std::cin >> iAnzahlFahrrad;
    for (int i = 0; i < iAnzahlFahrrad; i++)
    {
        std::string sName;
        double dSpeed;

        std::cout << "Fahrrad " << i + 1 << " Name, MaxGeschwindigkei:  ";
        std::cin >> sName >> dSpeed;
        vFahrzeuge.push_back(std::make_unique<Fahrrad>(sName, dSpeed));
    }

    double dZeittakt = 0.5;
    // double dEpsilon = 1e-6;

    for (dGlobaleZeit = dZeittakt; dGlobaleZeit <= 5.0 + dEpsilon; dGlobaleZeit += dZeittakt)
    {
        std::cout << "\nGlobale Zeit: " << dGlobaleZeit << std::endl;

        if (std::fabs(dGlobaleZeit - 3.0) < 1e-6)
        {
            std::cout << "--- 3.0 Stunden erreicht: PKWs tanken! ---";
            for (const auto &pFahrzeug : vFahrzeuge)
            {
                pFahrzeug->dTanken();
            };
            std::cout << std::endl;
        }

        Fahrzeug::vKopf();
        for (const auto &pFahrzeuge : vFahrzeuge)
        {
            pFahrzeuge->vSimulieren();
            std::cout << *pFahrzeuge << std::endl;
            std::cout << std::endl;
        }
    }
}

void vAufgabe_3()
{
    std::cout << "Test der Operatoren Auf. 3" << std::endl;
    PKW pkw1("Mercedesm", 200.0, 10.0, 60.0);
    Fahrrad fahrrad1("BMX", 25.0);

    Fahrzeug::vKopf();
    std::cout << pkw1 << std::endl;
    std::cout << fahrrad1 << std::endl;

    std::cout << "\n 1 stunde\n";
    dGlobaleZeit += 1.0;
    pkw1.vSimulieren();
    fahrrad1.vSimulieren();

    Fahrzeug::vKopf();
    std::cout << pkw1 << std::endl;
    std::cout << fahrrad1 << std::endl;

    if (fahrrad1 < pkw1)
    {
        std::cout << "Fahrrad fährt lürzere strecke " << std::endl;
    }

    std::cout << "Stammdaten PKW in Kopie: " << std::endl;
    PKW kopie("LeereKopie", 0.0, 0.0);
    kopie = pkw1;
    Fahrzeug::vKopf();
    std::cout << pkw1 << std::endl;
    std::cout << kopie << std::endl;
}

void vAufgabe_4()
{
    Weg::vKopf();
    Weg erster("Name", 22.0, Tempolimit::Autobahn);
    erster.vSimulieren();
    std::cout << 0;
}

void vAufgabe_5()
{

    {
        Weg Autobahn1("Ernst", 200.0, Tempolimit::Autobahn);

        Autobahn1.vAnnahme(std::make_unique<PKW>("Audi", 80.0, 6.0));
        Autobahn1.vAnnahme(std::make_unique<PKW>("Mercedes", 100.0, 68.0));
        Autobahn1.vAnnahme(std::make_unique<Fahrrad>("lol", 35.0));

        for (int i = 0; i < 3; i++)
        {
            dGlobaleZeit = i + 0.5;
            try
            {
                Autobahn1.vSimulieren();
            }
            catch (Fahrausnahme &ausnahme)
            {
                ausnahme.vBearbeiten();
            }
            std::cout << "\n Globale" << dGlobaleZeit << std::endl;
            std::cout << Autobahn1 << "\n"
                      << std::endl;
            Autobahn1.vFahrzeugeAusgeben();
        }
    }
}

void vAufgabe_6()
{
    constexpr int iWeglaenge = 500;
    int koordinaten[] = {700, 250, 100, 250};

    bool bGrafikAktiv = bInitialisiereGrafik(800, 500);

    if (bGrafikAktiv)
    {
        if (!bZeichneStrasse("Stadt", "Autobahn", iWeglaenge, 2, koordinaten))
        {
            std::cerr << "Die Strasse konnte nicht gezeichnet werden.\n";
            vBeendeGrafik();
            bGrafikAktiv = false;
        }
    }
    else
    {
        std::cerr << "Grafikserver nicht erreichbar. Simulation laeuft im Terminal.\n";
    }

    for (double dZeitschritt : {0.25, 0.3})
    {
        Weg stadt("Stadt", iWeglaenge, Tempolimit::Innerorts);
        Weg autobahn("Autobahn", iWeglaenge);

        stadt.vAnnahme(std::make_unique<PKW>("Audi", 120.0, 6.0));
        autobahn.vAnnahme(std::make_unique<PKW>("BMW", 120.0, 6.0));
        stadt.vAnnahme(std::make_unique<PKW>("VW", 100.0, 5.0), 3.0);
        autobahn.vAnnahme(std::make_unique<PKW>("Opel", 100.0, 5.0), 3.0);

        std::cout << "\nZeittakt " << dZeitschritt << " h\n";

        // Bei 50 km/h braucht der Audi 10 h für 500 km.
        // Bis 10.5 h sieht man auch die Meldung im Folgeschritt.
        for (dGlobaleZeit = 0.0; dGlobaleZeit <= 10.5 + 1e-9;
             dGlobaleZeit += dZeitschritt)
        {
            std::cout << "\n===== Zeit " << dGlobaleZeit << " h =====\n";

            if (bGrafikAktiv)
            {
                vSetzeZeit(dGlobaleZeit);
            }

            stadt.vSimulieren();
            autobahn.vSimulieren();

            Weg::vKopf();
            std::cout << stadt << '\n'
                      << autobahn << '\n';

            std::cout << "\nFahrzeuge auf Stadt\n";
            stadt.vFahrzeugeAusgeben();

            std::cout << "\nFahrzeuge auf Autobahn\n";
            autobahn.vFahrzeugeAusgeben();

            if (bGrafikAktiv)
            {
                vSleep(100);
            }
        }
    }

    if (bGrafikAktiv)
    {
        vBeendeGrafik();
    }
}

void vZwischendurchtest()
{
    Weg Autobahn1("Autobahn1", 200.0, Tempolimit::Autobahn);
    Weg Autobahn2("Autobahn2", 200.0, Tempolimit::Autobahn);
    Autobahn1.vAnnahme(std::make_unique<PKW>("Audi", 120.0, 6.0));
    Autobahn2.vAnnahme(std::make_unique<PKW>("BMW", 120.0, 6.0));

    bInitialisiereGrafik(800, 500);
    int koordinaten[] = {700, 250, 100, 250};
    bZeichneStrasse("Autobahn1", "Autobahn2", 100, 2, koordinaten);
    double dZeitschritte = 0.3;
    for (double dZeit = 0.0; dZeit <= 10.0 + dEpsilon; dZeit += dZeitschritte)
    {
        dGlobaleZeit = dZeit;
        vSetzeZeit(dGlobaleZeit);
        Autobahn1.vSimulieren();
        Autobahn2.vSimulieren();
        Weg::vKopf();
        std::cout << Autobahn1 << "\n" << Autobahn2 << std::endl;
        bZeichnePKW("Audi", "Autobahn1", 0.5, 120, 55);
        Autobahn1.vFahrzeugeAusgeben();        
        bZeichnePKW("BMW", "Autobahn2", 0.5, 120, 55);
        Autobahn2.vFahrzeugeAusgeben();
        vSleep(100);
    }
    vBeendeGrafik();
}

int main()
{
    /*
    vAufgabe_5();
    vAufgabe_1();
    vAufgabe_1a();
    vAufgabe_AB1();
    vAufgabe_2();
    vAufgabe_3();
    vAufgabe_4();
    vAufgabe_6();
    */
   vZwischendurchtest();
    return 0;
}