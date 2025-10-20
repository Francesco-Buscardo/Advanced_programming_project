#ifndef __LABORATORY_H__
#define __LABORATORY_H__

#include "Department.h"
#include "../Staff/mechanic.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Laboratory: public Department{
	
	static int     count_labs;
	int            ID_laboratory;
	set<Car>       under_maintenance_cars;
	set<Employee*> available_mechanics;    //available mechanics for repairing cars

	public: 
		Laboratory();
		Laboratory(const Laboratory& _lab);
		~Laboratory() override;
	
		friend ostream& operator <<(ostream& so, const Laboratory& _lab);

		bool add_car                (const Car& _car)       override; //add car to cars
		bool remove_car             (const Car& _car)       override; //remove car cars
		bool add_employee           (const Employee& _empl) override; //add an employee to employees
    bool remove_employee        (const Employee& _empl) override; //remove an employee from employees
		Car  find_car               (const Car& _car)       override; //find a car in cars
		bool add_car_to_maintenance (Car& _car);                      //add car to under_maintenance_cars
		bool fix_car                (Car& _car);                      //remove car from under_maintenance_cars
		bool add_mechanic           (const Mechanic& _mech);					//add mechanic to available_mechanics
		bool remove_mechanic        (const Mechanic& _mech);					//rmeove mechanic to available_mechanics	
};

#endif