/*********************************************************
 * Class Expression member functions implementation       *
 * TNG033: Lab 2                                          *
 **********************************************************/

#include "expression.h"
#include <cmath>;

// Initialize the counter of the total number of existing Expressions
std::size_t Expression::count_expressions = 0;
 





// Used only for debug purposes
// Return number of existing Expressions
std::size_t Expression::get_count_expressions() {
    return Expression::count_expressions;
}



/* ************************* */

bool Expression::isRoot(double x) const {

	constexpr double Epsilon = 1.0e-5;
	if (std::abs(this->operator()(x)) < Epsilon) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& d, const Expression& E) {
	E.display(d);  // dynamic binding occurs
	return d;
}
