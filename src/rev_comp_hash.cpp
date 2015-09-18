#include "rev_comp_hash.hpp"

rev_comp_hash::rev_comp_hash()
{
    hash['A'] = 'T';
    hash['T'] = 'A';
    hash['C'] = 'G';
    hash['G'] = 'C';
}

std::string rev_comp_hash::run(std::string ori)
{
    std::string rev_comp;
    for(const char i : ori)
    {
	rev_comp = this->hash[i] + rev_comp;
    }

    return rev_comp;
}
