/* std include */
#include <iostream>
#include <cassert>

/* project include */
#include "comp_naif.hpp"
#include "comp_pol3.hpp"
#include "comp_hash.hpp"
#include "comp_tab.hpp"

#include "rev_naif.hpp"
#include "rev_allocate.hpp"
#include "rev_switch.hpp"
#include "rev_std.hpp"

int main()
{
    std::string seq = "ACTG";
    std::string rev_comp = "CAGT";
    
    std::map<std::string, std::unique_ptr<acomp> > comp_list;
    comp_list.emplace("naif", std::make_unique<comp_naif>());
    comp_list.emplace("pol3", std::make_unique<comp_pol3>());
    comp_list.emplace("hash", std::make_unique<comp_hash>());
    comp_list.emplace("tab", std::make_unique<comp_tab>());

    rev_naif r_naif;
    rev_allocate r_allocate;
    rev_switch r_switch;
    rev_std r_std;
    
    std::cout<<"reverse naif :"<<std::endl;
    std::cout<<"\t"<<"comp naif"<<std::endl;
    assert(rev_comp == r_naif(seq, comp_list["naif"]));
    std::cout<<"\t"<<"comp pol3"<<std::endl;
    assert(rev_comp == r_naif(seq, comp_list["pol3"]));
    std::cout<<"\t"<<"comp hash"<<std::endl;
    assert(rev_comp == r_naif(seq, comp_list["hash"]));
    std::cout<<"\t"<<"comp tab"<<std::endl;
    assert(rev_comp == r_naif(seq, comp_list["tab"]));

    std::cout<<"reverse allocate :"<<std::endl;
    std::cout<<"\t"<<"comp allocate"<<std::endl;
    assert(rev_comp == r_allocate(seq, comp_list["naif"]));
    std::cout<<"\t"<<"comp pol3"<<std::endl;
    assert(rev_comp == r_allocate(seq, comp_list["pol3"]));
    std::cout<<"\t"<<"comp hash"<<std::endl;
    assert(rev_comp == r_allocate(seq, comp_list["hash"]));
    std::cout<<"\t"<<"comp tab"<<std::endl;
    assert(rev_comp == r_allocate(seq, comp_list["tab"]));

    std::cout<<"reverse switch :"<<std::endl;
    std::cout<<"\t"<<"comp switch"<<std::endl;
    assert(rev_comp == r_switch(seq, comp_list["naif"]));
    std::cout<<"\t"<<"comp pol3"<<std::endl;
    assert(rev_comp == r_switch(seq, comp_list["pol3"]));
    std::cout<<"\t"<<"comp hash"<<std::endl;
    assert(rev_comp == r_switch(seq, comp_list["hash"]));
    std::cout<<"\t"<<"comp tab"<<std::endl;
    assert(rev_comp == r_switch(seq, comp_list["tab"]));
    
    std::cout<<"reverse std :"<<std::endl;
    std::cout<<"\t"<<"comp std"<<std::endl;
    assert(rev_comp == r_std(seq, comp_list["naif"]));
    std::cout<<"\t"<<"comp pol3"<<std::endl;
    assert(rev_comp == r_std(seq, comp_list["pol3"]));
    std::cout<<"\t"<<"comp hash"<<std::endl;
    assert(rev_comp == r_std(seq, comp_list["hash"]));
    std::cout<<"\t"<<"comp tab"<<std::endl;
    assert(rev_comp == r_std(seq, comp_list["tab"]));

    return 0;
}









