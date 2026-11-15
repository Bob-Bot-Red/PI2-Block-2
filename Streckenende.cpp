#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug &fahrzeug, Weg &weg)
:Fahrausnahme(fahrzeug, weg)
{
}


void Streckenende::vArbeiten()
{
std::cout << "Streckenende: Fahrzeug " << p_pFahrzeug.getName() 
    << " auf Weg " << p_pWeg.getName() << std::endl;
}