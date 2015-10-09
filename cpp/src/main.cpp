
/* std include */
#include <memory>
#include <iostream>
#include <map>
#include <chrono>

/* sys include */
#include <sys/time.h>

/* project include */
#include "arev_comp.hpp"
#include "rev_comp_hash.hpp"
#include "rev_comp_tab.hpp"
#include "rev_comp_naive.hpp"
#include "rev_comp_pol3.hpp"
#include "rev_comp_hash_allocate.hpp"
#include "rev_comp_tab_allocate.hpp"
#include "rev_comp_naive_allocate.hpp"
#include "rev_comp_pol3_allocate.hpp"
#include "rev_comp_hash_switch.hpp"
#include "rev_comp_tab_switch.hpp"
#include "rev_comp_naive_switch.hpp"
#include "rev_comp_pol3_switch.hpp"

int main(int argc, char** argv)
{
    /* Take argument */
    long long repeat = std::stoll(std::string(argv[1]));
    std::string seq(argv[2]);

    /* Initialize algorithme */
    std::map<std::string, std::unique_ptr<arev_comp> > bench_list;
    bench_list.emplace("tab", std::make_unique<rev_comp_tab>());
    bench_list.emplace("hash", std::make_unique<rev_comp_hash>());
    bench_list.emplace("naive", std::make_unique<rev_comp_naive>());
    bench_list.emplace("pol3", std::make_unique<rev_comp_pol3>());
    bench_list.emplace("tab_allocate", std::make_unique<rev_comp_tab_allocate>());
    bench_list.emplace("hash_allocate", std::make_unique<rev_comp_hash_allocate>());
    bench_list.emplace("naive_allocate", std::make_unique<rev_comp_naive_allocate>());
    bench_list.emplace("pol3_allocate", std::make_unique<rev_comp_pol3_allocate>());
    bench_list.emplace("tab_switch", std::make_unique<rev_comp_tab_switch>());
    bench_list.emplace("hash_switch", std::make_unique<rev_comp_hash_switch>());
    bench_list.emplace("naive_switch", std::make_unique<rev_comp_naive_switch>());
    bench_list.emplace("pol3_switch", std::make_unique<rev_comp_pol3_switch>());

    /* print algorithme name */
    bool first = true;
    for(const auto &pair : bench_list)
    {
	if(first)
	    std::cout<<pair.first;
	else
	    std::cout<<","<<pair.first;
	first = false;
    }
    std::cout<<std::endl;

    /* loop on all algorithme and print result */
    first = true;
    for(const auto &algo : bench_list)
    {
	auto begin = std::chrono::high_resolution_clock::now();
        
	for(auto i = 0; i != repeat; i++)
	{
	    algo.second->run(seq);
	}

	auto elapsed = std::chrono::high_resolution_clock::now() - begin;

	long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	if(first)
	    std::cout<<duration;
	else
	    std::cout<<","<<duration;
	first = false;
    }
    std::cout<<std::endl;

    return 0;
}
