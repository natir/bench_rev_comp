#ifndef _HG_REV_COMP_REGEX_HPP_HG_
#define _HG_REV_COMP_REGEX_HPP_HG_

#include <regex>

#include "arev_comp.hpp"

class rev_comp_regex : public arev_comp
{
public:
    rev_comp_regex();
    
    std::string run(const std::string& ori);

private:
    std::regex nuc2nuc;
};

#endif /* _HG_REV_COMP_REGEX_HPP_HG_ */
