#ifndef LOSFAHREN_H
#define LOSFAHREN_H

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme
{
    public:
    //Fahrausnahme();
    Losfahren(Fahrzeug& fahrzeug, Weg& weg);
    ~Losfahren() override = default;
    void vBearbeiten() override;

};

#endif