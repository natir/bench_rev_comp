#!/usr/bin/env python3

class Arev_comp:

    def run(self, seq):
        rev_comp = str()

        for c in seq:
            rev_comp = self._char2char(c) + rev_comp
            
        return rev_comp

    def _char2char(self, c):
        raise NotImplemented
