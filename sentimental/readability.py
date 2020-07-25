from cs50 import get_string

def main():
    # prompt user to input text
    text = get_string("Text: ").lower()

    # count number of words in the text
    num_words = len(text.split())

    num_sentences = 0
    num_letters = 0

    for x in range(len(text)):

        # count the number of letters in the text
        if text[x] >= 'a' and text[x] <= 'z':
            num_letters += 1

        # count the number of sentences by counting the number of special characters - ./?/!
        elif text[x] == '?' or text[x] == '!' or text[x] == '.':
            num_sentences += 1

    # Using the Coleman-Liau formula, calculate the index
    L = (num_letters * 100) / num_words
    S = (num_sentences * 100) / num_words

    index =  0.0588 * L - 0.296 * S - 15.8

    # print reading grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade", round(index))


if __name__ == "__main__":
    main()