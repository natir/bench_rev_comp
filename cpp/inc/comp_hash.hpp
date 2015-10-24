#ifndef _HG_COMP_HASH_HPP_HG_
#define _HG_COMP_HASH_HPP_HG_

/* standard include */
#include <map>

/* project import */
#include "acomp.hpp"

class comp_hash : public acomp
{

public:

    comp_hash();
    virtual ~comp_hash();

    virtual char operator()(char nuc);

private:

    std::map<char, char> hash;
};

#endif /* _HG_COMP_HASH_HPP_HG_ */
