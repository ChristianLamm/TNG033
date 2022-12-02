/*************************
 * Class Expression       *
 * TNG033: Lab 2          *
 **************************/

#pragma once

#include <iostream>


class Expression {
public:
    // Destructor
    virtual ~Expression() {
        --count_expressions;
    }

    // ADD OTHER MEMBER FUNCTIONS

    bool isRoot(double x) const; 

    double Epsilon = 1.0e-5;

    virtual double operator()(double x) const; 
    virtual Expression* clone() const = 0;
    // Return number of existing instances of class Expression
    // Used only for debug purposes
    static std::size_t get_count_expressions();

    friend std::ostream& operator<<(std::ostream& e, const Expression&);

protected:
    // Default constructor
    Expression() {
        ++count_expressions;
    }

    // Copy constructor
    Expression(const Expression&) {
        ++count_expressions;
    }

    // Total number of existing expressions -- to help to detect bugs in the code
    static std::size_t count_expressions;

    virtual void display(std::ostream&) const = 0;

    Expression& operator=(const Expression& e) = default;
};
