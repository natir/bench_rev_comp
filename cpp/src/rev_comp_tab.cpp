#include "rev_comp_tab.hpp"

rev_comp_tab::rev_comp_tab()
{
    tab['A'] = 'T';
    tab['T'] = 'A';
    tab['C'] = 'G';
    tab['G'] = 'C';
}

std::string rev_comp_tab::run(std::string ori)
{
    std::string rev_comp;
    for(const char i : ori)
    {
	rev_comp = this->tab[i] + rev_comp;
    }

    return rev_comp;
}










