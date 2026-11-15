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
    constexpr double dEpsilon = 1e-9;
    if (dGlobaleZeit + dEpsilon < p_dStartZeitpunkt)
    {
        return 0.0;
    }
    throw Losfahren(aFzg,getWeg());
}