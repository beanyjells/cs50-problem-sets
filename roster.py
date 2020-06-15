import csv
import sys
from cs50 import SQL

db = SQL ("sqlite:///students.db")

# checking the command line arguments
if len(sys.argv) != 2:
    print("Usage: python roster.py House \n")
    exit(1)

# capitalise the house name
house_input = sys.argv[1].lower().capitalize()

# create the student roster
studentroster = db.execute("SELECT first, middle, last, birth from students WHERE house = (?) ORDER BY last, first", house_input)

# if student does not have a middle name, do not print 'none'
for row in studentroster:
    if row["middle"] == None:
        print(row["first"], row["last"] + ", born", row["birth"])

    else:
        print(row["first"], row["middle"], row["last"] + ", born", row["birth"])
