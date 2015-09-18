#include "rev_comp_naive.hpp"

rev_comp_naive::rev_comp_naive()
{

}

std::string rev_comp_naive::run(std::string ori)
{
    std::string rev_comp;
    for(const char i : ori)
    {
	if(i == 'A')
	    rev_comp = 'T' + rev_comp;
	else if(i == 'C')
	    rev_comp = 'G' + rev_comp;
	else if(i == 'T')
	    rev_comp = 'A' + rev_comp;
	else
	    rev_comp = 'C' + rev_comp;
    }

    return rev_comp;
}
