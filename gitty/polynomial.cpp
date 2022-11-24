/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>

// ADD implementation of the member functions for class Polynomial


Polynomial::Polynomial(const std::vector<double>& arg) {
		
	coeff = arg;
		

}

Polynomial::Polynomial(double d) {

	coeff.push_back(d);

}

Polynomial::Polynomial(Polynomial& arg) {

	coeff = arg.coeff;
	
}

