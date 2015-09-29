#ifndef _HG_REV_COMP_TAB_HPP_HG_
#define _HG_REV_COMP_TAB_HPP_HG_

#include "arev_comp.hpp"

class rev_comp_tab : public arev_comp
{
public:
    rev_comp_tab();

    std::string run(std::string ori);

private:
    char tab[85];
};

#endif /* _HG_REV_COMP_TAB_HPP_HG_ */










