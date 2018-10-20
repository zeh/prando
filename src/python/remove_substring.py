import re


def remove_extra(str, substr):
    return re.sub(substr, '', str)
