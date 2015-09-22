
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
    std::map<std::string, std::string> seq_list;
    seq_list.emplace("0", "AAAAAAAATATTTAAAATTAAAAATAATTAATATTTTAAATTTTATTTAATTTATTTATATATTATTATAATAAATTAATAAAAATTTAATATTAAATAA");
    seq_list.emplace("10", "TAAAATATTCTTAATTTTAATAAAAAATTAAAAGAAATATATATACAATATAAAGAAGTTAGAAAATTAATAAGAGAATTTTCTTTCTGTTTATTAAAGA");
    seq_list.emplace("20", "TATTTATAAAGTCCGCCATACAAATAATAATTCAAAAAAATTATTGATTAATTTATCTAAACGATAACCTTTTGTATCATATTAGAGCGGAAAGATAATT");
    seq_list.emplace("30", "ATAATGCTGCTTATAATCTCTCTGTCGTTGTTAACGTTTATAGTCTAGTTTCATTATAATTGTATGTTATTGAGGCATTGATTAATACTGGAAAACATTT");
    seq_list.emplace("40", "GAAATGAACTAATCTATACGACAGAAACCGTGTACCTACCAAATCTCTTTAATGTAAGTTCTGACTAATTCGTACTTTGTTAAGAACTTACATTTTAACA");
    seq_list.emplace("50", "CTAACCACCGTGTATTCATTATGGTACCAGGGACTTTAAGCCGAGTCAATGGAGCTCGCAATACAGAGTTTACCGCATCTTGCCGTAACTGACAAACTGT");
    seq_list.emplace("60", "ACAGGGGACATATGCCCTACCCCCATGATCTACTGGCGTCCCTGAGGCTGCAGTTCATGTGGTGGGGCAGCATCCGCGGCAAGCCCTAGTGCAATGGCGG");
    seq_list.emplace("70", "TTTCCCGCCCCCGTTCCGAGGAAGAGGCGGCGCGGGTGCGGCCATCGCTAGTGCGGAAACTGGGGAGGCTCCCGGGCCTCCGCCTTTAGGCGGTGCCTGC");
    seq_list.emplace("80", "CCCCTCGTAGAGGGGCTGCCAGCCATGCCCCGCGGGGGTCCGGGAAGGCGAGCCGGCCCGGCCGACCCGGGGGGGCGGGCCTCGGAGCCGCCCGGCGACG");
    seq_list.emplace("90", "GCCGTGGGCCCGCGGCGGAACCCCCCCGGCGAGCCCCCGCGGGCGCCGGCTGGGCGGCCCCGGCCGGCCCGACCAGGGGCCCGGACGCGCCGCCCCACGG");
    seq_list.emplace("100", "CCCCCGGGCCGGGGCGCGCCGCCCCGCGGGGGCCGGGGCCGCCCGCCGGCCCCCGCCGCGCCCGCGCCGCGCGCGCCCGCCCCCCCGCCCGCCCGCCCGG");

    std::map<std::string, std::unique_ptr<arev_comp> > bench_list;

    bench_list.emplace("tab", std::make_unique<rev_comp_tab>());
    bench_list.emplace("hash", std::make_unique<rev_comp_tab>());
    bench_list.emplace("naive", std::make_unique<rev_comp_naive>());
    bench_list.emplace("pol3", std::make_unique<rev_comp_pol3>());

    std::cout<<"gc%";
    for(const auto &pair : bench_list)
	std::cout<<","<<pair.first;
    std::cout<<std::endl;
    
    for(const auto &seq : seq_list)
    {
	std::cout<<seq.first;
	for(const auto &algo : bench_list)
	{
	    auto begin = std::chrono::high_resolution_clock::now();
        
	    for(auto i = 0; i != 1000000; i++)
	    {
		algo.second->run(seq.second);
	    }

	    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

	    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	    std::cout<<","<<duration;
	}
	std::cout<<std::endl;
    }
}
