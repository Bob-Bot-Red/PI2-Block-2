#ifndef STRECKENENDE_H
#define STRECKENENDE_H

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme
{
public:

virtual ~Streckenende() override = default
    void vArbeiten() override;
};

#endif