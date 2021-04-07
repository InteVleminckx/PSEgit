//
// Created by inte on 20.03.21.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_VACCIN_H
#define PROJECT_SOFTWARE_ENGENEERING_VACCIN_H

#include "TinyXML/tinyxml.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>  // Required for stringstreams
#include "DesignByContract.h"

using namespace std;

class Vaccin {

    Vaccin* _initCheck;

    string fType;
    int fLeveringen;
    int fInterval;
    int fTransport;
    int fHernieuwingen;
    int fTemperatuur;

public:

    Vaccin(string &Type, int Leveringen, int Interval, int Transport, int Hernieuwingen, int Temperatuur);

    /*
     * @functie: getType
     * Deze functie geeft het type van het vaccin.
     * @return: string, het type van het vaccin.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getType");
     */
    string getType();

    /*
     * @functie: getLeveringen
     * Deze functie geeft het aantal leveringen van het vaccin.
     * @return: int, het aantal leveringen.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getLeveringen");
     */
    int getLeveringen();

    /*
     * @functie: getInterval
     * Deze functie geeft het leveringen interval van het vaccin aan een hub.
     * @return: int, de intervalwaarde.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getInterval");
     */
    int getInterval();

    /*
     * @functie: getTransport
     * Deze functie geeft de hoeveelheid transport van het vaccin.
     * @return: int, de transportwaarde.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getTransport");
     */
    int getTransport();

    /*
     * @functie: getHernieuwingen
     * Deze functie geeft aan na hoeveel dagen een 2de vaccin moeten krijgen.
     * @return: int, het interval waarop de vaccins opnieuw moeten toegediend worden.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getHernieuwingen");
     */
    int getHernieuwingen();

    /*
     * @functie: getTemperatuur
     * Deze functie geeft de temperatuur van het vaccin waarop hij bewaard moet worden.
     * @return: int, geeft de temperatuur waarin het vaccin bewaard moet worden.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getTemperatuur");
     */
    int getTemperatuur();

    /*
     * @functie: getAantalVaccins
     * Deze functie geeft het aantal vaccins die van dit type in de hub bevinden terug.
     * @return: int, het geeft aantal vaccins die van dit type in de hub bevinden terug.
     * REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getAantalVaccins");
     */
    int getAantalVaccins();

    bool properlyInitialized();


};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCIN_H
