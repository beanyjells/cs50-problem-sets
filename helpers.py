from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # turn files a and b into sets of lines
    linelist_a = set(a.splitlines())
    linelist_b = set(b.splitlines())

    # put the same lines in both files lists into a separate list of lines
    samelineslist = list(set.intersection(linelist_a, linelist_b))

    return samelineslist


def sentences(a, b):
    """Return sentences in both a and b"""

    # turn files a and b into sets of sentences
    a_sentences = set(sent_tokenize(a))
    b_sentences = set(sent_tokenize(b))

    # put the same sentences in both files into a separate list of sentences
    samesentenceslist = list(set.intersection(a_sentences, b_sentences))

    return samesentenceslist


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # turn files a and b into sets of substrings
    a_substrings = {a[k:k+n-1] for k in range(0, len(a), n-1)}
    b_substrings = {b[k:k+n-1] for k in range(0, len(b),n-1)}

    # put the same substrings in both files into a separate list of substrings
    samesubstringslist = list(set.intersection(a_substrings, b_substrings))

    return samesubstringslist
