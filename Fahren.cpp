#include "Fahren.h"
#include "Fahrzeug.h"

Fahren::Fahren(Weg &pWeg)
: Verhalten(pWeg)
{
}

double Fahren::dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const
{
return aFzg.dGeschwindigkeit() * dZeitIntervall;
}
