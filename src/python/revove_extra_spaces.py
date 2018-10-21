import re


def remove_extra(str):
    return re.sub(' +', ' ', str)
