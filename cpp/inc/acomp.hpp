#ifndef _HG_ACOMP_HPP_HG_
#define _HG_ACOMP_HPP_HG_

class acomp
{

public:

    acomp();
    virtual ~acomp();
    
    virtual char operator()(char nuc) = 0;
};

#endif /* _HG_ACOMP_HPP_HG_ */










