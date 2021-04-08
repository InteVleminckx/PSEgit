/*
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/Transport.h"
#include "../Header_files/FileParser.h"

Transport::Transport(FileParser &file) {
    fLeveringInterval = file.fInterval;
    fAantalVaccins = 0;
    _initCheck = this;
    transportSimulatie(file);

}

void Transport::transportSimulatie(FileParser &file) {

    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling transportSimulatie");
    int day = 0;

    //aanmaken uitvoer bestand
    ofstream OT;

    //openen van het uitvoerbestand
    OT.open("../simulatieOutput/overzichtTransport.txt");
    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");

//    while (!isAllPeopleVaccinated(file)){
        //check allVaccinated

        //als fInterval om is, nieuwe levering in de hub
        if (day % (fLeveringInterval + 1) == 0) {
            fAantalVaccins += file.fLeveringen;
//            cout << "week: " << day/7 << endl;
        }

        for (unsigned int i = 0; i < file.fCentra.size(); i++){

            string centrumNaam = file.fCentra[i].getNaam();

            int vaccinsCentrum = file.fCentra[i].getVaccins(centrumNaam);
            int capaciteitCentrum = file.fCentra[i].getCapaciteit();

            double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;

            int ladingen = 0;
            bool foundLadingen = false;

            int tempVaccins = fAantalVaccins;

            for (int j = 0; j < (vaccins_transport_min + file.fTransport) / file.fTransport; ++j) {
                bool getLadingen = false;

                if ((tempVaccins - j*file.fTransport) > 0 ){ getLadingen = true;}

                if (j*file.fTransport + vaccinsCentrum >= capaciteitCentrum &&
                    2*capaciteitCentrum >= j*file.fTransport + vaccinsCentrum && !foundLadingen && getLadingen){
                    ladingen = j; foundLadingen = true;
                }

            }

            file.fCentra[i].setVaccins((ladingen * file.fTransport) + vaccinsCentrum, centrumNaam);

            fAantalVaccins -= ladingen * file.fTransport;

            OT << "Er werden " << ladingen << " ladingen (" << ladingen * file.fTransport <<
               " fVaccinsInCentrum) getransporteerd naar " << centrumNaam + ".\n";

//            vaccinatieInCentrum(file.fCentra[i]);

        }
        OT << "\n";
        day++;
    }
//    file.fHubVaccins = fAantalVaccins;
//}

void Transport::vaccinatieInCentrum(Vaccinatiecentrum &centrum) {

    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling vaccinatieInCentrum");

    string randomString;

    int vaccinsInCentrum = centrum.getVaccins(randomString);
    int capaciteit = centrum.getCapaciteit();
    int aantalOngevaccineerden = centrum.getInwoners() - centrum.getVaccinated();

    int inwonersGevaccineerd = min(vaccinsInCentrum, capaciteit);
    inwonersGevaccineerd = min(inwonersGevaccineerd, aantalOngevaccineerden);
    // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.

    centrum.setVaccinated(inwonersGevaccineerd + centrum.getVaccinated());
    centrum.setVaccins(centrum.getVaccins(randomString) - inwonersGevaccineerd, randomString);

    if (inwonersGevaccineerd != 0) {
        fOVP << "Er werden " << inwonersGevaccineerd << " inwoners gevaccineerd in " << centrum.getNaam() << ".\n";
    }
}

bool Transport::isAllPeopleVaccinated(FileParser &file) {
    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling isALlPeopleVaccinated");

    for (unsigned int i = 0; i < file.fCentra.size(); i++) {
        if (file.fCentra[i].getInwoners() != file.fCentra[i].getVaccinated()) {
            return false;
        }
    }
    return true;
}

bool Transport::properlyInitialized() {

    return _initCheck == this;
}

