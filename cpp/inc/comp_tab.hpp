#ifndef _HG_COMP_TAB_HPP_HG_
#define _HG_COMP_TAB_HPP_HG_

/* project import */
#include "acomp.hpp"

class comp_tab : public acomp
{

public:

    comp_tab();
    virtual ~comp_tab();
    
    virtual char operator()(char nuc);

private:

    char tab['T'+1]; // tab begin with index 0
};

#endif /* _HG_COMP_TAB_HPP_HG_ */










