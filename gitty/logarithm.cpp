/*********************************************************
 * Class Logarithm member functions implementation        *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <iomanip>
#include "expression.h"


// ADD implementation of the member functions for class Logarithm
Logarithm::Logarithm() {

	double c1 = 0.0; double c2 = 1.0; int b = 2;
	std::vector<double> coeff(0, 1);
	E = new Polynomial(coeff);
}


Logarithm::Logarithm(const Expression& arg1, double arg2, double arg3, int arg4) {

	E = arg1.clone();
	c1 = arg2; c2 = arg3; b = arg4;

}

Logarithm::Logarithm(const Logarithm& log) {

	c1 = log.c1, c2 = log.c2, b = log.b;
	E = log.E->clone();

}

Logarithm& Logarithm::operator=(const Logarithm log) {

	c1 = log.c1, c2 = log.c2, b = log.b;
	delete E;
	E = log.E->clone();

	return *this;

}

Logarithm* Logarithm::clone() const {
	return new Logarithm(*this);
}

void Logarithm::display(std::ostream& os) const {

	std::string s = " + ";
	if (c2 < 0) {
		s = " - ";
	}

	os << std::fixed << std::setprecision(2) << c1 << s << abs(c2) /*...*/
		<< " * Log_" << abs(b) << "( " << *E << " )";
}

Logarithm& Logarithm::set_base(int x, Logarithm& log) {

	log.b = x;

	return log;

}

//or

Logarithm& Logarithm::set_base(int x) {

	b = x;

	return *this;

}

double Logarithm::operator()(double y) const {

	double sum{ 0 };
	double e = E->operator()(y);

	sum += c1 + (c2 * (log(e) / log(b)));

	return sum;

}