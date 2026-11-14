#ifndef FAHRRAD_H
#define FAHRRAD_H

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{

public:
    Fahrrad();
    Fahrrad(const std::string &sName, const double dMaxGeschwindkeit);
    virtual ~Fahrrad();
    double dGeschwindigkeit() const override;

private:
};

#endif