#include "rev_comp_pol3_allocate.hpp"
#include <cmath>

rev_comp_pol3_allocate::rev_comp_pol3_allocate()
{
}

std::string rev_comp_pol3_allocate::run(std::string ori)
{
    std::string rev_comp(ori.length(), 'A');
    for(unsigned int i = 0; i != ori.length(); i++)
    {
	rev_comp[ori.length() - i - 1] = this->char2char(ori[i]);
    }

    return rev_comp;
}

char rev_comp_pol3_allocate::char2char(char base)
{  
    return (((-0.045625*base + 10.1787)*base) - 753.8)*base + 18606; 
    //return (((-0.0456259*base + 10.178733)*base) - 753.80732)*base + 18606.353;
    //This is the complete formule but with upper same result and save time thank truncation
}

