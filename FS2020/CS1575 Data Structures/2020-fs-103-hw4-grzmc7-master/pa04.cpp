/* Sample main (this file is not a unit test!)

 * This file is for developing your own tests to make sure that your code is
    runnable for different use cases.

 * std::vector is included in the code below to show you how your types should
    behave. Feel free to use that for debugging purposes.


 * Make sure to test your vector with multiple types!!

 * In the main function (or multiple mains) you should write your own
    "unit tests" for each function; one suggestion may be one main per function.
    Multiple Main Methods: http://www.cplusplus.com/forum/beginner/46664/
*/

// USE THIS TO TEST, BUT REMOVE LATER TO VALIDATE YOUR OWN IMPLEMENTAION
//#include <vector>
//#include <iostream>
//using namespace std;

// Uncomment this to test with your own list implementation
#include "MyVector.h"

int main()
{
    // Uncomment this to test with your own list implementation
    MyVector<int> v;

    //MyVector<int> gr = v; //copy constructor called here
    //std::vector<int> v;

    cout << v.size() << endl;
    v.push_back(4000);  
    cout << v.at(0) << endl;

    cout << v.capacity() << endl; //Error: "Note 2" edge case

    v.reserve(10);
    cout << v.capacity() << endl;

    v.push_back(200);
    v.push_back(100);

    v.insert(v.begin(), 3);
    v.insert(v.end(), 20);

    v.reserve(200);

    MyVector<char> c;

    cout << c.size() << endl;
    c.push_back('a');  
    cout << c.at(0) << endl;

    c.insert(c.end(), 'z');

    c.assign(20, 'L');

    MyVector<string> s;

    cout << s.size() << endl;
    s.push_back("ohhebouttadoit");  
    cout << s.at(0) << endl;

    s.insert(s.end(), "ohshithereitcome");

    s.assign(20, "dafuqqqqq yunglean?");

    s.insert(s.end(), "ohh right right...");

    //gr.push_back(100);

    //v = gr;

    //v.clear();

    v.assign(5, 7);

    MyVector<int> gr = v; //copy constructor called here

    //MySwap(gr, v);

    // These below look like iterators, but are really just integers.
    // We are not making you re-implement iterators themselves.

    int j = 0;

    for(auto i = s.begin(); i < s.end(); i++)
    {
        cout << j << ": (s) "; //I added this

        cout << s.at(j) << endl;
        j++;
    }

    cout << endl << endl; //I added this

    j = 0;

    for(auto i = 0; i < v.size(); i++)
    {
        cout << v[j] << endl;
        j++;
    }

    return 0;
}
