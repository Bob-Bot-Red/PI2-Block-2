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
    Weg Autobahn1("Ernst", 200.0, Tempolimit::Autobahn);

    Autobahn1.Annahme(std::make_unique<PKW>("Audi", 80.0, 6.0));
    Autobahn1.Annahme(std::make_unique<PKW>("Mercedes", 100.0, 68.0));
    Autobahn1.Annahme(std::make_unique<Fahrrad>("lol", 35.0));

    for (int i = 0; i < 3; i++)
    {
        dGlobaleZeit = i * 0.5;
        Autobahn1.vSimulieren();
        std::cout << "\n Globale" << dGlobaleZeit << std::endl;
        std::cout << Autobahn1 << "\n" << std::endl;
        Autobahn1.vFahrzeugeAusgeben();

    }
}
int main()
{
    /*
    vAufgabe_1();
    vAufgabe_1a();
    vAufgabe_AB1();
    vAufgabe_2();
    vAufgabe_3();
    vAufgabe_4();
    */
   vAufgabe_5();

    return 0;
}