#ifndef _HG_REV_COMP_NAIVE_HPP_HG_
#define _HG_REV_COMP_NAIVE_HPP_HG_

#include <map>

#include "arev_comp.hpp"

class rev_comp_naive : public arev_comp
{
public:
    rev_comp_naive();
    
    std::string run(std::string ori);
};

#endif /* _HG_REV_COMP_NAIVE_HPP_HG_ */
