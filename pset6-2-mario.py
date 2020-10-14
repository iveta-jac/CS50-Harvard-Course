from cs50 import get_int

# Positive integer between 1 and 8, inclusive
while True:
    h = get_int("Height: ")
    if h >= 1 and h <= 8:
        break

for i in range(h):

    # Make spaces
    print(" " * (h - i - 1), end="")

    # Make hashes
    print("#" * (i + 1), end="")

    # Make 2 spaces
    print("  ", end="")

    # Make hashes again
    print("#" * (i + 1))