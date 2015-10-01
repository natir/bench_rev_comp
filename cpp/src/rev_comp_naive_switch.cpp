#include "rev_comp_naive_switch.hpp"

rev_comp_naive_switch::rev_comp_naive_switch()
{

}

std::string rev_comp_naive_switch::run(std::string ori)
{
    for(long unsigned int begin = 0, end = ori.length() - 1; begin <= end; begin++, end--)
    {
	this->tmp = char2char(ori[begin]);
	ori[begin] = char2char(ori[end]);
	ori[end] = this->tmp;
    }

    return ori;
}

char rev_comp_naive_switch::char2char(char c)
{
    if(c == 'A')
	return 'T';
    else if(c == 'C')
	return 'G';
    else if(c == 'T')
	return 'A';
    else
	return 'C';
}
