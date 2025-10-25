#ifndef __LABORATORY_H__
#define __LABORATORY_H__

#include "Department.h"
#include "../Staff/mechanic.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

class Car;

class Laboratory: public Department{
	
	static int      count_labs;
	int             ID_laboratory;
	set<Employee*>  available_mechanics;    //available mechanics for repairing cars

	public: 
		Laboratory();
		Laboratory(const Laboratory& _lab);
		~Laboratory() override;
	
		virtual ostream& print_operator (ostream& os) const;
		friend  ostream& operator <<    (ostream& os, const Laboratory& _lab);

		void fix_car                (Car* _car);                        //remove car from under_maintenance_cars
		void add_mechanic           (Employee* _mech);  					      //add mechanic to available_mechanics
		void remove_mechanic        (Employee* _mech);  					      //rmeove mechanic to available_mechanics
	  int  get_ID                 ()                 const override;
};

ostream& operator <<(ostream& os, const Laboratory& _lab);

#endif