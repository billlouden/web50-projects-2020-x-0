
from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    # TODO
    # split strings into lines
    # create list of all lines that are in a and b
    # return the list
    # \n will terminate each line
    # look at string python methods
    # https://docs.python.org/3/library/stdtypes.html#string-methods
    # find lines in common
    # choose set for data structure
    # data-structures
    # remove duplicate lines
    # display list of lines in common

    a_lines = set(a.split("\n"))
    b_lines = set(b.split("\n"))

    return a_lines & b_lines


def sentences(a, b):
    """Return sentences in both a and b"""
    # TODO
    # compare sentences
    # split into sentences
    # need to determine punctuation that ends various sentences
    # use python library NLTK  natural language tokenize
    # nltk sent_tokenize
    # from nltk.tokenize import sent_tokenize
    # then find sentences in common, avoiding duplicates
    # display list of natural sentences in common

    a_sentences = set(sent_tokenize(a))
    b_sentences = set(sent_tokenize(b))

    return a_sentences & b_sentences


def substring_tokenize(s, n):
    substrings = []
    # Extract all substrings from string
    # s[i:j] returns substring of s from index i up to index j-1

    for i in range(len(s) - n + 1):
        substrings.append(s[i:i + n])

    return substrings

    # TODO
    # compare substrings using integer n for length of string to compare
    # split each string into all possible substrings of length n
    # e.g.  string 5 chars longs, searching substring of len 3
    # n =3; input "Hello" = "Hel", "ell", "llo"
    # n= 2; input "Hello" = "He", "el", "ll", "lo"
    # process all permuations in both files by
    #
    # display list of substrings in common


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    a_substrings = set(substring_tokenize(a, n))
    b_substrings = set(substring_tokenize(b, n))

    return a_substrings & b_substrings