/* project include */
#include "comp_tab.hpp"

comp_tab::comp_tab()
{
    this->tab['A'] = 'T';
    this->tab['T'] = 'A';
    this->tab['C'] = 'G';
    this->tab['G'] = 'C';
}

comp_tab::~comp_tab()
{
    /* do nothing */
}

char comp_tab::operator()(char nuc)
{
    return this->tab[nuc];
}










