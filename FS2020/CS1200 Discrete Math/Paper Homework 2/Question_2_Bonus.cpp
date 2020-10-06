#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned long long upperLimit = 18446744073709000000; //maximum value for type
    char limitChoice; //The user's choice on whether to enter a limit

    bool isMagic;
    bool counterFound = false;
    unsigned long long userNum = 1; //the number being tested, starts at 1
    unsigned long long num; //used for calculations on userNum

    //introductory message
    cout << endl << "Welcome to the Magic Number Counter Example searcher!" 
         << endl << endl << "This program searches all numbers from 1 to a "
         << "given limit in search" << endl << "of numbers that serve as counter examples "
         << "to the Collatz Conjecture." << endl << "Set a limit or let the program run "
         << "until it finds a counter example!" << endl
         << endl << "Would you like to enter an upper limit? (y/n)" << endl;

    cin >> limitChoice;

    //if no, program runs until max value for type reached
    if((limitChoice == 'y') || (limitChoice == 'Y'))
    {
        cout << endl << "Enter a limit: ";
        cin >> upperLimit;
    }

    cout << endl << "Search in progress..." << endl 
         << endl << "Numbers checked:" << endl;

    while((!counterFound) && (userNum <= upperLimit))
    {
        if(userNum >= 10000000) //outputs milestones (starting at 10 million)
        { 
            if(userNum % 1000000000000 == 0)
                cout << userNum / 1000000000000 << " trillion" << endl;

            else if(userNum % 1000000000 == 0 )
                cout << userNum / 1000000000 << " billion" << endl;

            else if(userNum % 10000000 == 0)
                cout << userNum / 1000000 << " million" << endl;
        }

        int i = 1; //calculation step number

        num = userNum;

        //if calculation exceeds 3000 steps, number assumed to not be magic
        while((num != 1) && (i < 3000))
        {
            if(num % 2 == 0) { num /= 2; }

            else { num = num * 3 + 1; }
        
            i++;
        } 

        isMagic = ( num == 1 ? true : false );

        if(!isMagic) //counter example
        {
            counterFound = true;
            cout << "Counter example found: " << userNum << endl;
        }

        userNum++;
    }
 
    cout << endl << "Upper Limit Reached" << endl << "Search ended" << endl << endl;

    return 0;
}