/*********************************************************
 * Class Polynomial member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "polynomial.h"
#include <vector>
#include <cmath>
#include <iomanip>
#include "expression.h"


// ADD implementation of the member functions for class Polynomial


Polynomial::Polynomial(const std::vector<double>& arg) : coeff{ arg } {}

Polynomial::Polynomial( double d) {

	coeff.push_back(d);

}


void Polynomial::display(std::ostream& os) const{

	for (std::size_t i = 0; i < coeff.size(); i++)
	{
		if (i == 0) {
			os << std::fixed << std::setprecision(2) << coeff[i];
		}
		else if (coeff[i] < 0)
		{
			os << std::fixed << std::setprecision(2) << 
				" - " << abs(coeff[i]) << " * X^" << i;
		}
		else {
			os << std::fixed << std::setprecision(2) << " + " << abs(coeff[i]) << " * X^" << i;
		}
	}

}

Polynomial* Polynomial::clone() const
{
	return new Polynomial(*this);
}


double Polynomial::operator()(double x) const {
	
	double sum{ 0 };

	for (std::size_t i = 0; i < coeff.size(); i++) {

		if (i == 0)
		{
			sum += coeff[i];
		}
		else sum += coeff[i] * (pow(x, i));
	}
	
	return sum;
}

//Polynomial* Polynomial::clone() const {
//	return new Polynomial(*this);
//}

Polynomial Polynomial::operator+=(const Polynomial& arg) {

	for (std::size_t i = 0; i < arg.coeff.size(); i++)
	{
		if (i >= coeff.size()) {
			coeff.push_back(arg.coeff[i]);
		}
		else coeff[i] += arg.coeff[i];
	}

	return *this;
}


double& Polynomial::operator[](int arg){

	return coeff[arg];
}

double Polynomial::operator[](int arg) const{

	return coeff[arg];
}

