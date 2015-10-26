#!/usr/bin/env python3

# -*- coding: utf8 -*-

# std import
import sys
import os

# pytest import
import pytest


# setup environement
@pytest.fixture()
def setup_env():
    base_path = os.path.dirname(os.path.realpath('__file__'))
    sys.path.append(os.path.join(base_path, ".."))


def test_rev_comp_tab(setup_env):
    import rev_comp_tab

    algo = rev_comp_tab.Tab()
    assert "CAGT" == algo.run("ACTG")


def test_rev_comp_pol3(setup_env):
    import rev_comp_pol3

    algo = rev_comp_pol3.Pol3()
    assert "CAGT" == algo.run("ACTG")


def test_rev_comp_hash(setup_env):
    import rev_comp_hash

    algo = rev_comp_hash.Hash()
    assert "CAGT" == algo.run("ACTG")


def test_rev_comp_naive(setup_env):
    import rev_comp_naive

    algo = rev_comp_naive.Naive()
    assert "CAGT" == algo.run("ACTG")
