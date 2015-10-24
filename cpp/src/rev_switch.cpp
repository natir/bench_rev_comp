/* project include */
#include "rev_switch.hpp"

rev_switch::rev_switch()
{
    /* do nothing */
}

rev_switch::~rev_switch()
{
    /* do nothing */
}

std::string rev_switch::operator()(std::string seq, const std::unique_ptr<acomp>& comp)
{
    for(long unsigned int begin = 0, end = seq.length() - 1; begin <= end; begin++, end--)
    {
	this->tmp = (*comp)(seq[begin]);
	seq[begin] = (*comp)(seq[end]);
	seq[end] = this->tmp;
    }

    return seq;
}
