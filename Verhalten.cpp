#include "Verhalten.h"
#include "Fahrzeug.h"

Verhalten::Verhalten(Weg &pWeg)
: p_pWeg(pWeg)
{
}

double Verhalten::dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const
{
    return aFzg.dGeschwindigkeit() * dZeitIntervall;
}

