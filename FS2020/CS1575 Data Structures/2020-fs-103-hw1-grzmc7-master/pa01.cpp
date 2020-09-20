//File: pa01.cpp
//Programmer: Gian Zignago
//Description: This program takes in a matrix via standard input
//             and searches it for a specified word

#include "matrix_search.h"


int main()
{
    short numCases;    //number of matrix/word combinations to be input
    short userRows;    //number of rows in the given data set
    short userCols;    //number of columns in the given data set
    string targetWord; //word to be searched for


    cin >> numCases;


    //each loop is an independent case
    for(int i = 0; i < numCases; i++)
    {

        int sol [4] = {}; //coordinates of start and end points of found word
                          //initialized with four zeroes for each case


        //user input and matrix creation
        cin >> userRows >> userCols;

        char **userMatrix = build_matrix(userRows, userCols);

        fill_matrix(userRows, userCols, userMatrix);

        cin >> targetWord;


        //matrix search
        matrix_search(sol, targetWord, userRows, userCols, userMatrix);


        //search result output
        cout << "Searching for \"" << targetWord << "\" in matrix " << i 
             << " yields:" << endl;


        //if sol filled with all zeroes, signifies that word was not found
        if((sol[0] == sol[1]) && (sol[0] == sol[2]) && (sol[0] == sol[3]))
        {
            cout << "The pattern was not found." << endl << endl;
        }

        else //word found
        {
            cout << "Start pos:(" << sol[0] << ", " << sol[1] << ')'
                 << "to End pos:(" << sol[2] << ", " << sol[3] << ')'
                 << endl << endl;
        }

        //deallocation of data stored in userMatrix
        delete_matrix(userRows, userMatrix);

    }

    return 0;

}
