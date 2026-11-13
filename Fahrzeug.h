#ifndef FAHRZEUG_H
#define FAHRZEUG_H // Sicherung falls ich öfter mal die gleiche Datei einbinde, nicht so lange Ladezeit usw.

#include "Simulationsobjekt.h"
#include <limits>

class Fahrzeug : public Simulationsobjekt
{
public:
    Fahrzeug();
    Fahrzeug(const std::string &sName);
    Fahrzeug(const std::string &sName, const double p_dMaxGeschwindigkeit);
    virtual ~Fahrzeug();
    
    static void vKopf();
    virtual void vAusgeben(std::ostream &out) const override;
    void vSimulieren() override;

    virtual double dTanken(const double dMenge = std::numeric_limits<double>::infinity());
    virtual double dGeschwindigkeit() const;

    bool operator<(const Fahrzeug &rhs) const;
    Fahrzeug &operator=(const Fahrzeug &rhs);

protected:
    double p_dMaxGeschwindigkeit = 0.0;
    double p_dGesamtStrecke = 0.0;
    double p_dGesamtZeit = 0.0;

private:
};



#endif // FAHRZEUG_H , Ende der Schreibweise hier, damit der Präprozessor weiß,
       // dass die Datei zu Ende ist