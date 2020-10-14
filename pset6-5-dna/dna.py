import csv
from sys import argv, exit


def main():

    # Check for correct number of args
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Try to open files if they exist
    try:

        # Open data file
        data = csv.DictReader(open(argv[1], 'r'))

        # Open a sequence of DNA file
        with open(argv[2], 'r') as sequence:
            dna = sequence.read()

        # Initialize empty dictionary for saving STR counts
        str_count = {}

        # For each STR, compute the longest run of consecutive repeats in the DNA sequence
        for STR in data.fieldnames[1:]:
            i = 0
            count = 0
            max_count = 0
            while i <= len(dna) - len(STR):
                current_slice = dna[i: i + len(STR)]
                if current_slice == STR:
                    count += 1
                    max_count = max(max_count, count)
                    i += len(STR)
                else:
                    i += 1
                    count = 0

            # Save maximum STRs counts in a dictionary using
            str_count[STR] = str(max_count)

        # Compare STR counts with individuals in the CSV file, print a name if there's a match
        for person in data:
            match = 0
            for STR in str_count:
                if str_count[STR] != person[STR]:
                    break
                else:
                    match += 1
            if match == len(str_count):
                print(person['name'])
                exit(0)
        print("No match")

    # Error when file doesn't exist
    except FileNotFoundError:
        print("File(s) not found")
        exit(1)


main()