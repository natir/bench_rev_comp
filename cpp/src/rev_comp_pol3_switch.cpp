#include "rev_comp_pol3_switch.hpp"
#include <cmath>

rev_comp_pol3_switch::rev_comp_pol3_switch()
{
}

std::string rev_comp_pol3_switch::run(std::string ori)
{
    for(long unsigned int begin = 0, end = ori.length() - 1; begin <= end; begin++, end--)
    {
	this->tmp = char2char(ori[begin]);
	ori[begin] = char2char(ori[end]);
	ori[end] = this->tmp;
    }

    return ori;
}

char rev_comp_pol3_switch::char2char(char base)
{  
    return (((-0.045625*base + 10.1787)*base) - 753.8)*base + 18606; 
    //return (((-0.0456259*base + 10.178733)*base) - 753.80732)*base + 18606.353;
    //This is the complete formule but with upper same result and save time thank truncation
}

