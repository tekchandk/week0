""" 
Problem: Print censor message
Date: 06.04.2019
Author: Mr. Tek Chand

"""

from sys import argv

words = set()

def main():
    #check command-line argument
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    #load txt file
    load(argv[1])
    sentence = input("Type your sentence here: ")
    sentence_words = sentence.split()
    for i in sentence_words:
        # Check the word in banned words dictionary
        if(check(i)):
            for j in range(len(i)):
                print("*",end="")
        else:
            print(i, end="")
        print(" ", end="")
    return True

def load(infile):
    #load word in txt file
    file = open(infile, "r")
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()
    return True

# Return true if word found in banned dictionary else false
def check(word):
    return word.lower() in words

if __name__ == "__main__":
    main()
