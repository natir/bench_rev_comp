
/* std include */
#include <memory>
#include <iostream>
#include <map>
#include <chrono>

/* project include */
#include "acomp.hpp"
#include "comp_naif.hpp"
#include "comp_pol3.hpp"
#include "comp_hash.hpp"
#include "comp_tab.hpp"

#include "arev.hpp"
#include "rev_naif.hpp"
#include "rev_allocate.hpp"
#include "rev_switch.hpp"
#include "rev_std.hpp"

int main(int argc, char** argv)
{
    /* Take argument */
    long long repeat = std::stoll(std::string(argv[1]));
    std::string seq(argv[2]);

    /* Initialize algorithme */
    std::map<std::string, std::unique_ptr<acomp> > comp_list;
    comp_list.emplace("naif", std::make_unique<comp_naif>());
    comp_list.emplace("pol3", std::make_unique<comp_pol3>());
    comp_list.emplace("hash", std::make_unique<comp_hash>());
    comp_list.emplace("tab", std::make_unique<comp_tab>());

    std::map<std::string, std::unique_ptr<arev> > rev_list;
    rev_list.emplace("naif", std::make_unique<rev_naif>());
    rev_list.emplace("allocate", std::make_unique<rev_allocate>());
    rev_list.emplace("switch", std::make_unique<rev_switch>());
    rev_list.emplace("std", std::make_unique<rev_std>());
    
    /* print algorithme name */
    bool first = true;
    for(const auto &comp : comp_list)
    {
	for(const auto &rev : rev_list)
	{
	    if(!first)
		std::cout<<",";

	    std::cout<<"rev_"<<rev.first<<"_comp_"<<comp.first;
	    first = false;
	}
    }
    std::cout<<std::endl;

    /* loop on all algorithme and print result */
    first = true;
    for(const auto &comp : comp_list)
    {
	for(const auto &rev : rev_list)
	{
	    auto begin = std::chrono::high_resolution_clock::now();

	    for(auto i = 0; i != repeat; i++)
	    {
		(*rev.second)(seq, comp.second);
	    }

	    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

	    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	    if(!first)
		std::cout<<",";

	    std::cout<<duration;
	    first = false;
	}
    }
    std::cout<<std::endl;

    return 0;
}
