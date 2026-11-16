#include "Fahrrad.h"
#include <cmath>
#include <algorithm>
#include "Weg.h"
#include "SimuClient.h"

Fahrrad::Fahrrad() : Fahrzeug()
{
}

Fahrrad::Fahrrad(const std::string &sName, const double dMaxGeschwindkeit)
    : Fahrzeug(sName, dMaxGeschwindkeit)
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dGeschwindigkeit() const
{
    double iAbschnitte = std::floor(p_dGesamtStrecke /20.0); //rundet nach unten
    double dGeschwindigkeit = p_dMaxGeschwindigkeit * std::pow(0.9, iAbschnitte);
    return std::min(p_dMaxGeschwindigkeit, std::max(12.0, dGeschwindigkeit)); //max, gibt größter Wert(wenn 12 dann anderer zu niederig), dann das kleinsten der Werten

}

void Fahrrad::vZeichnen(const Weg &FzgWeg) const
{
    if(FzgWeg.getLaenge() <= 0.0)
    {
        return;
    }
    const double dRelPosition = p_dAbschnittStrecke / FzgWeg.getLaenge();
    bZeichneFahrrad(getName(), FzgWeg.getName(), dRelPosition, dGeschwindigkeit());
}