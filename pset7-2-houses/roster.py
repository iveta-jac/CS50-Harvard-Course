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

    # Query database for all students in house
    rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house=? ORDER BY last", house);

    for row in rows:
        print(row)


main()
