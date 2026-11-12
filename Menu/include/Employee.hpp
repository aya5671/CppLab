#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
using namespace std;

class Employee {
private:

    string name;
    int age;

public:

    Employee();
    void setEmployee(string n, int a);
    string getName() const;
    int getAge() const;
};

#endif