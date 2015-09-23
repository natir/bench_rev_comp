
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

int main(int argc, char** argv)
{
    /* Take argument */
    long long repeat = std::stoll(std::string(argv[1]));
    std::string seq(argv[2]);

    /* Initialize algorithme */
    std::map<std::string, std::unique_ptr<arev_comp> > bench_list;
    bench_list.emplace("tab", std::make_unique<rev_comp_tab>());
    bench_list.emplace("hash", std::make_unique<rev_comp_tab>());
    bench_list.emplace("naive", std::make_unique<rev_comp_naive>());
    bench_list.emplace("pol3", std::make_unique<rev_comp_pol3>());

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
