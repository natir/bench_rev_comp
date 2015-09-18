#include "rev_comp_tab.hpp"

rev_comp_tab::rev_comp_tab()
{
    hash['A'] = 'T';
    hash['T'] = 'A';
    hash['C'] = 'G';
    hash['G'] = 'C';
}

std::string rev_comp_tab::run(std::string ori)
{
    std::string rev_comp;
    for(const char i : ori)
    {
	rev_comp = this->hash[i] + rev_comp;
    }

    return rev_comp;
}










