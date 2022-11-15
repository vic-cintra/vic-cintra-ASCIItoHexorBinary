/*
Victor Cintra
Spring 2022
hex and binary converter
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

int main (int argc, char **argv){//this main takes two arguments, which allows me to differentiate between the binary and hex options
   int hexC = 0;//this hex counter starts at 0 to increment everytime we need a new line
   int hexNL = 16;//this is how many characters are printed for the hex
   int binaryC = 0;
   int binaryNL = 6;
   string line;
   
   if(argc == 2){//this will run the hex file
   ifstream myfile(argv[1]);//opens text file
   cout << setw(9) << setfill('0') << ": ";//this prints the first address using setw and setfill
      while(getline(myfile, line)){//keeps my file open and sets it to "line"
         
         for(int i = 0; i <= line.size(); i++){

            if(i % 2 != 0){//starts at 0, so every 4 characters printed in hex (odd or even) will include a space. This seperates everything so it is in the correct format
               cout << hex << int(line[i]) << " ";
            }else{
               cout << hex << int(line[i]);
            }

            if((i + 1) % 16 == 0){//ensures only 16 characters are printed at a time
               cout << " ";

               while(hexC < hexNL){//prints the line out and increments hexC
                  cout << line[hexC];
                  hexC++;
               }

               cout << endl;
               hexNL = hexNL + 16;//by this line, hexC = 16 and hexNL increments to 32 so we are ready for the next 16 characters

               if(i < line.size()){
                  cout << setfill('0') << setw(7) << hexNL - 16 << ": ";//this continues to print the addresses at the beginning of the new lines
               }
            }
         }
      }

   } else if (strcmp(argv[1],"-b") == 0){//this checks to see if "-b" is an argument, if it is, then it goes to the binary section
      ifstream myfile(argv[2]);
      cout << setw(9) << setfill('0') << ": ";//this begins the addresses again

      while(getline(myfile, line)){//keeps file open

         for(int i = 0; i <= line.size(); i++){
            bitset<8> binary(line[i]);//this sets out the binary to 8 and reads the human code to print it
            cout << binary << " ";

            if((i + 1) % 6 == 0){//this is similar to the hex code above, it just reads 6 human characters at a time
               cout << " ";

               while(binaryC < binaryNL){//this is the same as the code above, the numbers are slightly different to match the binary offset.
                  cout << line[binaryC];
                  binaryC++;
               }
               cout << endl;
               binaryNL = binaryNL + 6;

               if(i < line.size()){
                  cout << setfill('0') << setw(7) << binaryNL - 6 << ": ";
               }
            }
         }
      }
   }
 return 0;
}                                               
