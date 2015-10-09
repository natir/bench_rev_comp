#!/usr/bin/env python3

import arev_comp

class Naive(arev_comp.Arev_comp):

    def _char2char(self, c):
        if c == 'A':
            return 'T'
        if c == 'C':
            return 'G'
        if c == 'G':
            return 'C'
        else:
            return 'A'
        
