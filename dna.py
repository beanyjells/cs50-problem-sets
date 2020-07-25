from sys import argv, exit
import sys
import csv


# check that there are 3 arguments in the command line
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(0)

# open and read csv file as a list
csv_file = open(sys.argv[1], newline='')
csvreader = csv.reader(csv_file)

# store the first line of the csv file as a list
headings = next(csvreader)

# open and read text file
text_file = open(sys.argv[2], "r")
textreader = text_file.read()

# initialise an empty list for the STR counts
str_counts = []


# iterate through DNA text file to compute the STR counts
for i in range(1, len(headings)):
    counter = 0
    n = 1

    while headings[i]*n in textreader: # counts the longest sequence of the STR
        n += 1
    if (n - 1) > counter:
        counter = n - 1
    str_counts.append(counter) # stores the value of the longest sequence of the STR

# check if the STR counts match with any in the database or csv file

match = False

# iterate through csv file for a match
for row in csvreader:
    tally = 0

    for c in range(len(str_counts)):
        # check if each STR count matches exactly with the entry in the csv file
        if int(row[c+1]) == int(str_counts[c]):
            tally += 1
        else:
            break

    if tally == len(str_counts): # this proves that all the STR counts match with one person
        print(row[0])
        match = True
        break

# if there is no match
if match == False:
    print("No match")

# close both files
text_file.close()
csv_file.close()