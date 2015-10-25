#ifndef _HG_REV_NAIF_HPP_HG_
#define _HG_REV_NAIF_HPP_HG_

/* project include */
#include "arev.hpp"

class rev_naif : public arev
{

public:
    
    rev_naif();
    virtual ~rev_naif();
    
    std::string operator()(std::string seq, const std::unique_ptr<acomp>& comp);
};

#endif /*_HG_REV_NAIF_HPP_HG_*/

















