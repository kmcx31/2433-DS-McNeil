///////////////////////////////////////////////////////////////////////////////
// Author: Kevin McNeil Jr.
// Email:  shaqmantoo121@yahoo.com
// Title:  Program 1
// Semester: Spring 2020
//
// Description:
//       Uses a pre-created input file to read in integers. One by one are processed thru their bit values which
//       coorispond to messages that decide how to give an assignment.
//
// Usage:
//
// Files:   main.cpp    :   driver program
//          bits.dat    :   input
//          test.dat    :   input
//          test.out    :   output
//          mcneil_kevin_bits.out   :   output
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

/**
     * void openFiles
     * 
     * Description:
     *      Uses a pre-created input file and creates(if needed) an output file.
     * 
     * Params:
     *      ifstream&    :   input file by address to open
     *      ofstream&    :   output file by address to open
     * 
     * Returns:
     *      void
     */
void openFiles(ifstream& infile, ofstream& outfile){
    char inFileName[40];
    char outFileName[40];

    cout << "Enter the input file name: ";
    cin >> inFileName;
    infile.open(inFileName);

    cout << "Enter the output file name: ";
    cin >> outFileName;
    outfile.open(outFileName);

}

/**
     * int* getBits
     * 
     * Description:
     *      Receives a number and calculates its bit values using shift right operator.
     * 
     * Params:
     *      unsigned int     :   Keeps bit value at 16. Also keeps user from putting in a negative.
     * 
     * Returns:
     *      An array with size [16] with a 0 or 1 depending on calculation.
     */
int* getBits(unsigned int num){
    int *Arr = new int[16];     
    for(int i = 0; i < 16; i++){
        Arr[i] = num % 2;
        num = num >> 1;
    }
    return Arr;
}


int main(){
    int *temp;          //placeholder array to hold numbers as they are read in
    int num;            //used to read in number
    int total = 0;      //keeps track of total assignments from file
    
    ifstream fin;
    ofstream fout;
    openFiles(fin, fout);   
    fout << "Kevin McNeil Jr." << endl;
    
    while(!fin.eof()){  //while loop to loop thru until end of file
        total++;
        fin >> num;     //read in num
        fout << "ASSIGNMENT #" << total << " OPTIONS" << endl << endl;
        temp = getBits(num);
        int i = 0;      

        while(i < 16){  //while loop to assess bits and return specifications for assignment
          switch(i){
            case 0: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment has a time limit." << endl;
                i++;
                break;
                }

            case 1: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment may be printed." << endl;
                i++;
                break;
                }

            case 2: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment's questions will be scrambled." << endl;
                i++;
                break;
                }

            case 3: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment is password protected." << endl;
                i++;
                break;
                }

            case 4: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "The questions on this assignment will have their point values shown." << endl;
                i++;
                break;
                }

            case 5: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "The questions on this assignment will have their titles shown." << endl;
                i++;
                break;
                }

            case 6: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "References for this assignment will be shown." << endl;
                i++;
                break;
                }

            case 7: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "Access to external links is allowed." << endl;
                i++;
                break;
                }

            case 8: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment will have formulas shown." << endl;
                i++;
                break;
                }

            case 9: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment will only allow one attempt." << endl;
                i++;
                break;
                }
            
            case 10: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment will require correct letter cases." << endl;
                i++;
                break;
                }

            case 11: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "This assignment will allow late submissions." << endl;
                i++;
                break;
                }

            case 12: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "Access to the ebook will be allowed on this assignment." << endl;
                i++;
                break;
                }

            case 13: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "Access to check your work will be allowed on this assignment." << endl;
                i++;
                break;
                }

            case 14: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "Correct spacing and punctuation will be required on this assignment." << endl;
                i++;
                break;
                }

            case 15: 
                if(temp[i] == 0){
                i++;
                break;
            }else{
                fout << "You may ask the instructor questions during this assignment." << endl;
                i++;
                break;
                }
        
            }
            
        }
        fout << endl << endl;
    }
    return 0;
}