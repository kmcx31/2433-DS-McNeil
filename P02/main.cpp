///////////////////////////////////////////////////////////////////////////////
// Author: Kevin McNeil Jr.
// Email:  shaqmantoo121@yahoo.com
// Title:  Program 2
// Semester: Spring 2020
//
// Description:
//       Uses a pre-created input file to read in set values. 1st value determines whenther
//      to use an Arithmetic seq. or a Geometric seq. 2nd value determines a, 3rd determines d,
//      4th determines length of sequence and 5th/6th determine the summation range.
//
// Usage:
//       Create a sequence and sum up values between a given range.
//
// Files:   main.cpp      :   driver program
//          input.txt     :   input
//          tInput.txt    :   input
//          output.out    :   output
//          tOutput.out   :   output
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//global variables to keep track of input from file
char SEQ;
int A;
int D;
int TERMS;
int SUM;
int MIN;
int MAX;

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
     * int* aSequence
     * 
     * Description:
     *      Puts data set through an arithmetic sequence and returns
     *     an array with ints.
     * 
     * Params:
     *      int *arr   :   Array pointer to input data set
     *      int a      :   1st number in sequence
     *      int d      :   2nd number that adds to previous set
     *      int terms  :   Max number for sequence
     * 
     * Returns:
     *      int*       :   Array with new data set
     */
int* aSequence(int *arr, int a, int d, int terms){
    arr[0] = a;
    for(int i = 1; i < terms; i++){
        arr[i] = a + d;
        a = arr[i];
    }
    return arr;
}     

/**
     * int* gSequence
     * 
     * Description:
     *      Puts data set through a geometric sequence and returns
     *     an array with ints.
     * 
     * Params:
     *      int *arr   :   Array pointer to input data set
     *      int a      :   1st number in sequence
     *      int d      :   2nd number that adds to previous set
     *      int terms  :   Max number for sequence
     * 
     * Returns:
     *      int*       :   Array with new data set
     */
int* gSequence(int *arr, int a, int d, int terms){
    int power = 2;
    arr[0] = a;
    arr[1] = a * d;
    for(int i = 2; i < terms; i++){
        int temp = pow(d, power); 
        arr[i] = a * temp;
        power++;
    }
    return arr;
}

/**
     * int sumValues
     * 
     * Description:
     *      Sums values given from an array within a set
     *     range.
     * 
     * Params:
     *      int *arr   :   Array pointer to input data set
     *      int min    :   Min number for sequence
     *      int max    :   Max number for sequence
     * 
     * Returns:
     *      int        :   Sum of range of ints
     */
int sumValues(int *arr, int min, int max){
    int sum = 0;
    for(int i = min - 1; i < max; i++){
        sum += arr[i];
    }
    return sum;
}

/**
     * void printSequence
     * 
     * Description:
     *      Prints out array of data set as well as Sum 
     *     of a given range.
     * 
     * Params:
     *      int *arr   :   Array pointer to input data set
     *      int min    :   Min number for sequence
     *      ind max    :   Max number for sequence
     *      int sum    :   Sum of range of ints
     *      int terms  :   Total terms in sequence
     *      ofstream&  :   To print to outfile
     * 
     * Returns:
     *      void
     */
void printSequence(int *arr, int min, int max, int sum, int terms, ofstream& fout){
    for(int i = 0; i < terms; i++){
        fout << arr[i] << "    ";
    }
    fout << "\nSum of sequence from " << min << " to " << max << " is " << sum << endl << endl;
}

int main(){
    ifstream fin;   //declare ifstream 
    ofstream fout;  //declare ostream
    openFiles(fin, fout);   

    fout << "Kevin Mcneil Jr." << endl << endl;     //start formatting for ofstream

    int *arr = new int[41];     //declare array with size 41 to hold ints for data sequence

    while(fin >> SEQ){          //while loop that termainates when not reading in input
        SUM = 0;                //reset sum and nSum to 0 to not interfere with new data set
        fin >> A;               //ifstream input
        fin >> D;
        fin >> TERMS;
        fin >> MIN;
        fin >> MAX;

        if(SEQ == 'A'){                         //if input == 'A'
            fout << "Arithmetic sequence: ";    //call aSequence to start sequence
            aSequence(arr, A, D, TERMS);        
        }else if(SEQ == 'G'){                   //else if input == 'G'
            fout << "Geometric sequence: ";     //call gSequence to start sequence
            gSequence(arr, A, D, TERMS);
        }

        SUM = sumValues(arr, MIN, MAX);         //SUM = sum of new sequence with given range

        printSequence(arr, MIN, MAX, SUM, TERMS, fout);     //ofstream sequence with summation

        for(int i = 0; i <= 41; i++){           //reset array to 0's to not interfere with new sequence
            arr[i] = 0;
        }
    }
    return 0;
}