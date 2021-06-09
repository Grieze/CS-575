README.txt

This program works by pasting in the filepath for the program to use. An example would be like: 

C:\numbers.txt

There is no need for quotes or double back slashes as the program should be able to find the file. 
Worst case you can modify the code by pasting the file in the current working directory of the source code 
and manually pasting the file path where it says ifstream data(inputFile); located on line 17.
Just change inputFile to "numbers.txt" or whatever the file name is and move that file name into 
the current working directory. Then once it finishes compiling it should exit with code 0 and you should
see an output file called output which is a text file in your current working directory.