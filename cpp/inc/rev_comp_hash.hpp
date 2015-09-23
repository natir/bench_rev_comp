#ifndef _HG_REV_COMP_HASH_HPP_HG_
#define _HG_REV_COMP_HASH_HPP_HG_

#include <map>

#include "arev_comp.hpp"

class rev_comp_hash : public arev_comp
{
public:
    rev_comp_hash();
    
    std::string run(std::string ori);

private:
    std::map<char, char> hash;
};

#endif /* _HG_REV_COMP_HASH_HPP_HG_ */
