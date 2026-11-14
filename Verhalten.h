#ifndef VERHALTEN_H
#define VERHALTEN_H

class Weg;
class Fahrzeug;

class Verhalten
{
public:
    Verhalten(Weg &pWeg);
     double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) const;
private:
Weg& p_pWeg;
};

#endif