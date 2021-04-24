/*
 * korte beschrijving:
 * Klasse (Hub), bevat het aantal vaccins in de hub zelf en de vaccinatiecentra waar de hub aan moet distribueren.
 * Houdt ook het aantal geleverde vaccins van elk type bij.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_HUB_H
#define PROJECT_SOFTWARE_ENGENEERING_HUB_H

#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>  // Required for stringstreams
#include "DesignByContract.h"
#include "Vaccin.h"
#include "Vaccinatiecentrum.h"
#include "../TinyXML/tinyxml.h"

using namespace std;

class Hub {
public:

    Hub* _initCheck;
//    int fAantalVaccins;
//    int fLeveringInterval;
//    ofstream fOVP; //overzichtVaccinatieProcedure

    vector<Vaccin*> fVaccins;

    vector<Vaccinatiecentrum*> fHubCentra;

    int VCcounter;

    /*
     * @functie: Hub
     * Constructor voor Hub.
     */
    Hub();

    /*
     * @functie : setAantalGeleverdeVaccins
     * Deze functie zet het aantal vaccins van een type per hub.
     * @param type : string, type van het vaccin
     * @param aantal : int, hoeveelheid vaccins die worden toegevoegd
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling setAantalGeleverdeVaccins");
     * REQUIRE(aantal > 0, "Het aantal geleverde vaccins moet groter zijn dan 0.");
     * ENSURE((getAantalGeleverdeVaccins(type) == aantal), "setVaccinatedFirstTime postcondition failure.");
     */
    void setAantalGeleverdeVaccins(string &type, int aantal);

    /*
     * @functie : getAantalGeleverdeVaccins
     * Deze functie geeft het aantal vaccins in de hub van een type terug.
     * @param type : string, type van het vaccin.
     * @return : int, aantal vaccins van het type in de hub.
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling getAantalGeleverdeVaccins");
     */
    int getAantalGeleverdeVaccins(string &type);

    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_HUB_H
