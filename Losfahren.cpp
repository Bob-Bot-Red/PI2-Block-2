#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include <iostream>

Losfahren::Losfahren(Fahrzeug &fahrzeug, Weg &weg)
:Fahrausnahme(fahrzeug, weg)
{
}

void Losfahren::vBearbeiten()
{
    std::cout << "Losfahren: Fahrzeug " << p_pFahrzeug.getName() 
    << " auf Weg " << p_pWeg.getName() << std::endl;
}