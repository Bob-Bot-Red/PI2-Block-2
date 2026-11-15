#ifndef STRECKENENDE_H
#define STRECKENENDE_H

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme
{
public:
Streckenende(Fahrzeug &fahrzeug, Weg &weg);

virtual ~Streckenende() override = default;
    void vBearbeiten() override;
};

#endif