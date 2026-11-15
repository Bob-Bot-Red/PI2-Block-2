#ifndef WEG_H
#define WEG_H

#include "Simulationsobjekt.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"
#include <list>
#include <memory>

class Fahrzeug;

class Weg : public Simulationsobjekt
{

public:
    Weg();
    Weg(const std::string &sName, double dLaenge, Tempolimit eTempolimit);
    virtual ~Weg();

    static void vKopf();
    virtual void vSimulieren() override;
    virtual void vAusgeben(std::ostream &out) const override;
    double getTempolimit() const;
    void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug);
    void vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double dStartZeitpunkt);
    void vFahrzeugeAusgeben() const;
    double getLaenge() const;
private:
    double p_dLaenge = 0.0;
    Tempolimit p_eTempolimit;
    std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
};

#endif