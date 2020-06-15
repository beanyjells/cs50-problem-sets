import sys
import csv
from sys import argv
from cs50 import SQL

db = SQL ("sqlite:///students.db")

# checking the command line arguments
if len(sys.argv) != 2:
    print("Usage: python import.py characters.csv \n")
    exit(1)

# Open CSV file and read it
with open(sys.argv[1], "r") as characters:

    # Create DictReader
    reader = csv.DictReader(characters)

    # Iterate over CSV file
    for row in reader:

        #Check the length of the name
        check_name = row["name"]
        name_list = check_name.split()

        # Split the full name into first, middle and last names
        first_name = name_list[0]

        # If the student has a middle name, store it
        if len(name_list) == 3:
            middle_name = name_list[1]
            last_name = name_list[2]

        # If the student does not have a middle name, input as 'None'
        elif len(name_list) == 2:
            middle_name = None
            last_name = name_list[1]

        # Insert student info in the students table
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", first_name, middle_name, last_name, row["house"], row["birth"])