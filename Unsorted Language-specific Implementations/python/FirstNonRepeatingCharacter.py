#!/usr/bin/env python3


def find_first_non_repeat_char(input_string):
    return [a for a in input_string if input_string.count(a) == 1][0]
