#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H

#include <exception>
#include <stdexcept>
#include "Weg.h"
#include "Fahrzeug.h"

class Fahrausnahme : public std::exception
{
public:
    Fahrausnahme(Fahrzeug &fahrzeug, Weg &weg);
    virtual void vArbeiten() = 0;
    virtual ~Fahrausnahme();

    protected:
    Fahrzeug &p_pFahrzeug;
    Weg &p_pWeg;
    private:
};

#endif