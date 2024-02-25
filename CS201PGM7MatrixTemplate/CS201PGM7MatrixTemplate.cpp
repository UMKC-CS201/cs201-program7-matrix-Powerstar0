// PROGRAM: CS201PGM7Matrix
// NAME: Johnny Diep
// DATE: 02/25/2024
// Purpose: Read various matrices and calculate several properties.

#include <iostream>
#include "Matrix.h"
#include <string>
using namespace std;


int main()
{


    cout << "\n\n***************************************************" << endl;
    cout << "***************************************************" << endl;
    cout << "\nWELCOME TO MY MATRIX PROCESSOR\n";
    cout << "\n***************************************************" << endl;

    //open file & check it is open
    ifstream inStream;
    inStream.open(R"(C:\Users\Johnny\CLionProjects\cs201-program7-matrix-Powerstar0\CS201PGM7MatrixTemplate\data.txt)"); //String literal from CLION
    if (!inStream.is_open()){
        cout << "Error opening files" << endl;

        return 1;
    }
    //if so, loop through each record in the input file:
    //   load the new matrix
    //   if load is successful (return == 1)
    //      process the matrix
    int vector_number = 1;
    while (inStream.good()) {
        int vectorSize;
        inStream >> vectorSize;
        vector<vector<int>> matrix;
        //resizes vector
        matrix.resize(vectorSize);
        for (int i = 0; i < vectorSize; ++i) {
            matrix.at(i).resize(vectorSize);
        }
        //loads matrix if its valid
        if (loadMatrix(inStream, matrix, vectorSize, vector_number) == 1) {
            //printVector(matrix, vectorSize);
            processMatrix(matrix, vectorSize, vector_number);
        }
        //Increments vector number
        vector_number++;
    }

    //close the input file
    inStream.close();
    //wait to view any output printed to the screen (if needed)
    string hold;
    cin >> hold;
}



//[1 1 0]
//[0 1 0]
//[1 0 1]
//For i = 0 to singe-1
//  clear 1-d vector
//  for j=0 to singe-1
//      load 110
//      push onto v<v<int>>

//Reflexive all diagonal = 1
//Symmetric [i][j] == [j][i]
//transitive if
 