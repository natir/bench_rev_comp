#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import io
import sys
import subprocess
import itertools


class Arev_comp:

    def run(self, seq):
        return ''.join(self._char2char(c) for c in seq)[::-1]

    def _char2char(self, c):
        raise NotImplemented

class Hash(Arev_comp):

    def __init__(self):
        self.char2char = dict()
        self.char2char['A'] = 'T'
        self.char2char['T'] = 'A'
        self.char2char['C'] = 'G'
        self.char2char['G'] = 'C'

    def _char2char(self, c):
        return self.char2char[c]

input_gperf = io.StringIO()

# Header part of the gperf file
print("struct kmer_revcomp\n{\n\tchar * kmer;\n\tchar * revcomp;\n};\n",
      file=input_gperf)
print("%language=C++", file=input_gperf)
print("%define slot-name kmer", file=input_gperf) 
print("%includes", file=input_gperf)
print("%7bit", file=input_gperf)
print("%compare-lengths", file=input_gperf)
print("%readonly-tables", file=input_gperf)
print("%struct-type", file=input_gperf)
print("", file=input_gperf)

# Main part of the gperf file
print("%%", file=input_gperf)
rev_comp = Hash()

for k in range(1, int(sys.argv[1]) + 1):
    for kmer in [''.join(p) for p in itertools.product(['A', 'C', 'T', 'G'],
                                                       repeat=k)]:
        print("{}, \"{}\"".format(kmer, rev_comp.run(kmer)), file=input_gperf)

input_gperf.seek(io.SEEK_SET)

p = subprocess.Popen(["gperf"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
output, _ = p.communicate(input_gperf.read().encode())

with open(sys.argv[2], "w") as cpp_outfile:
    cpp_outfile.write(output.decode())
