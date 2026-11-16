#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug &fahrzeug, Weg &weg)
    : Fahrausnahme(fahrzeug, weg)
{
}

void Streckenende::vBearbeiten()
{
    std::cout << "Streckenende: Fahrzeug " << p_pFahrzeug.getName()
              << " auf Weg " << p_pWeg.getName() << std::endl;
    Fahrzeug *pFahrzeug = &p_pFahrzeug;
    Weg* pWeg = &p_pWeg;
    p_pWeg.vVerzoegert([pFahrzeug, pWeg]()
                       { auto pAbgegebenesFahrzeug = pWeg->pAbgabe(*pFahrzeug);});
}