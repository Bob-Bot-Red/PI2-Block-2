#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H

#include <exception>
#include <stdexcept>
#include "Weg.h"
#include "Fahrzeug.h"
#include <memory>

class Fahrausnahme : public std::exception
{
public:
    Fahrausnahme(Fahrzeug &fahrzeug, Weg& weg);
    virtual void vArbeiten() = 0;
    virtual ~Fahrausnahme();

    private:
    std::unique_ptr<Fahrzeug> p_aFahrzeug;
    Weg &p_aWeg;
};

#endif