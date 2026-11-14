#ifndef PARKEN_H
#define PARKEN_H
#include "Verhalten.h"
#include "Weg.h"

class Parken : public Verhalten
{
    public:
    Parken(Weg &weg, double dStartZeitpunkt);
    double dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const override;

    private:
    double p_dStartZeitpunkt;
    mutable bool p_bStartmeldungAusgegeben = false;

};

#endif