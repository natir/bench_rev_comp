
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

int main(int argc, char** argv)
{
    std::string base_str = "CTAACCACCGTGTATTCATTATGGTACCAGGGACTTTAAGCCGAGTCAATGGAGCTCGCAATACAGAGTTTACCGCATCTTGCCGTAACTGACAAACTGT";

    std::map<std::string, std::unique_ptr<arev_comp> > bench_list;

    bench_list.emplace("tab", std::make_unique<rev_comp_tab>());
    bench_list.emplace("hash", std::make_unique<rev_comp_tab>());
    bench_list.emplace("naive", std::make_unique<rev_comp_naive>());

    std::cout<<"Base sequence "<<base_str<<std::endl;
    for(const auto &it : bench_list)
    {
	std::cout<<"Result for "<<it.first<<" "<<it.second->run(base_str)<<std::endl;
    }
    
    for(const auto &it : bench_list)
    {
	auto begin = std::chrono::high_resolution_clock::now();
        
	for(auto i = 0; i != 10000; i++)
	{
	    it.second->run(base_str);
	}

	auto elapsed = std::chrono::high_resolution_clock::now() - begin;

	long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	std::cout<<"10 000 call of "<<it.first<<" algo : "<<duration<<" microseconds "<<std::endl;
    }
}








