#!/usr/bin/env python3

import arev_comp

class Tab(arev_comp.Arev_comp):

    def __init__(self):
        self.char2char = [None for _ in range(ord('T')+1)]
        self.char2char[ord('A')] = 'T'
        self.char2char[ord('T')] = 'A'
        self.char2char[ord('C')] = 'G'
        self.char2char[ord('G')] = 'C'

    def _char2char(self, c):
        return self.char2char[ord(c)]
