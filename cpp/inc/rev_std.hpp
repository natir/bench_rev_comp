#ifndef _HG_REV_STD_HPP_HG_
#define _HG_REV_STD_HPP_HG_

/* project include */
#include "arev.hpp"


class rev_std : public arev
{

public:

    rev_std();
    virtual ~rev_std();

    std::string operator()(std::string seq, const std::unique_ptr<acomp>& comp);

private:

    char tmp;
};

#endif /*_HG_REV_STD_HPP_HG_*/
