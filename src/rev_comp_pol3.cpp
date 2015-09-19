#include "rev_comp_pol3.hpp"
#include <cmath>

rev_comp_pol3::rev_comp_pol3()
{
}

std::string rev_comp_pol3::run(std::string ori)
{
    std::string rev_comp;
    for(const char i : ori)
    {
	rev_comp = this->char2char(i) + rev_comp;
    }

    return rev_comp;
}

char rev_comp_pol3::char2char(char base)
{
    return (((-0.0456259*base + 10.178733)*base) - 753.80732)*base + 18606.353;
    //return 18606.353 - 753.80732*base + 10.178733*base*base - 0.0456259*base*base*base;
}



















