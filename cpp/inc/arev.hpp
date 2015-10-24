#ifndef _HG_AREV_HPP_HG_
#define _HG_AREV_HPP_HG_

/* standard include */
#include <string>
#include <memory>

/* project include */
#include "acomp.hpp"

class arev
{

public:
    
    arev();
    virtual ~arev();

    virtual std::string operator()(std::string seq, const std::unique_ptr<acomp>& comp) = 0;
};

#endif /*_HG_AREV_HPP_HG_*/
