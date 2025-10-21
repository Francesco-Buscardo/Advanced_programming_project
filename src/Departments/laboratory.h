#ifndef __LABORATORY_H__
#define __LABORATORY_H__

#include "Department.h"
#include "../Staff/mechanic.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Laboratory: public Department{
	
	static int      count_labs;
	int             ID_laboratory;
	set<Car*>       under_maintenance_cars;
	set<Employee*>  available_mechanics;    //available mechanics for repairing cars

	public: 
		Laboratory();
		Laboratory(const Laboratory& _lab);
		~Laboratory() override;
	
		friend ostream& operator <<(ostream& so, const Laboratory& _lab);

		void add_car                (Car* _car)       override; //add car to cars
		void remove_car             (Car* _car)       override; //remove car cars
		void add_employee           (Employee* _empl) override; //add an employee to employees
    void remove_employee        (Employee* _empl) override; //remove an employee from employees
		Car* find_car               (Car* _car)       override; //find a car in cars
		void add_car_to_maintenance (Car* _car);                //add car to under_maintenance_cars
		void fix_car                (Car* _car);                //remove car from under_maintenance_cars
		void add_mechanic           (Employee* _mech);					//add mechanic to available_mechanics
		void remove_mechanic        (Employee* _mech);					//rmeove mechanic to available_mechanics	
};

ostream& operator <<(ostream& os, const Laboratory& _lab);

#endif