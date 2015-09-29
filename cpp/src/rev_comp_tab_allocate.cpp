#include "rev_comp_tab_allocate.hpp"

rev_comp_tab_allocate::rev_comp_tab_allocate()
{
    tab['A'] = 'T';
    tab['T'] = 'A';
    tab['C'] = 'G';
    tab['G'] = 'C';
}

std::string rev_comp_tab_allocate::run(std::string ori)
{
    std::string rev_comp(ori.length(), 'A');
    for(unsigned int i = 0; i != ori.length(); i++)
    {
	rev_comp[ori.length() - i - 1] = this->tab[ori[i]];
    }

    return rev_comp;
}










