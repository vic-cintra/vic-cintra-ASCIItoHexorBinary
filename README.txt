Victor Cintra
Spring 2022
Hex and binary converter

This project can take any text, in this case Winston Churchill's speech, and convert it into binary or hex.

This project contains a Makefile, an include.txt file (Winston Churchill's speech), an
xed.cpp file (source code), and a README.txt file.

To compile for hex with xCode, in the terminal type:
xed include.txt 

To compile for binary with xCode, in the terminal:
xed -b include.txt

If xCode is not installed, the application can be run from the terminal using:
g++ xed.cpp -o xed

Then for hex enter:
./xed include.txt

Or for binary enter:
./xed -b include.txt

The makefile takes care of the inputs required. Also, if you would like to run a different file through, you can copy and paste it and replace Churchills speech.
