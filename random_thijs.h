#ifndef RANDOM_THIJS
#define RANDOM_THIJS

#include <boost/random.hpp>
#include <fstream>

int random_number(int n);
double uniform();
double normal(double m, double s);
double Gamma(int k, double lambda);
double Expon(double lambda);

void set_seed(unsigned seed);

std::ostream& storeState(std::ostream& os);
std::istream& readState(std::istream& is);

#endif 