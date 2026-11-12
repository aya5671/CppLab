#include "../include/printer.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <unistd.h>
#include <termios.h>

using namespace std;
using namespace advprint;


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


struct Employee{
    string name;
    int age;
};


struct EmployeeArray{
    Employee* employees;
    int count;
    int size;
};


void resizeArray(EmployeeArray& data){
    int newSize = data.size * 2;

    Employee* newEmployees = new Employee[newSize];

    for (int i = 0; i < data.count; i++){
        newEmployees[i] = data.employees[i];
    }

    delete[] data.employees;
    data.employees = newEmployees;
    data.size = newSize;

    cout << "Size: " << data.size << endl;
}


void addEmployees(EmployeeArray& data)
{
    string name;
    int age=0;
    clear();

    while (true){

        cout << "Enter employee name or done: ";
        getline(cin, name);

        if (name == "done"){
            cout << "Done" << endl;
            break;
        }

        // if (name.empty()){
        //     break;
        // }
        
        while (true){
            cout << "Enter employee age: ";
            cin >> age;
            if (age >= 18){
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                break;
            }
            cout << "Invalid age" << endl;
        }

        data.employees[data.count].name = name;
        data.employees[data.count].age = age;
        data.count++;

        cout << "Employee added" << endl;

        if (data.count == data.size){
            resizeArray(data);
        }
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


void displayEmployees(EmployeeArray& data){
    clear();
    cout << "EMPLOYEES" <<endl;

    for (int i = 0; i < data.count; i++){
        cout << "Employee #" << i + 1 << endl;
        cout << "Name: " << data.employees[i].name << endl;
        cout << "Age: " << data.employees[i].age << endl;
        cout << endl;
    }

    cout << "# of employees: " << data.count << endl;
    cout << "Size Available: " << data.size << endl;

//esc
    while (true){
        char key = getch_linux();
        if (key == '\033'){
            break;
        }
    }
}


void displayMenu(int selected){

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


void runMenu(EmployeeArray& data){
    int selected = 0;
    char key1;
    char key2;
    char key3;
    bool running = true;

    while (running){
        displayMenu(selected);
        key1 = getch_linux();

        if (key1 == '\033'){
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
        else if (key1 == '\n' || key1 == '\r'){
            switch (selected){
                case 0: //new
                    addEmployees(data);
                    break;
            
                case 1: //display
                    displayEmployees(data);
                    break;
            
                case 2: //exit
                    running = false;
                    clear();
                    break;
            }
        }
    }
}


int main()
{
    EmployeeArray data;
    data.size = 5;
    data.count = 0;
    data.employees = new Employee[data.size];

    runMenu(data);

    delete[] data.employees;
    data.employees = nullptr;

    return 0;
}