#ifndef MENU_HPP
#define MENU_HPP

#include "Employee.hpp"

class Menu {

private:

    static const int MAX = 5;
    Employee employees[MAX];

    int count;
    int selected;
    void displayMenu();

public:

    Menu();
    void addEmployees();
    void displayEmployees();
    void run();
};

#endif