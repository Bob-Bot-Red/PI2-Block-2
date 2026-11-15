#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren(Weg &pWeg)
: Verhalten(pWeg)
{
}

double Fahren::dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const
{
    const double dRest = getWeg().getLaenge() - aFzg.getAbschnittstrecke();
    if(dRest <= 0.0)
    {
        throw Streckenende(aFzg, getWeg());
    }

    const double dMoeglicheStrecke = aFzg.dGeschwindigkeit() * dZeitIntervall;

    if(dMoeglicheStrecke >= dRest)
    {
        return dRest;
    }
    return dMoeglicheStrecke;
}
