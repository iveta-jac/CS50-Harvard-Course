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

        # Iterate over students
        for row in data:

            # Separate each name into first, (middle), and last names
            name = row["name"].split(" ")

            # If there is no middle name
            if len(name) == 2:
                print("2")

            # With middle name
            if len(name) == 3:
                print("3")

            # Insert temporary data into the table
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", row["name"], "NULL", "NULL", row["house"], row["birth"])


main()
