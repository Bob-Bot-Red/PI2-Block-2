#ifndef VERHALTEN_H
#define VERHALTEN_H

class Weg;
class Fahrzeug;

class Verhalten
{
public:
    Verhalten(Weg &pWeg);
    virtual ~Verhalten();
    double dStrecke(Fahrzeug &aFzg, double dZeitIntervall) const;
    Weg &getWeg() const;

private:
    Weg &p_pWeg;
};

#endif