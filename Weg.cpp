#include "Weg.h"
#include "Fahrzeug.h"
#include <iomanip>
#include <utility>

Weg::Weg()
    : Weg("", 0.0, Tempolimit::Autobahn)
{
}

Weg::Weg(const std::string &sName, double dLaenge, Tempolimit eTempolimit)
    : Simulationsobjekt(sName),
      p_dLaenge(dLaenge), p_eTempolimit(eTempolimit)
{
}

Weg::~Weg()
{
}

void Weg::vSimulieren()
{
    for (const auto &Autos : p_pFahrzeuge)
    {
        Autos->vSimulieren();
    };
}

void Weg::vAusgeben(std::ostream &out) const
{
    Simulationsobjekt::vAusgeben(out);
    out << std::setw(15) << p_dLaenge;
    out << "(";
    for (const auto &pAuto : p_pFahrzeuge)
    {
        out << pAuto->getName() << " ";
    };
    out << ")";
}

double Weg::getTempolimit() const
{
    return static_cast<double>(p_eTempolimit);
}

void Weg::vKopf()
{
    std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left)
              << std::setw(5) << "ID"
              << std::setw(15) << "Name"
              << std::setw(15) << "Laenge"
              << std::setw(20) << "Fahrzeuge" << std::endl
              << std::setfill('-') << std::setw(55) << "" << std::endl
              << std::setfill(' ');
}

void Weg::Annahme(std::unique_ptr<Fahrzeug> fahrzeug)
{
    if (!fahrzeug)
    {
        return;
    }
    else
        fahrzeug->vNeueStrecke(*this);
    p_pFahrzeuge.push_back(std::move(fahrzeug));
}