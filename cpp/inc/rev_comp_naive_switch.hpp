#ifndef _HG_REV_COMP_NAIVE_SWITCH_HPP_HG_
#define _HG_REV_COMP_NAIVE_SWITCH_HPP_HG_

#include <map>

#include "arev_comp.hpp"

class rev_comp_naive_switch : public arev_comp
{
public:
    rev_comp_naive_switch();
    
    std::string run(std::string ori);

private:

    char char2char(char c);

private:

    char tmp;
};

#endif /* _HG_REV_COMP_NAIVE_HPP_HG_ */





