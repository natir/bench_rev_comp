/* project include */
#include "comp_hash.hpp"

comp_hash::comp_hash() : hash()
{
    this->hash['A'] = 'T';
    this->hash['T'] = 'A';
    this->hash['C'] = 'G';
    this->hash['G'] = 'C';
}

comp_hash::~comp_hash()
{
    /* do nothing */
}

char comp_hash::operator()(char nuc)
{
    return this->hash[nuc];
}
