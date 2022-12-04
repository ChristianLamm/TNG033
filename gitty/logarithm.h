/*************************
 * Class Logarithm        *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "expression.h"

class Logarithm : public Expression {
   
public:
	Logarithm();
	Logarithm(const Expression& E, double c1, double c2, int b);
	Logarithm(const Logarithm& log); // copy constr.



	Logarithm& set_base(int x, Logarithm& log); // change base of a logarithm
	//or
	Logarithm& set_base(int x);

	Logarithm& operator=(const Logarithm log);

	Logarithm* clone() const override;

	double operator()(double y) const override;

protected:
	Expression* E;
	int b;
	double c1, c2;

	void display(std::ostream& os) const override;

};
