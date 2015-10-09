#!/usr/bin/env python3

import arev_comp

class Hash(arev_comp.Arev_comp):

    def __init__(self):
        self.char2char = dict()
        self.char2char['A'] = 'T'
        self.char2char['T'] = 'A'
        self.char2char['C'] = 'G'
        self.char2char['G'] = 'C'

    def _char2char(self, c):
        return self.char2char[c]
