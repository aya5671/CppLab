#include "../include/Menu.hpp"
#include "../include/printer.hpp"
#include <iostream>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <termios.h>
#include <limits>

using namespace std;
using namespace advprint;

// i used AI for some help in the getch linux parts and some of the inputs from the menu
// since it was causing problems :)

char getch_linux()
{
    char buf = 0;

    struct termios old_settings;
    struct termios new_settings;

    tcgetattr(STDIN_FILENO, &old_settings);

    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);

    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    read(STDIN_FILENO, &buf, 1);

    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return buf;
}

Menu::Menu()
{
    count = 0;
    selected = 0;
}

void Menu::displayMenu(){
    clear();
    writeAt(8, 2, "MENU", Color::red);

    if (selected == 0){
        writeAt(8, 5, "->", Color::yellow);
        writeAt(12, 5, "New", Color::yellow);
    }
    else{
        writeAt(8, 5, "  ", Color::white);
        writeAt(12, 5, "New", Color::white);
    }

    if (selected == 1){
        writeAt(8, 7, "->", Color::yellow);
        writeAt(12, 7, "Display", Color::yellow);
    }
    else{
        writeAt(8, 7, "  ", Color::white);
        writeAt(12, 7, "Display", Color::white);
    }

    if (selected == 2){
        writeAt(8, 9, "->", Color::yellow);
        writeAt(12, 9, "Exit", Color::yellow);
    }
    else{
        writeAt(8, 9, "  ", Color::white);
        writeAt(12, 9, "Exit", Color::white);
    }

    fflush(stdout);
}

void Menu::addEmployees()
{
    string name;
    int age=0;

    clear();

    while (true){
        if (count == MAX){
            cout << endl;
            cout << "Full Storage" << endl;
            break;
        }

        cout << "Enter employee name or done : ";
        //cin >> name;
        getline(cin, name);

        if (name == "done" ) {
            cout << endl;
            cout << "Done" << endl;
            break;
        }

        // if (name.empty()){
        //     break;
        // }

    while (true){
        cout << "Enter employee age: ";
        cin >> age;

        if(age >= 18){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cout << "Invalid Age" << endl;
    }

        employees[count].setEmployee(name, age);
        count++;
        cout << "Employee added" << endl;
    }

//esc
    while (true){
        char key = getch_linux();

        if (key == '\033'){
            break;
        }
    }
}

void Menu::displayEmployees(){
    clear();
    cout << "EMPLOYEES" << endl;

    for (int i = 0; i < count; i++){
        cout << "Employee #" << i + 1 << endl;
        cout << "Name: " << employees[i].getName() << endl;
        cout << "Age: " << employees[i].getAge() << endl;
        cout << endl;
    }

//esc
    while (true){
        char key = getch_linux();
        if (key == '\033'){
            break;
        }
    }
}

void Menu::run(){

    int selected = 0;
    char key1;
    char key2;
    char key3;
    bool running = true;

    while (running){
        displayMenu();
        key1 = getch_linux();

        if (key1 == '\033') {
            key2 = getch_linux();

            if (key2 == '['){
                key3 = getch_linux();

                switch (key3){
                    case 'A': //up
                        selected--;

                        if (selected < 0){
                            selected = 2;
                        }
                        break;

                    case 'B': //down
                        selected++;

                        if (selected > 2){
                            selected = 0;
                        }
                        break;
                }
            }
        }
        else if (key1 == '\n' || key1 == '\r')
        {
            switch (selected)
            {
                case 0: //new
                    addEmployees();
                    break;

                case 1: //display
                    displayEmployees();
                    break;

                case 2: //exit
                    running = false;
                    clear();
                    break;
            }
        }
    }
}