from cs50 import get_string


def main():
    text = get_string("Text: ")

    # Average number of letters per 100 words in the text
    L = count_letters(text) * 100 / count_words(text)

    # Average number of sentences per 100 words in the text
    S = count_sentences(text) * 100 / count_words(text)

    # Grade level computed by the Coleman-Liau formula, rounded to the nearest integer
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# Count the number of letters in the text
def count_letters(array):
    sum = 0
    for i in range(len(array)):
        if array[i].isalpha():
            sum += 1
    return sum


# Count the number of words in the text
def count_words(array):
    sum = 0
    for i in range(len(array)):

        # Count words when char is a space and after it follows not a space. Don't count when space(s) are before first or after the last word
        if (i == 0 and array[i] != " ") or (array[i] == " " and array[i + 1] != " " and i != len(array) - 1):
            sum += 1
    return sum


# Count the number of sentences in the text
def count_sentences(array):
    sum = 0
    for i in range(len(array)):

        # Count sentences when char is '.', '!' or '?'
        if array[i] == "." or array[i] == "!" or array[i] == "?":
            sum += 1
    return sum


main()
