#include "Simulationsobjekt.h"
#include <iomanip>

extern double dGlobaleZeit;

int Simulationsobjekt::p_iMaxID = 0; // Initialisierung der statischen Variable p_iMaxID

Simulationsobjekt::Simulationsobjekt() : Simulationsobjekt("")
{
}

Simulationsobjekt::Simulationsobjekt(const std::string &sName)
    : p_sName(sName),
      p_iID(++p_iMaxID)
{
    std::cout << "Fahrzeug " << p_sName << std::endl
              << "name: " << p_iID << std::endl;
}

Simulationsobjekt::~Simulationsobjekt()
{
    std::cout << "Fahrzeug " << p_sName << " mit ID " << p_iID << " wird gelöscht." << std::endl;
}

void Simulationsobjekt::vAusgeben(std::ostream &out) const
{
    std::cout << std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left)
              << std::setw(5) << p_iID
              << std::setw(15) << p_sName;
}

int Simulationsobjekt::getID() const
{
    return p_iID;
}

const std::string &Simulationsobjekt::getName()
{
    return p_sName;
}

bool Simulationsobjekt::operator==(const Simulationsobjekt &rhs)
{
    return this->p_iID == rhs.p_iID;
}

Simulationsobjekt &Simulationsobjekt::operator=(const Simulationsobjekt &rhs)
{
    if (this != &rhs)
    {
        p_sName = rhs.p_sName;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Simulationsobjekt &s)
{
    s.vAusgeben(out);
    return out;
}