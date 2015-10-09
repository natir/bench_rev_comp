#!/usr/bin/env python3

import arev_comp

class Pol3(arev_comp.Arev_comp):

    def _char2char(self, c):
        return chr(int((((-0.045625*ord(c) + 10.1787)*ord(c)) - 753.8)*ord(c) + 18606))
