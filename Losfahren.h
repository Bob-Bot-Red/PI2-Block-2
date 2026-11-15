#ifndef LOSFAHREN_H
#define LOSFAHREN_H

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme
{
    public:
    Fahrausnahme();
    virtual ~Fahrausnahme();

    void vArbeiten() override;

};

#endif