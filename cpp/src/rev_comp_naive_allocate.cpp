#include "rev_comp_naive_allocate.hpp"

rev_comp_naive_allocate::rev_comp_naive_allocate()
{

}

std::string rev_comp_naive_allocate::run(std::string ori)
{
    std::string rev_comp(ori.length(), 'A');
    for(unsigned int i = 0; i != ori.length(); i++)
    {
	if(ori[i] == 'A')
	    rev_comp[ori.length() - i - 1] = 'T';
	else if(ori[i] == 'C')
	    rev_comp[ori.length() - i - 1] = 'G';
	else if(ori[i] == 'T')
	    rev_comp[ori.length() - i - 1] = 'A';
	else
	    rev_comp[ori.length() - i - 1] = 'C';
    }

    return rev_comp;
}
