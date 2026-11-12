//use modulus
#include <iostream>
#include "../include/magicBox.hpp"

using namespace std;

int main()
{
    int n=0;

    while(n <= 0 || n % 2 == 0){
        cout << "Please enter an odd number: ";
        cin >> n;
    }
    magicBox(n);

    return 0;
}
