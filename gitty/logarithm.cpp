/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <iomanip>


// ADD implementation of the member functions for class Logarithm
Logarithm::Logarithm() {

	double c1 = 0.0; double c2 = 1.0; int b = 2;
	std::vector<double> coeff(0, 1);
	E = new Polynomial(coeff);

}