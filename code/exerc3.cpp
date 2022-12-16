/*********************************************
 * Lab 3: exercise 3                         *
 * Program to compute an approximation of PI *
 * STL-algorithms should be used             *
 *********************************************/

#include <iostream>
#include <cmath>
#include <format>
#include <vector>
#include <algorithm>
#include <numeric>

double calculate(double k) {
    double const factor{ 8.0 * k };
    double const init{ 4.0 / (factor + 1.0) - 1.0 / (factor + 4.0) };

    std::vector<double> other_factors{ 4.0, 5.0, 6.0 };

    std::transform(other_factors.begin(), other_factors.end(),
        other_factors.begin(), [&factor](double d) { return -1.0 / (d + factor); }); //ers�tter forloop

    double result{ init };
    result = std::accumulate(other_factors.begin(), other_factors.end(), init);  //

    return result;
}

int main() {
    std::cout << "Enter number of terms: ";
    int n;
    std::cin >> n;

    std::vector<double> terms(n);

    std::iota(terms.begin(), terms.end(), 0); //push_back funktion f�r stl


    std::vector<double> power_terms{ terms };

    std::transform(terms.begin(), terms.end(), terms.begin(), calculate); //g�r igenom varje element och applicerar calc

    std::transform(power_terms.begin(), power_terms.end(), //sammma sak fast med andra parentesen
        power_terms.begin(), [](int i) { return std::pow(16.0, -i); }); //nu har vi tv� vektorer att ber�kna

    double result{ 0.0 };
    result = std::inner_product(terms.begin(), terms.end(), power_terms.begin(), 0.0); //ber�knar skal�rprodukten mellan
                                                                                       //power_terms och terms

    std::cout << std::format("{:.15f}\n", result);
}