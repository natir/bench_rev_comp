/* project include */
#include "rev_naif.hpp"

rev_naif::rev_naif()
{
    /* do nothing */
}

rev_naif::~rev_naif()
{
    /* do nothing */
}

std::string rev_naif::operator()(std::string seq, const std::unique_ptr<acomp>& comp)
{
    std::string rev_comp;
    for(char nuc : seq)
    {
	rev_comp = (*comp)(nuc) + rev_comp;
    }

    return rev_comp;
}



















