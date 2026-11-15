#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H

#include <exception>
#include <stdexcept>
class Weg;
class Fahrzeug;

class Fahrausnahme : public std::exception
{
public:
    Fahrausnahme(Fahrzeug &fahrzeug, Weg &weg);
    virtual void vBearbeiten() = 0;
    virtual ~Fahrausnahme() = default;

    protected:
    Fahrzeug &p_pFahrzeug;
    Weg &p_pWeg;
};

#endif