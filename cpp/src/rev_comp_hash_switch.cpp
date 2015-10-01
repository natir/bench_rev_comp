#include "rev_comp_hash_switch.hpp"

rev_comp_hash_switch::rev_comp_hash_switch()
{
    hash['A'] = 'T';
    hash['T'] = 'A';
    hash['C'] = 'G';
    hash['G'] = 'C';
}

std::string rev_comp_hash_switch::run(std::string ori)
{

    for(long unsigned int begin = 0, end = ori.length() - 1; begin <= end; begin++, end--)
    {
	this->tmp = hash[ori[begin]];
	ori[begin] = hash[ori[end]];
	ori[end] = this->tmp;
    }

    return ori;
}
