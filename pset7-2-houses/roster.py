# A program that prints a list of students for a given house in alphabetical order
from cs50 import SQL
from sys import argv, exit


# Set up a database connection
db = SQL("sqlite:///students.db")

def main():

    # Check for correct number of args
    if len(argv) != 2:
        print("Usage: python roster.py Gryffindor")
        exit(1)

    house = argv[1]

    # Query database for all students in a house, sort by last name, then first name
    rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", house);

    # Print out each student's full name and birth year
    for row in rows:

        # If there is no middle name
        if row["middle"] != "NULL":
            print(row["first"] + " " + row["middle"] + " " + row["last"] + ",", "born", row["birth"])

        # With middle name
        else:
            print(row["first"] + " " + row["last"] + ",", "born", row["birth"])


main()
