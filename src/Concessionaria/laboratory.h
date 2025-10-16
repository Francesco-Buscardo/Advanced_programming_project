#ifndef LABORATORY_H
#define LABORATORY_H

#include "Concessionaria.h"
#include "../Staff/mechanic.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Laboratory: public Concessionaria{
	
	set<Mechanic> available_mechanics; //available mechanics for repairing cars

	protected:
		string ID_laboratory;
		set<Car> under_maintenance_cars;

	public: 
		Laboratory(string _id);
		Laboratory(const Laboratory& _lab);
		~Laboratory();
	
		friend ostream& operator <<(ostream& so, const Laboratory& _lab);

		void add_car(const Car& _car) override;     //add car to under_maintenace_cars
		void remove_car(const Car& _car) override;  //remove car from under_maintenace_cars
		bool fix_car(Car& _car);
		void add_mechanic(const Mechanic& _mech);
};

#endif