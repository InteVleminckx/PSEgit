/*
 * korte beschrijving:
 * Klasse (Vaccinatiecentrum) om een vaccinatiecentrum aan te maken, en de vaccinaties in het centrum te regelen.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/06/2021
 * @version: Specificatie 2.1
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#define PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>  // Required for stringstreams
#include <fstream>
#include "DesignByContract.h"
#include "Vaccin.h"

using namespace std;

class Vaccinatiecentrum {

    string fNaam;
    string fAdres;
    int fInwoners;
    int fCapaciteit;
    int fVaccinatedFirstTime;  // aantal gevaccineerden bij eerste inenting
    int fVaccinatedSecondTime; // aantal gevaccineerde die al een hernieuwing hebben gehad
    int fLadingen;
    map<pair<int, string>, int> fGebruikteVaccins;
    Vaccinatiecentrum* _initCheck;
    map<string, int> fVaccinsInCentrum; // fVaccinsInCentrum in het centrum

public:
    /*
     * @functie: Vaccinatiecentrum
     * Constructor voor een vaccinatiecentrum.
     * ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");
     */
    Vaccinatiecentrum();

    /*
     * @functie: vaccinatieHernieuwing
     * Deze functie voert de hernieuwingen uit.
     * @param vaccin : Vaccin, het vaccin waar de hernieuwing mee moet gebeuren
     * @param day : int, de dag van de hernieuwing
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieHernieuwing");
     */
    void vaccinatieHernieuwing(Vaccin* vaccin, int day, ofstream &OT);

    /*
     * @functie: vaccinatieFirstTime
     * Wanneer er geen hernieuwingen moeten plaatsvinden dan worden er mensen die nog niet gevaccineerd
     * zijn voor de eerste keer gevaccineerd. Dit wordt hier bepaalt, het aan transport wordt hier dan
     * ook ineens berekent.
     * @param vaccin : Het vaccin die wordt gebruikt om te vaccineren.
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * @param day : de huidige dag waar ons bevinden in de simulatie
     * @param teVaccineren : controllen waarde om voor te breaken van de for loop, wanneer er geen nieuwe berekingen
     *                       meer gedaan moeten worden
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieFirstTime");
     */
    void vaccinatieFirstTime(Vaccin* vaccin, ofstream &OT, int day, int &teVaccineren);

    /*
     * @functie : vaccinatieInCentrum
     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het Vaccinatiecentrum.
     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal fVaccinsInCentrum in
     * het centrum, en daarnaast wordt het aantal fVaccinsInCentrum in het centrum verlaagd.
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieInCentrum");
     */
    int vaccinatieInCentrum(Vaccin* vaccin, int teVaccineren, int day);

    /*
     * @functie: eraseDayfromGebruikteVaccins
     * Wanneer we een hernieuwing hebben gedaan, kunnen we dit verwijderen uit de map
     * @param dagHernieuwing
     * @param type
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling eraseDayfromGebruikteVaccins");
     */
    void eraseDayfromGebruikteVaccins(int dagHernieuwing, string &type);

    /*
     * @functie: setNaam
     * Deze functie zet de fNaam van het vaccinatiecentrum.
     * @param Cnaam : string, fNaam van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setNaam");
     * REQUIRE((!Cnaam.empty()), "Een vaccininatiecentrum moet een fNaam hebben, met minstens 1 karakter.");
     * ENSURE((getNaam() == Cnaam), "setNaam postcondition failure.");
     */
    void setNaam(string &Cnaam);
    /*
     * @functie: setAdres
     * Deze functie zet het fAdres van het vaccinatiecentrum.
     * @param Cadres : string, fAdres van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setAdres");
     * REQUIRE((!Cadres.empty()), "Het fAdres moet minstens 1 karakter.");
     * ENSURE((getAdres() == Cadres), "setAdres postcondition failure.");
     */
    void setAdres(string &Cadres);
    /*
     * @functie: setInwoners
     * Deze functie zet het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @param Cinwoners : int, aantal inwoners in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setInwoners");
     * REQUIRE((Cinwoners > 0), "Een gebied heeft meer dan 0 inwoners.");
     * ENSURE((getInwoners() == Cinwoners), "setInwoners postcondition failure.");
     */
    void setInwoners(int &Cinwoners);
    /*
     * @functie: setCapaciteit
     * Deze functie zet de fCapaciteit van het vaccinatiecentrum.
     * @param Ccapaciteit : int, fCapaciteit van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setCapaciteit");
     * REQUIRE((Ccapaciteit > 0), "Een vaccininatiecentrum heeft een grotere fCapaciteit dan 0.");
     * ENSURE((getCapaciteit() == Ccapaciteit), "setCapaciteit postcondition failure.");
     */
    void setCapaciteit(int &Ccapaciteit);

    /*
     * @functie: setVaccins
     * Deze functie zet het aantal fVaccinsInCentrum die het vaccinatiecentrum in bezit heeft.
     * @param Cvaccinaties : int, aantal fVaccinsInCentrum in het vaccinatiecentrum.
     * @param type : type van het vaccins.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccins");
     * REQUIRE((Cvaccinaties >= 0), "Een vaccininatiecentrum heeft 0 of meer fVaccinsInCentrum in bezit.");
     * ENSURE((getVaccins() == Cvaccinaties), "setVaccins postcondition failure.");
     */
    void setVaccins(int Cvaccinaties, string &type);

    /*
     * @functie: setVaccinatedFirstTime
     * Deze functie zet het aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * @param Cvaccinated : int, aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinated");
     * REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
     * ENSURE((getVaccinatedFirstTime() == Cvaccinated), "setVaccinatedFirstTime postcondition failure.");
     */
    void setVaccinatedFirstTime(int Cvaccinated);

    /*
     * @functie: setVaccinatedSecondTime
     * Deze functie zet het aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * @param Cvaccinated : int, aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinated");
     * REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
     * ENSURE((getVaccinatedFirstTime() == Cvaccinated), "setVaccinatedFirstTime postcondition failure.");
     */
    void setVaccinatedSecondTime(int Cvaccinated);

    /*
     * @functie: setGebruikteVaccins
     * Slaagt in een map op hoeveel personen er een hernieuwing moeten krijgen met een vaccin dat ze
     * de vorige keer hebben gekregen en op welke dag.
     * @param dagHernieuwing : int, dag dat ze een hernieuwing moeten krijgen.
     * @param type : string, type van het vaccin.
     * @param aantalPersonen : int, aantal personen die een hernieuwing moeten krijgen.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setGebruikteVaccins");
     * REQUIRE((aantalPersonen >= 0), "Aantal personen moet groter of gelijk zijn aan 0.");
     * REQUIRE((dagHernieuwing > 0), "De dag van een hernieuwing moet positief zijn");
     * ENSURE((getGebruikteVaccins(dagHernieuwing, type) == aantalPersonen), "setGebruikteVaccins postcondtion failure");
     */
    void setGebruikteVaccins(int dagHernieuwing, string &type, int aantalPersonen);

    /*
     * @functie: setLadingen
     * Deze functie geeft de ladingen terug van het vaccinatiecent
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setLadingen");
     * REQUIRE((ladingen >= 0), "Aantal ladingen moet positief zijn");
     * ENSURE((getLadingen() == ladingen), "setLadingen postcondtion failure");
     */
    void setLadingen(int ladingen);

    /*
     * @functie: setNewMapGebruikteVaccins
     * Deze functie vervangt de map fGebruikteVaccins, wanneer er niet genoeg vaccins zijn bij de hernieuwing
     * @param newGebruikteVaccins
     */
    void setNewMapGebruikteVaccins(map<pair<int, string>, int> &newGebruikteVaccins);

    /*
     * @functie: getNaam
     * Deze functie geeft de fNaam van het vaccinatiecentrum.
     * @return: string, de fNaam van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getNaam");
     */
    string getNaam();

    /*
     * @functie: getAdres
     * Deze functie geeft het fAdres van het vaccinatiecentrum.
     * @return: string, het fAdres van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getAdres");
     */
    string getAdres();

    /*
     * @functie: getInwoners
     * Deze functie geeft het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @return: int, inwoners in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getInwoners");
     */
    int getInwoners();

    /*
     * @functie: getCapaciteit
     * Deze functie geeft de fCapaciteit voor het opslagen van de vaccinatie van een vaccinatiecetrum.
     * @return: int, de fCapaciteit van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getCapaciteit");
     */
    int getCapaciteit();

    /*
     * @functie: getVaccins
     * Deze functie geeft het huidige aantal fVaccinsInCentrum in bezit.
     * @param type : type van het vaccins.
     * @return: int, huidig aantal fVaccinsInCentrum in het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccins");
     */
    int getVaccins(string &type);

    /*
     * @functie: getVaccinatedFirstTime
     * Deze functie geeft hoeveel mensen er al gevaccineerd zijn.
     * @return: int, aantal personen die al gevaccineerd zijn.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinatedFirstTime");
     */
    int getVaccinatedFirstTime();

    /*
     * @functie: getVaccinatedSecondTime
     * Deze functie geeft hoeveel mensen er al gevaccineerd zijn.
     * @return: int, aantal personen die al gevaccineerd zijn.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinatedFirstTime");
     */
    int getVaccinatedSecondTime();

    /*
     * @functie: getGebruikteVaccins
     * Geeft het aantal personen terug die een hernieuwing moeten krijgen op de gegeven dag en type vaccin
     * @param dagHernieuwing : int, dag dat ze een hernieuwing moeten krijgen.
     * @param type : string, type van het vaccin.
     * @return int, aantal personen die een hernieuwing moeten krijgen
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getGebruikteVaccins");
     */
    int getGebruikteVaccins(int dagHernieuwing, string &type);


    /*
     * @functie: getVaccinsInCentrum
     * Geeft het aantal vaccins in een centrum terug.
     * @return map<string, int>, aantal vaccins in centrum
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinsInCentrum");
     */
    map<string, int> getVaccinsInCentrum();

    /*
     * @functie: getLadingen
     * Geeft het aantal ladingen in een centrum terug.
     * @return : int, aantal ladingen in centrum
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getLadingen");
     */
    int getLadingen();

//    void isAdresGeldig(string &Cadres);
    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
