/* project include */
#include "comp_pol3.hpp"

comp_pol3::comp_pol3()
{
    /* do nothing */
}

comp_pol3::~comp_pol3()
{
    /* do nothing */
}

char comp_pol3::operator()(char nuc)
{
    return (((-0.045625 * nuc + 10.1787) * nuc) - 753.8) * nuc + 18606; 
    //return (((-0.0456259*base + 10.178733)*base) - 753.80732)*base + 18606.353;
    //This is the complete formule but with upper same result and save time thank truncation
}
