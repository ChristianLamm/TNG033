/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {
   
 public:
    Polynomial(const std::vector<double>& arg);

    Polynomial(double d);

    Polynomial(Polynomial& arg);

    Polynomial& operator=(const Polynomial& arg) = default;

    ~Polynomial() = default;

    Polynomial operator+=(const Polynomial& arg);

    friend Polynomial operator+(Polynomial arg1, Polynomial& arg2) {
        return (arg1 += arg2);// use add-assign op.
    }

    double operator()(double d) const override;
    double& operator[](int arg);
    double operator[](int arg) const;


private:

    std::vector<double> coeff;

    void display(std::ostream&) const;
    
    double operator()(double x) const;

    Expression* clone() const;
    
};

