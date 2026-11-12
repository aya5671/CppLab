#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include "../include/magicBox.hpp"

using namespace std;

int Value(int n, int m, int r, int c){
    int row = 0;
    int col = n / 2;

    for (int k = 1; k <= m; k++){
        if (row == r && col == c){
            return k;
        }

        if (k % n == 0){
            row = (row + 1) % n;
        }
        else{
            row = (row - 1 + n) % n;
            col = (col + 1) % n;
        }
    }

    return 0;
}

void magicBox(int n){
    int m;
    int data;

    for (m = 1; m <= n * n; m++){
        cout << "\033[2J\033[H";
        cout << "Magic Box for " << n << ":" << endl;
        cout << endl;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                data = Value(n, m, i, j);

                if (data == 0){
                    // cout << "    ";
                    cout << setw(4) << " ";
                }
                else{
                    // cout << data << "   ";
                    cout << setw(4) << data;
                }
            }
            cout << endl;
        }
        cout << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}