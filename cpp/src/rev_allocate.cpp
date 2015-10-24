/* project include */
#include "rev_allocate.hpp"

rev_allocate::rev_allocate()
{
    /* do nothing */
}

rev_allocate::~rev_allocate()
{
    /* do nothing */
}

std::string rev_allocate::operator()(std::string seq, const std::unique_ptr<acomp>& comp)
{
    std::string rev_comp(seq.length(), 'A');

    for(unsigned int i = 0; i != seq.length(); i++)
    {
	rev_comp[seq.length() - i - 1] = (*comp)(seq[i]);
    }

    return rev_comp;
}
