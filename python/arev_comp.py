#!/usr/bin/env python3

class Arev_comp:

    def run(self, seq):
        return reversed(''.join(self._char2char(c) for c in seq))

    def _char2char(self, c):
        raise NotImplemented
