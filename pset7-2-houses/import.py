from cs50 import SQL
from sys import argv, exit
import csv


# Set up a database connection
db = SQL("sqlite:///students.db")

def main():

    # Check for correct number of args
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(1)

    # Open data file
    with open(argv[1], 'r') as csv_file:
        data = csv.DictReader(csv_file)

        for row in data:
            print(row)


main()
