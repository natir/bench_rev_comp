#!/usr/bin/env python3

class Arev_comp:

    def run(self, seq):
        return ''.join(self._char2char(c) for c in seq)[::-1]

    def _char2char(self, c):
        raise NotImplemented
