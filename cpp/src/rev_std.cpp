/*standard include*/
#include <algorithm>
#include <iostream>

/* project include */
#include "rev_std.hpp"


rev_std::rev_std()
{
    /* do nothing */
}

rev_std::~rev_std()
{
    /* do nothing */
}

std::string rev_std::operator()(std::string seq, const std::unique_ptr<acomp>& comp)
{
    auto first = seq.begin(), last = seq.end();

    while(true)
	if(first == last || first == --last)
	{
	    if(seq.length() % 2)
		*first = (*comp)(*first);
	    return seq;
	}
	else
	{
	    *first = (*comp)(*first);
	    *last = (*comp)(*last);
	    std::iter_swap(first, last);
	    ++first;
	}
}
