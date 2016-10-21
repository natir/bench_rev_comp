/* std include */
#include <memory>
#include <iostream>
#include <chrono>

#include "mphf_kmer.hpp"

#ifndef KMER
#define KMER 4
#endif

std::string rev_comp_naif(std::string seq)
{
    std::string rev_comp;

    unsigned int k = KMER;
    unsigned int i = 0;

    for(; i < seq.length() && k > 0; k--)
    {
        while(signed(seq.length() - k + 1) > 0 && i < signed(seq.length() - k + 1))
        {
            auto tmp = Perfect_Hash::in_word_set(seq.substr(i, k).c_str(), k);
            if(tmp != 0)
                rev_comp = tmp->revcomp + rev_comp;
            i += k;
        }
    }

    return rev_comp;
}

std::string rev_comp_allo(std::string seq)
{
    std::string rev_comp(seq.length(), 'A');

    unsigned int k = KMER;
    unsigned int i = 0;
    for(; i < seq.length() && k > 0; k--)
    {
        while(signed(seq.length() - k + 1) > 0 && i < seq.length() - k + 1)
        {
            //std::cout<<rev_comp<<" "<<seq.length()<<" "<<i<<" "<<k<<std::flush;
            auto tmp = Perfect_Hash::in_word_set(seq.substr(i, k).c_str(), k);
            if(tmp != 0)
                rev_comp.replace(seq.length() - (k + i), k, tmp->revcomp);
            i += k;
            //std::cout<<" "<<rev_comp<<std::endl;
        }
    }

    return rev_comp;
}

int main(int argc, char** argv)
{
    /* Take argument */
    long long repeat = std::stoll(std::string(argv[1]));
    std::string seq(argv[2]);

    /* print algorithme name */
    std::cout<<"mphf_naif,mphf_allo"<<std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i != repeat; i++)
    {
        rev_comp_naif(seq);
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<duration;

    begin = std::chrono::high_resolution_clock::now();

    for(auto i = 0; i != repeat; i++)
    {
        rev_comp_allo(seq);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<","<<duration<<std::endl;


    //std::cout<<rev_comp_naif(seq)<<std::endl;
    //std::cout<<rev_comp_allo(seq)<<std::endl;

    return 0;
}

