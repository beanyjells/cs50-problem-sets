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
    a_substrings = list()

    for i in range(len(a)):
        if len(a) == n:
            break
        elif len(a) < n:
            break
        elif len(a[i:i+n]) < n:
            break
        else:
            a_substrings.append(a[i:i+n])

    b_substrings = list()

    for j in range(len(b)):
        if len(b) == n:
            break
        elif len(b) < n:
            break
        elif len(b[i:i+n]) < n:
            break
        else:
            b_substrings.append(a[i:i+n])

    # remove duplicates from each list
    a_substrings = list(dict.fromkeys(a_substrings))
    b_substrings = list(dict.fromkeys(b_substrings))

    samesubstringslist = list()

    #iterate over the two lists to find matching sentences & append them to one list
    for z in a_substrings:
        for xx in b_substrings:
            if z == xx:
                samesubstringslist.append(z)

    return samesubstringslist
