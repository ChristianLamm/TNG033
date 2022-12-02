/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>



// ADD implementation of the member functions for class Polynomial


Polynomial::Polynomial(const std::vector<double>& arg) : coeff{ arg } {}

Polynomial::Polynomial( double d) {

	coeff.push_back(d);

}

Polynomial::Polynomial(Polynomial& arg) {

	coeff = arg.coeff;
	
}

void Polynomial::display(std::ostream&) const{}
double Polynomial::operator()(double x) const {
	return 0;
}
Expression* Polynomial::clone() const{}

Polynomial Polynomial::operator+=(const Polynomial& arg) {

	return *this;
}

double Polynomial::operator()(double d) const {}
double& Polynomial::operator[](int arg){}
double Polynomial::operator[](int arg) const{}

