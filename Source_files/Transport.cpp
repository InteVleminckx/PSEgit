/*
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/Transport.h"
#include "../Header_files/FileParser.h"

Transport::Transport(Hub* hub, Vaccinatiecentrum* centrum, ofstream &OT) {
    _initCheck = this;

//    //aanmaken uitvoer bestand
//    ofstream OT;
//
//    //openen van het uitvoerbestand
//    OT.open("../simulatieOutput/overzichtTransport.txt");
//    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");

    int teVaccineren = 0;

    for (unsigned int i = 0; i < hub->fVaccins.size(); ++i) {

        if (centrum->getVaccinated() == centrum->getInwoners()){
            break;
        }

        string centrumNaam = centrum->getNaam();
        string vaccinType = hub->fVaccins[i]->getType();
        int vaccinsCentrum = centrum->getVaccins(vaccinType);
        int capaciteitCentrum = centrum->getCapaciteit();
        double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;

        int ladingen = 0;
        bool foundLadingen = false;

        int tempVaccins = hub->fVaccins[i]->getAantalVaccins();

        for (int j = 0; j < (vaccins_transport_min + hub->fVaccins[i]->getTransport())/hub->fVaccins[i]->getTransport();
            ++j) {

            bool getLadingen = false;

            if ((tempVaccins - j*hub->fVaccins[i]->getTransport()) > 0 ){ getLadingen = true;}

            if (j*hub->fVaccins[i]->getTransport() + vaccinsCentrum >= capaciteitCentrum &&
                2*capaciteitCentrum >= j*hub->fVaccins[i]->getTransport() + vaccinsCentrum && !foundLadingen && getLadingen){
                ladingen = j; foundLadingen = true;
            }
        }
        centrum->setVaccins((ladingen * hub->fVaccins[i]->getTransport()) + vaccinsCentrum, vaccinType);

        hub->fVaccins[i]->setAantalVaccins(-(ladingen * hub->fVaccins[i]->getTransport()));

        OT << "Er werden " << ladingen << " ladingen (" << ladingen * hub->fVaccins[i]->getTransport() <<
       " vaccins) getransporteerd naar " << centrumNaam + ".\n";

        teVaccineren = vaccinatieInCentrum(centrum, vaccinType, teVaccineren);

        if (teVaccineren <= 0) {
            break;
        }

    }
    OT << "\n";
}

int Transport::vaccinatieInCentrum(Vaccinatiecentrum* centrum, string &vaccinType, int teVaccineren) {

    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling vaccinatieInCentrum");


    int vaccinsInCentrum = centrum->getVaccins(vaccinType);
    int capaciteit = centrum->getCapaciteit();
    int aantalOngevaccineerden = centrum->getInwoners() - centrum->getVaccinated();

    int inwonersGevaccineerd = min(vaccinsInCentrum, capaciteit);
    inwonersGevaccineerd = min(inwonersGevaccineerd, aantalOngevaccineerden);
    // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.

    if (teVaccineren == 0){
        teVaccineren = inwonersGevaccineerd;
    }

    if (teVaccineren < inwonersGevaccineerd){
        centrum->setVaccinated(teVaccineren + centrum->getVaccinated());
        centrum->setVaccins(centrum->getVaccins(vaccinType) - teVaccineren, vaccinType);
    }
    else{
        centrum->setVaccinated(inwonersGevaccineerd + centrum->getVaccinated());
        centrum->setVaccins(centrum->getVaccins(vaccinType) - inwonersGevaccineerd, vaccinType);
    }

//    if (inwonersGevaccineerd != 0) {
//        fOVP << "Er werden " << inwonersGevaccineerd << " inwoners gevaccineerd in " << centrum->getNaam() << ".\n";
//    }
    return capaciteit - inwonersGevaccineerd;
}

//bool Transport::isAllPeopleVaccinated(FileParser &file) {
//    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling isALlPeopleVaccinated");
//
//        for (unsigned int j = 0; j < file.fHubs.size(); j++) {
//            for (unsigned int i = 0; i < file.fHubs[j]->fHubCentra.size(); i++) {
//                if (file.fHubs[j]->fHubCentra[i]->getInwoners() != file.fHubs[j]->fHubCentra[i]->getVaccinated()) {
//                    return false;
//                }
//            }
//        }
//    return true;
//}

bool Transport::properlyInitialized() {

    return _initCheck == this;
}

//void Transport::transportSimulatie(FileParser &file) {
//
//    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling transportSimulatie");
//    int day = 0;
//
//    //aanmaken uitvoer bestand
//    ofstream OT;
//
//    //openen van het uitvoerbestand
//    OT.open("../simulatieOutput/overzichtTransport.txt");
//    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");
//
////    while (!isAllPeopleVaccinated(file)){
//        //check allVaccinated
//
//        //als fInterval om is, nieuwe levering in de hub
//        if (day % (fLeveringInterval + 1) == 0) {
//            fAantalVaccins += file.fLeveringen;
////            cout << "week: " << day/7 << endl;
//        }
//
//        for (unsigned int i = 0; i < file.fCentra.size(); i++){
//
//            string centrumNaam centrum->getNaam();
//
//            int vaccinsCentrum centrum->getVaccins(centrumNaam);
//            int capaciteitCentrum centrum->getCapaciteit();
//
//            double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;
//
//            int ladingen = 0;
//            bool foundLadingen = false;
//
//            int tempVaccins = fAantalVaccins;
//
//            for (int j = 0; j < (vaccins_transport_min + file.fTransport) / file.fTransport; ++j) {
//                bool getLadingen = false;
//
//                if ((tempVaccins - j*file.fTransport) > 0 ){ getLadingen = true;}
//
//                if (j*file.fTransport + vaccinsCentrum >= capaciteitCentrum &&
//                    2*capaciteitCentrum >= j*file.fTransport + vaccinsCentrum && !foundLadingen && getLadingen){
//                    ladingen = j; foundLadingen = true;
//                }
//
//            }
//            centrum->setVaccins((ladingen * file.fTransport) + vaccinsCentrum, centrumNaam);
//
//            fAantalVaccins -= ladingen * file.fTransport;
//
//            OT << "Er werden " << ladingen << " ladingen (" << ladingen * file.fTransport <<
//               " fVaccinsInCentrum) getransporteerd naar " << centrumNaam + ".\n";
//
////            vaccinatieInCentrum(file.fCentra[i]);
//
//        }
//        OT << "\n";
//        day++;
//    }
////    file.fHubVaccins = fAantalVaccins;
////}