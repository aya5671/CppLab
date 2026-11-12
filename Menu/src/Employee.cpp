#include "../include/Employee.hpp"

Employee::Employee() {

    name = "";
    age = 0;
}

void Employee::setEmployee(std::string n, int a) {

    name = n;
    age = a;
}

std::string Employee::getName() const {

    return name;
}

int Employee::getAge() const {

    return age;
}