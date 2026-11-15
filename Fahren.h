#ifndef FAHREN_H
#define FAHREN_H

#include "Verhalten.h"

class Fahren : public Verhalten
{
public:
    Fahren(Weg &pWeg);
    virtual ~Fahren() = default;
    double dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const override;
    double getAbschnittstrecke() const
    {
return p_dAbschnittStrecke;
    }
};
#endif