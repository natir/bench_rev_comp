#include "rev_comp_tab_switch.hpp"

rev_comp_tab_switch::rev_comp_tab_switch()
{
    tab['A'] = 'T';
    tab['T'] = 'A';
    tab['C'] = 'G';
    tab['G'] = 'C';
}

std::string rev_comp_tab_switch::run(std::string ori)
{

    for(long unsigned int begin = 0, end = ori.length() - 1; begin <= end; begin++, end--)
    {
	this->tmp = this->tab[ori[begin]];
	ori[begin] = this->tab[ori[end]];
	ori[end] = this->tmp;
    }

    return ori;
}










