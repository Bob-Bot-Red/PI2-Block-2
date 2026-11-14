#ifndef PARKEN_H
#define PARKEN_H
#include "Verhalten.h"
#include "Weg.h"

class Parken : public Verhalten
{
    Parken(Weg &weg, double dStartZeitpunkt);
    double dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const override;

    protected:
    double p_dStartZeitpunkt;
};

#endif