#ifndef _HG_COMP_NAIF_HPP_HG_
#define _HG_COMP_NAIF_HPP_HG_

/* project import */
#include "acomp.hpp"

class comp_naif : public acomp
{

public:

    comp_naif();
    virtual ~comp_naif();
    
    virtual char operator()(char nuc);
};

#endif /* _HG_COMP_NAIF_HPP_HG_ */
