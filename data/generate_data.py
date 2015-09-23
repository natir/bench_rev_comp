#!/usr/bin/env python3

# -*- coding: utf-8 -*-

""" Generate DNA data for benchmark some rev_comp algorithme """

# std import
import argparse


# Control argument
def unsigned_int(val):
    val = int(val)
    if val < 0:
        raise argparse.ArgumentTypeError("You can't use signed value")

    return val


def in_interval_0_1(val):
    val = float(val)
    print(val)
    if val > 1 or val < 0:
        raise argparse.ArgumentTypeError("We required val in [0, 1]")

    return val


# Main programme
def main():
    """ Main function of programme """

    parser = argparse.ArgumentParser(prog="generate_data",
                                     description="Generate DNA data")
    parser.add_argument("-o", "--output", type=str, help="output filename",
                        required=True)
    parser.add_argument("-l", "--min-seq-len", type=unsigned_int,
                        help="minimal sequence length", default=100)
    parser.add_argument("-L", "--max-seq-len", type=unsigned_int,
                        help="maximal sequence length", default=100000000)
    parser.add_argument("-m", "--step-seq", type=unsigned_int,
                        help="multiplicator of sequence growing", default=10)
    parser.add_argument("-g", "--min-gc", type=in_interval_0_1,
                        help="minimal GC %", default=0.0)
    parser.add_argument("-G", "--max-gc", type=in_interval_0_1,
                        help="maximal GC %", default=1.0)
    parser.add_argument("-s", "--step-gc", type=unsigned_int,
                        help="step of gc growing", default=10)

    args = parser.parse_args()

    
def generate_random(gc):
    gc_or_ta = random.random()
    pu_or_py = radom.random()

    if gc_or_ta < gc:
        if pu_or_py < 0.5:
            return 'G'
        else:
            return 'C'
    else:
        if pu_or_py < 0.5:
            return 'A'
        else:
            return 'T'


if __name__ == '__main__':
    main()
