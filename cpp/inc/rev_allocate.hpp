#ifndef _HG_REV_ALLOCATE_HPP_HG_
#define _HG_REV_ALLOCATE_HPP_HG_

/* project include */
#include "arev.hpp"

class rev_allocate : public arev
{

public:
    rev_allocate();
    virtual ~rev_allocate();
    
    std::string operator()(std::string seq, const std::unique_ptr<acomp>& comp);
};

#endif /*_HG_REV_ALLOCATE_HPP_HG_*/







