#ifndef _HG_REV_COMP_POL3_ALLOCATE_HPP_HG_
#define _HG_REV_COMP_POL3_ALLOCATE_HPP_HG_

#include "arev_comp.hpp"

class rev_comp_pol3_allocate : public arev_comp
{
public:
    rev_comp_pol3_allocate();

    std::string run(std::string ori);

private:

    char char2char(char base);
};

#endif /* _HG_REV_COMP_TAB_HPP_HG_ */

