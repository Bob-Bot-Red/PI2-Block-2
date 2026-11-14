#include "Fahrrad.h"
#include "Simulationsobjekt.h"
#include <cmath>
#include <algorithm>

Fahrrad::Fahrrad() : Fahrzeug()
{
}

Fahrrad::Fahrrad(const std::string &sName, const double dMaxGeschwindkeit)
    : Fahrzeug(sName),
    p_dMaxGeschwindigkeit((dMaxGeschwindkeit > 0.0) ? dMaxGeschwindkeit : 0.0)
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dGeschwindigkeit() const
{
    //* wandeln in int wegen division
    int iAbschnitte = static_cast<int>(p_dGesamtStrecke /20.0);
    //*0.9^Abschnitte 
    double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * std::pow(0.9, iAbschnitte);
    return (dAktuelleGeschwindigkeit >= 12.0) ? dAktuelleGeschwindigkeit : 12.0;
}