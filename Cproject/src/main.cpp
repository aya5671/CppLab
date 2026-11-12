#include <iostream>
#include "../include/mystring.h"

using namespace std;
using namespace stringmanipulation;

int main (){
    char a[] = "cat";
    cout << To_Upper(a)<< endl;

    char b[] = "CAT";
    cout << To_Lower(b) <<endl;

    char x[] = "hello";
    char y[] = "hello";

    Compare_Length(x,y);
    Compare_Length(a,y);

    Compare_Value(x, y);
    Compare_Value (a,y);

    char * z = Copy_String(x);
    cout << z <<endl;
    delete[] z;
    z = nullptr;

    return 0;
}