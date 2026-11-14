#include "Fahrzeug.h"
#include <iomanip>
#include "Verhalten.h"


extern double dGlobaleZeit;

Fahrzeug::Fahrzeug()
{
}

Fahrzeug::Fahrzeug(const std::string &sName)
    : Simulationsobjekt(sName)
{
}

Fahrzeug::Fahrzeug(const std::string &sName, const double dMaxGeschwindigkeit)
    : Simulationsobjekt(sName),
      p_dMaxGeschwindigkeit((dMaxGeschwindigkeit > 0.0) ? dMaxGeschwindigkeit : 0.0)
{
    std::cout << "Fahrzeug " << sName << "mit Geschw" << p_dMaxGeschwindigkeit << "wird erstellt" << std::endl;
}

Fahrzeug::~Fahrzeug()
{
}

void Fahrzeug::vKopf()
{
    std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left)
              << std::setw(5) << "ID"
              << std::setw(15) << "Name"
              << std::setw(20) << "MaxGeschwindigkeit"
              << std::setw(20) << "GesamtStrecke"
              << std::setw(20) << "GesamtZeit"
              << std::setw(20) << "GesamtVerbrauch"
              << std::setw(15) << "Tankinhalt" << std::endl
              << std::setfill('-') << std::setw(110) << "" << std::endl
              << std::setfill(' ');
}

void Fahrzeug::vAusgeben(std::ostream &out) const
{
    Simulationsobjekt::vAusgeben(out);

    out << std::setw(20) << p_dMaxGeschwindigkeit
        << std::setw(20) << p_dGesamtStrecke
        << std::setw(20) << p_dGesamtZeit;
}

void Fahrzeug::vSimulieren()
{
    double dZeitDifferenz = dGlobaleZeit - p_dZeit;
    if (dZeitDifferenz > 0.0)
    {
        p_dGesamtZeit += dZeitDifferenz;
        double dTeilstrecke = p_pVerhalten->dStrecke(*this, dZeitDifferenz);
        p_dGesamtStrecke += dTeilstrecke;
        p_dZeit = dGlobaleZeit;
    }
}

double Fahrzeug::dTanken(const double dMenge)
{
    return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const
{
    return p_dMaxGeschwindigkeit;
}

bool Fahrzeug::operator<(const Fahrzeug &rhs) const
{
    return this->p_dGesamtStrecke < rhs.p_dGesamtStrecke;
}

Fahrzeug &Fahrzeug::operator=(const Fahrzeug &rhs)
{
    if (this != &rhs)
    {
        Simulationsobjekt::operator=(rhs);
        p_dMaxGeschwindigkeit = rhs.p_dMaxGeschwindigkeit;
    }
    return *this;
}

double Fahrzeug::getMaxGesch()
{
    return p_dMaxGeschwindigkeit;
}

void Fahrzeug::vNeueStrecke(Weg& Weg)
{

}