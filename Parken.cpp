#include "Parken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"


extern double dGlobaleZeit;

Parken::Parken(Weg &weg, double dStartZeitpunkt)
    : Verhalten(weg),
      p_dStartZeitpunkt(dStartZeitpunkt)
{
}

double Parken::dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const
{
    if (dGlobaleZeit < p_dStartZeitpunkt)
    {
        return 0.0;
    }
    if (!p_bStartmeldungAusgegeben)
    {
        p_bStartmeldungAusgegeben = true;
        throw Losfahren(aFzg, getWeg());
    }
    return aFzg.dGeschwindigkeit() * dZeitIntervall;
}