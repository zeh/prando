import re


def remove_substring(str, substr):
    return re.sub(substr, '', str)
