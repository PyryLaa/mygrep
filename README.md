# mygrep
This program is a very minimalist version of grep. This readme will be updated as the program gets more functionality. Updates will be sorted with timestamps formatted
DD/MM/YY



Example (enter these to command line in the directory where my_grep.exe is):

./my_grep.exe following man_grep_plain_ASCII.txt
Above will search for the string "following" from "man_grep_plain_ASCII.txt" file and print out the lines containing the string
For the filename you can also give a path to a file eg. "~/Documents/test.txt" would go to your documents folder (if ~ is your /users/USERNAME/ folder)

15/02/23
For now the program accepts 2 command line arguments. 
1. Search string: the string that the user wants to search from a file
2. Filename: File from which to search the string
If no arguments provided, program will ask the user for a string and then another string that will be searched from the first string

