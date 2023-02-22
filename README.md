# mygrep
This program is a very minimalist version of grep. This readme will be updated as the program gets more functionality. Updates will be sorted with timestamps formatted
DD/MM/YY

Accepted command line options:
-ol     Gives you the number of the line where the matching string was found
-oo     Gives you the occurences of lines containing the search string in the file
-olo    Combination of -ol and -oo
-h      Prints short usage guide (give only this after ./my_grep.exe)



Example (for the filename you can give the path to the .txt file):

./my_grep.exe following man_grep_plain_ASCII.txt
Above will search for the string "following" from "man_grep_plain_ASCII.txt" file and print out the lines containing the string


./my_grep.exe -ol following man_grep_plain_ASCII.txt
Above will search for the string "following" from "man_grep_plain_ASCII.txt" file, print out the lines containing the string and the line number where it was found

22/02/23
Added more command line arguments


15/02/23
For now the program accepts 2 command line arguments. 
1. Search string: the string that the user wants to search from a file
2. Filename: File from which to search the string
If no arguments provided, program will ask the user for a string and then another string that will be searched from the first string



