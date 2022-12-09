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

    Polynomial(double d); //conversion constructor

    Polynomial(const Polynomial& ) = default; // copy const.

    Polynomial& operator=(const Polynomial&) = default;

    ~Polynomial() = default;

    Polynomial* clone() const override;

    Polynomial operator+=(const Polynomial& arg);


    // 
    friend Polynomial operator+(Polynomial arg1, const Polynomial& arg2) {
        return (arg1 += arg2);// use add-assign op.
    }

    double operator()(double x) const override;
    
    double& operator[]( int arg);
    double operator[](int arg) const; // we should not be able to change const Polynom 


private:

    std::vector<double> coeff;

    void display(std::ostream& os) const override;
   

   // Expression* clone() const;
    
};

