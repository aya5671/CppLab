#include <cmath>
#include "../include/mystring.h"
#include <iostream>
using namespace std;
namespace stringmanipulation{

     char * To_Upper (char * a){
        
        int i =0;

        while( a[i] != '\0'){
            if(a[i]>='a' && a[i]<='z'){
                a[i]-=32;
            };
            i++;
        };

        return a;
    };  

     char * To_Lower (char * a){

        int i = 0;

        while(a[i] != '\0'){
            if(a[i]>='A' && a[i]<= 'Z'){
                a[i]+=32;
            };
            i++;
        };

        return a;
    };

    void Compare_Length(char *a, char *b)
    {
        int a_length = 0;
        int b_length = 0;

        while (a[a_length] != '\0'){
            a_length++;
        };

        while (b[b_length] != '\0'){
            b_length++;
        };

        if (a_length > b_length){
            cout << "The first string is longer in length." << endl;
        }
        else if (b_length > a_length){
            cout << "The second string is longer length." << endl;
        }
        else{
            cout << "Both strings are equal in length." << endl;
        };
    };

    void Compare_Value(char *a, char *b)
    {
        int i = 0;

        while (a[i] != '\0' || b[i] != '\0'){
            if (a[i] != b[i]){
                cout << "The strings arent equal in value." << endl;
                return;
            };
            i++;
        };
        cout << "The strings are equal in value." << endl;
    };
    
    char * Copy_String(char * a){

        int i =0;

        while (a[i] != '\0'){
            i++;
        };

        char * b = new char [i+1];

        for (int x = 0; x<=i; x++){
            b[x] = a[x];
        };

        return b;
    };
}