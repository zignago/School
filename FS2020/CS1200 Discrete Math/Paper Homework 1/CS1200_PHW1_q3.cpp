#include <iostream>
using namespace std;

int main()
{
    bool p, q, r, s, t, u, w;
    
    s = false;
    t = (!s ? false : true);
    
    if(!t) { w = true; }
    if(!s) { q = false; r = true; }
    
    p = (!q ? false : true);
    u = ((!p && r) ? true : false);

    bool Conclusion = (u && w);

    cout << ( Conclusion ? "true" : "false" );

    return 0;
}