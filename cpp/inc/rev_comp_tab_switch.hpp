#ifndef _HG_REV_COMP_TAB_SWITCH_HPP_HG_
#define _HG_REV_COMP_TAB_SWITCH_HPP_HG_

#include "arev_comp.hpp"

class rev_comp_tab_switch : public arev_comp
{
public:
    rev_comp_tab_switch();

    std::string run(std::string ori);

private:
    
    char tab[85];
    char tmp;
};

#endif /* _HG_REV_COMP_TAB_HPP_HG_ */












