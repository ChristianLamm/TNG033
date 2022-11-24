/*************************
 * Class Polynomial       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>
#include <vector>
#include "expression.h"

class Polynomial : public Expression {
   
    Polynomial(const std::vector<double>& arg);

    Polynomial(const double d);

    Polynomial(Polynomial& arg);

private:
    std::vector<double> coeff;

    
    
};

