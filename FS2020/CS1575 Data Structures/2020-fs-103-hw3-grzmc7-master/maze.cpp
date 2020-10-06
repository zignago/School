
#include "maze.h"

//map elements
const char EMPTY = ' ';
const char VISITED = '@';
const char WALL = '|';
const char START = 'N';
const char END = 'E';


void get_identity(string &my_id)
{
    my_id = "grzmc7";
}


string * build_matrix(int rows)
{
    string * matrix;
    matrix = new string[rows];

    return matrix;
}


void fill_matrix(string *matrix, int rows)
{
    string line;

    getline(cin, line); //collects newline after user enters row

    //collects user input for each row
    for(int i = 0; i < rows; i++)
    {
        getline(cin, line);
        matrix[i] = line;
    }

    return;
}


void print_matrix(string *matrix, int rows)
{
    for(int i = 0; i < rows; i++)
        cout << matrix[i] << endl;

    return;
}


void delete_matrix(string *&matrix)
{
    //deletes the array of pointers
    delete[] matrix;

    return;
}


void find_start(string *matrix, int rows, int &row, int &col)
{
    for(int i = 0; i < rows; i++)
    {
        for(long unsigned int j = 0; j < matrix[i].length(); j++)
        {
            if(matrix[i][j] == START)
            {
                row = i;
                col = j;

                return; //start found
            }
        }
    }
    
    //No starting coordinates found
    cerr << endl << "Error: Map does not have a starting point" << endl ;
    throw; //terminates program
}


bool find_exit(string *matrix, int row, int col)
{
    //reached destination
    if(at_end(matrix, row, col))
    { 
        return true; 
    }

    else
    {
        //NORTH
        if (valid_move(matrix, row, col, "NORTH"))
        {
            if(!at_end(matrix, row-1, col))
                matrix[row-1][col] = VISITED;

            if(find_exit(matrix, row-1, col))
                return true;
            
            else
                matrix[row-1][col] = EMPTY;
        }

        //SOUTH
        if (valid_move(matrix, row, col, "SOUTH"))
        {
            if(!at_end(matrix, row+1, col))
                matrix[row+1][col] = VISITED;

            if(find_exit(matrix, row+1, col))
                return true;

            else
                matrix[row+1][col] = EMPTY;
        }

        //EAST
        if (valid_move(matrix, row, col, "EAST"))
        {
            if(!at_end(matrix, row, col-1))
                matrix[row][col-1] = VISITED;

            if(find_exit(matrix, row, col-1))
                return true;

            else
                matrix[row][col-1] = EMPTY;
        }

        //WEST
        if (valid_move(matrix, row, col, "WEST"))
        {
            if(!at_end(matrix, row, col+1))
                matrix[row][col+1] = VISITED;

            if(find_exit(matrix, row, col+1))
                return true;

            else
                matrix[row][col+1] = EMPTY;
        }
    }

    //no viable path
    return false;
}


bool at_end(string *matrix, int row, int col)
{
    if(matrix[row][col] == END)
        return true;
    
    return false;
}


bool valid_move(string *matrix, int row, int col, string direction)
{
    char mapChar; //character at given coordinate

    switch(direction[0]) //first letter of direction
    {
        case 'N': //NORTH
            mapChar = matrix[row-1][col];
            break;

        case 'S': //SOUTH
            mapChar = matrix[row+1][col];
            break;

        case 'E': //EAST
            mapChar = matrix[row][col-1];
            break;

        case 'W': //WEST
            mapChar = matrix[row][col+1];
            break;
    }

    if(mapChar == WALL || mapChar == VISITED || mapChar == START) 
        return false; //invalid move

    return true; //valid move
}