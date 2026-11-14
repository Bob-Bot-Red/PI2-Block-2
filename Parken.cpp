#include "Parken.h"
#include "Fahrzeug.h"

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
        std::cout << "Fahrzeug " << aFzg.getName() 
        << "Startet bei Zeit " << p_dStartZeitpunkt << std::endl;
        p_bStartmeldungAusgegeben = true;
    }
    return aFzg.dGeschwindigkeit() * dZeitIntervall;
}