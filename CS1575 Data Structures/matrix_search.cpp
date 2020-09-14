//File: matrix_search.cpp
//Programmer: Gian Zignago
//Description: contains function information for the matrix word search program

#include "matrix_search.h"


void get_identity(string &my_id)
{
    my_id = "grzmc7";
}


char ** build_matrix(int rows, int cols)
{
    char **newMatrix;
    newMatrix = new char*[rows];

    //fill each sub-array
    for(int i = 0; i < rows; i++)
    {
        newMatrix[i] = new char[cols];
    }

    return newMatrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
    //each row
    for(int i = 0; i < rows; i++)
    {
        //each column
        for(int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    return;
}


void print_matrix(int rows, int cols, char **matrix)
{
    //each row
    for(int i = 0; i < rows; i++)
    {
        //each column
        for(int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << ' ';
        }

        cout << endl;
    }

    return;
}


void delete_matrix(int rows, char **matrix)
{
     //free each sub-array
    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    return;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{

    //These arrays store the eight directions to search arround a character
    const short x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; //Row Direction (N/S)
    const short y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; //Column Direction (E/W)


    //scans each row
    for(int i = 0; i < rows; i++)
    {
        //scans each column
        for(int j = 0; j < cols; j++)
        {
            //searches for first letter
            if(matrix[i][j] == word[0])
            {

                for(int direction = 0; direction < 8; direction++)
                {
                    int k; //number of consecutive chars matched
                    int rSearch = i + x[direction]; //row to search
                    int cSearch = j + y[direction]; //column to search

                    int endX, endY; //current endpoint


                    for (k = 1; k < word.length(); k++) 
                    {
                        endX = rSearch;
                        endY = cSearch;
                        
                        //prevents "walking-off" the array
                        if (rSearch >= rows || rSearch < 0 || 
                            cSearch >= cols || cSearch < 0)
                        {
                            break;
                        }

                        //if the selected character does not match the word
                        if (matrix[rSearch][cSearch] != word[k])
                        {
                            break;
                        }

                        rSearch += x[direction];
                        cSearch += y[direction]; 
                    }


                    if(k == word.length())
                    {
                        //starting coords
                        sol[0] = i;
                        sol[1] = j;

                        //endpoint coords
                        sol[2] = endX;
                        sol[3] = endY;

                        return; //match found
                    }


                }
            }
        }
    }

    return; //no match found

}

