/*
 * korte beschrijving:
 * klasse (DesignByContract) laat ons toe om de REQUIRE en ENSURE functies te gebruiken, namelijk pre-en postcondities.
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H
#define PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H

#include <assert.h>

#define REQUIRE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)

#endif //PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H // niet nodig?
