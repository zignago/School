
#include "maze.h"

int main()
{
    int numRows;
    cin >> numRows;

    int mapNum = 0;

    while(numRows) //terminates when user enters 0 for row
    {
        //map creation
        string * matrix = build_matrix(numRows);
        fill_matrix(matrix, numRows);

        //starting coordinates
        int row = -1, col = -1;
        find_start(matrix, numRows, row, col);

        cout << endl << "Map " << mapNum << " -- ";

        //recursive loop
        if(find_exit(matrix, row, col))
            cout << "Solution found:" << endl;
        
        else
            cout << "No solution found:" << endl;       

        print_matrix(matrix, numRows);
        
        delete_matrix(matrix); 

        cin >> numRows;

        mapNum++;
    }

    return 0;
}
