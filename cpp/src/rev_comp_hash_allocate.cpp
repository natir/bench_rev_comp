#include "rev_comp_hash_allocate.hpp"

rev_comp_hash_allocate::rev_comp_hash_allocate()
{
    hash['A'] = 'T';
    hash['T'] = 'A';
    hash['C'] = 'G';
    hash['G'] = 'C';
}

std::string rev_comp_hash_allocate::run(std::string ori)
{
    std::string rev_comp(ori.length(), 'A');
    for(unsigned int i = 0; i != ori.length(); i++)
    {
	rev_comp[ori.length() - i - 1] = this->hash[ori[i]];
    }

    return rev_comp;
}
