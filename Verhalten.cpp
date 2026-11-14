#include "Verhalten.h"


Verhalten::Verhalten(Weg &pWeg)
    : p_pWeg(pWeg)
{
}

Verhalten::~Verhalten()
{
}

double Verhalten::dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const
{
}

Weg &Verhalten::getWeg() const
{
    return p_pWeg;
}