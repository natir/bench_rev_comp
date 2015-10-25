#ifndef _HG_REV_SWITCH_HPP_HG_
#define _HG_REV_SWITCH_HPP_HG_

/* project include */
#include "arev.hpp"


class rev_switch : public arev
{

public:

    rev_switch();
    virtual ~rev_switch();

    std::string operator()(std::string seq, const std::unique_ptr<acomp>& comp);
    
private:

    char tmp;
    
};

#endif /*_HG_REV_SWITCH_HPP_HG_*/
