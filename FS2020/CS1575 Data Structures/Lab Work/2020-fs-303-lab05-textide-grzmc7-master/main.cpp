#include <iostream>
#include "funcs.h"
#include "TrianglePrinter.h"

using namespace std;

int main()
{
    TrianglePrinter t;
    int rowNum = 0;

    for(unsigned int i = 0; i < 10; i++)
    {
        cout << factorial(i) << endl;
    }

    while(rowNum < 7)
    {
        for(int i = 0; i < rowNum + 1; i++)
            t.add(combination(rowNum, i));
        
        t.newrow();
        rowNum++;
    }

    t.print();

    return 0;
}
