#include "stdafx.h"
#include "random_thijs.h"


typedef boost::mt11213b rndeng;
rndeng rndgen;                      //< The one and only random number generator


int random_number(int n)
{
	return boost::uniform_int<int>(0,n-1)(rndgen);
}

double uniform()
{
	return boost::uniform_01<double>()(rndgen);
}

double normal(double m, double s)
{
	return boost::normal_distribution<double>(m, s)(rndgen);
}
/*
double Gamma(int k, double lambda)
{
	return boost::gamma_distribution<double>(k,lambda)(rndgen);
}*/

double Expon(double lambda)
{
	return boost::exponential_distribution<double>(lambda)(rndgen);
}

void set_seed(unsigned seed)
{
	rndgen.seed(rndeng::result_type(seed));
}

std::ostream& storeState(std::ostream& os)
{
  os << rndgen << '\n';
  return os;
}

std::istream& readState(std::istream& is)
{
  is >> rndgen;
  return is;
}
 