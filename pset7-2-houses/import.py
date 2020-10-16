# Import data from a CSV spreadsheet into a database table
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

                # Insert data into the table
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                           name[0], None, name[1], row["house"], row["birth"])

            # With middle name
            if len(name) == 3:

                # Insert data into the table
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                           name[0], name[1], name[2], row["house"], row["birth"])


main()
