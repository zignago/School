using namespace std;
#include <iostream>

//the number to be tested for "magicness"
const unsigned long long int MAGIC_NUM = 93571393692802302;

int main()
{
    bool isMagic;
    unsigned long long int num = MAGIC_NUM;

    int i = 1; //records step number for output

    while(num != 1)
    {
        //outputs each step, starting at initial value
        cout << endl << "Step " << i << ": " << num;

        if(num % 2 == 0) { num /= 2; }

        else { num = num * 3 + 1; }

        i++;
    } 

    //outputs final step (num should equal 1)
    cout << endl << "Step " << i << ": " << num; 

    isMagic = ( num == 1 ? true : false );

    //results
    cout << endl << endl << "total steps elapsed: " << i 
         << endl << MAGIC_NUM << (isMagic ? " is" : " is not")
         << " a magic number." << endl << endl;

    return 0;
}