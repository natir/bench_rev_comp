/* std include */
#include <memory>
#include <iostream>
#include <chrono>

#include "mphf_4mer.hpp"

std::string rev_comp(std::string seq)
{
    std::string rev_comp;

    unsigned int k = 4;
    unsigned int i = 0;

    for(; i < seq.length() && k > 0; k--)
    {
        for(; i < seq.length() - k + 1; i += k)
        {
            rev_comp = Perfect_Hash::in_word_set(seq.substr(i, k).c_str(), k)->revcomp + rev_comp;
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
    std::cout<<"mphf_4mer"<<std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    rev_comp(seq);

    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<duration<<std::endl;

    return 0;
}

