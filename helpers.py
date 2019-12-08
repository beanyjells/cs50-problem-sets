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

    # find the substrings in each file and put them in a list
    a_substrings = set()
    a_length = len(a)

    for i in range(a_length):
        if a_length == n:
            break
        elif a_length < n:
            break
        elif len(a[i:i+n]) < n:
            break
        else:
            a_substrings.add(a[i:i+n])

    b_substrings = set()
    b_length = len(b)

    for i in range(b_length):
        if b_length == n:
            break
        elif b_length < n:
            break
        elif len(b[i:i+n]) < n:
            break
        else:
            b_substrings.add(b[i:i+n])

    # iterate over the two lists to find matching sentences & append them to one list
    samesubstringslist = list(set.intersection(a_substrings, b_substrings))

    return samesubstringslist