#include "employee.h"
#include<iostream>
#include<string>
using namespace std;

Employee::Employee(): ID_employee(""), name_employee(""), lastname_employee(""), age_employee(0){
}

Employee::Employee(const string _id, const string _name, const string _last, const int _age): ID_employee(_id), name_employee(_name), lastname_employee(_last), age_employee(_age){
}

Employee::Employee(const Employee& _empl): ID_employee(_empl.ID_employee), name_employee(_empl.name_employee), lastname_employee(_empl.lastname_employee), age_employee(_empl.age_employee){
}