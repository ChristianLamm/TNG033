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
	Logarithm(const Expression& arg1, double arg2, double arg3, int arg4);
	Logarithm(const Logarithm& log); // copy constr.



	Logarithm& set_base(int x, Logarithm& log); // change base of a logarithm
	//or
	Logarithm& set_base(int x);

	Logarithm& operator=(const Logarithm& log);

	~Logarithm();

	Logarithm* clone() const override;

	double operator()(double y) const override;

protected:
	Expression* E;
	int b;
	double c1, c2;

	void display(std::ostream& os) const override;

};
