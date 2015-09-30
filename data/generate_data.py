#!/usr/bin/env python3

# -*- coding: utf-8 -*-

""" Generate DNA data for benchmark some rev_comp algorithme """

# std import
import sys
import argparse
import random
from numpy import arange


# Control argument
def unsigned_int(val):
    val = int(val)
    if val < 0:
        raise argparse.ArgumentTypeError("You can't use signed value")

    return val


def in_interval_0_1(val):
    val = float(val)

    if val > 1 or val < 0:
        raise argparse.ArgumentTypeError("We required val in [0, 1]")

    return val


# Main programme
def main(args):
    """ Main function of programme """

    parser = argparse.ArgumentParser(prog="generate_data",
                                     description="Generate DNA data",
                                     formatter_class=argparse.
                                     ArgumentDefaultsHelpFormatter)
    parser.add_argument("-o", "--output", type=str, help="output filename",
                        required=True)
    parser.add_argument("-l", "--min-seq-len", type=unsigned_int,
                        help="minimal sequence length", default=100)
    parser.add_argument("-L", "--max-seq-len", type=unsigned_int,
                        help="maximal sequence length", default=100000000)
    parser.add_argument("-m", "--step-seq", type=unsigned_int,
                        help="multiplicator of sequence growing", default=10)
    parser.add_argument("-g", "--min-gc", type=in_interval_0_1,
                        help="minimal GC percent", default=0.0)
    parser.add_argument("-G", "--max-gc", type=in_interval_0_1,
                        help="maximal GC percent", default=1.0)
    parser.add_argument("-s", "--step-gc", type=in_interval_0_1,
                        help="step of gc growing", default=0.1)

    args = vars(parser.parse_args(args))

    with open(args["output"], "w") as outfile:
        outfile.write("length,gc,seq\n")
        for len_seq in range_geo(args["min_seq_len"],
                                 args["max_seq_len"]*args["step_seq"],
                                 args["step_seq"]):
            for gc in arange(args["min_gc"], args["max_gc"]+args["step_gc"],
                             args["step_gc"]):
                outfile.write(str(len_seq) + "," + str(gc) + "," +
                              ''.join(generate_random(gc, len_seq)) + "\n")


def range_geo(start, stop=1, step=2):
    start, stop = (stop, start) if stop < start else (start, stop)

    while start < stop:
        yield start
        start *= step


def generate_random(gc, n):
    for i in range(n):
        gc_or_ta = random.random()
        pu_or_py = random.random()

        if gc_or_ta < gc:
            if pu_or_py < 0.5:
                yield 'G'
            else:
                yield 'C'
        else:
            if pu_or_py < 0.5:
                yield 'A'
            else:
                yield 'T'


if __name__ == '__main__':
    main(sys.argv[1:])
