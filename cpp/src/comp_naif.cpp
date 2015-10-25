/* project include */
#include "comp_naif.hpp"

comp_naif::comp_naif()
{
    /* do nothing */
}

comp_naif::~comp_naif()
{
    /* do nothing */
}

char comp_naif::operator()(char nuc)
{
    if(nuc == 'A')
	return 'T';
    else if(nuc == 'C')
	return 'G';
    else if(nuc == 'T')
	return 'A';
    else
	return 'C';
}










