#ifndef _HG_COMP_POL3_HPP_HG_
#define _HG_COMP_POL3_HPP_HG_

/* project import */
#include "acomp.hpp"

class comp_pol3 : public acomp
{

public:

    comp_pol3();
    virtual ~comp_pol3();

    virtual char operator()(char nuc);
};

#endif /* _HG_COMP_POL3_HPP_HG_ */
