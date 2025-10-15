#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

istream& operator >>(istream& is, Power_supply& _ps){

	string _str;
	is >> _str;

	if(_str.compare("GASOLINE")) {
		_ps = GASOLINE;
	} else if(_str.compare("HYBRID")) {
		_ps = HYBRID;
	} else if(_str.compare("DIESEL")) {
		_ps = DIESEL;
	} else if(_str.compare("METHANE")) {
		_ps = METHANE;
	} else if(_str.compare("ELECTRIC")) {
		_ps = ELECTRIC;
	} else {
		_ps = NOTHNG;
	}

	return is;
}

ostream& operator <<(ostream& os, const Laboratory& _lab){
	
	os << "-------------------------------------------" << endl
     << "Lab " << "ID: " << _lab.ID_laboratory << endl
     << "-------------------------------------------" << endl;
	
		 return os;
}

ostream& operator <<(ostream& os, const Mechanic& _mech){
	
	os << "-------------------------------------------" << endl
		 << "Mechanic " << "ID: " << _mech.ID_employee << endl
		 << "-------------------------------------------" << endl
		 << _mech.name_employee << " "
		 << _mech.lastname_employee << ", "
		 << _mech.age_employee;

	return os;
}

ostream& operator <<(ostream& os, const Rental& _ren){
	
	os << "-------------------------------------------" << endl
     << "Rental " << "ID: " << _ren.ID_rental << endl
     << "-------------------------------------------" << endl;
	
	return os;
}

vector<Car> init_cars(){

	ifstream _in_file;
	_in_file.open("./dataSet/cars.txt", ios::in);

	vector<Car> cars;

	string id;
	long double price;
	int dd, mm, yyyy;
	Power_supply ps;
	string color;
	int x, y, z;
	string model;
	string sc;

	while (_in_file >> id 
				   				>> price 
				   				>> dd
				   				>> mm
				   				>> yyyy
				   				>> ps 
				   				>> color 
				   				>> x
				   				>> y
				   				>> z 
				   				>> model
								  >> sc) {

	  Date yop(dd, mm, yyyy);
	  vector<int> dim = {x, y, z};
	  Car car(id, price, yop, ps, color, dim, model);
		cout << car << endl;

		cars.push_back(car);
	}

	_in_file.close();
	return cars;
}

vector<Laboratory> init_labs(const vector<Car>& _cars){

	srand((unsigned) time(0));

	ifstream _in_file_lab;
	ifstream _in_file_mechanic;
	_in_file_lab.open("./dataSet/labs.txt", ios::in);
	_in_file_mechanic.open("./dataSet/mechanics.txt", ios::in);

	
	vector<Laboratory> labs;

	string ID_lab;
	int n; //cars num
	int m; //mechenics num
	string sc; //;

	string ID_employee;
  string name_employee;
  string lastname_employee;
  int age_employee;

	while (_in_file_lab >> ID_lab 
											>> n 
											>> m
											>> sc){
		Laboratory lab(ID_lab);

		cout << lab << endl;

		cout << "CARS IN LAB" << endl;
		while(n-- > 0) {
			int i = rand() % _cars.size();
			lab.add_car(_cars.at(i));
			cout << _cars.at(i);
		}

		cout << "MECHANICS IN LAB" << endl;
		while(m-- > 0) {
			_in_file_mechanic >> ID_employee
								 	 			>> name_employee 
								 	 			>> lastname_employee
								 	 			>> age_employee
								 	 			>> sc;
			Mechanic m(ID_employee, name_employee, lastname_employee, age_employee);
			lab.add_mechanic(m);

			cout << m << endl;
		}

		labs.push_back(lab);
	}

	_in_file_lab.close();
	_in_file_mechanic.close();

	return labs; 
}

vector<Shop> init_shops(){

	ifstream _in_file;
	_in_file.open("./dataSet/shops.txt", ios::in);

	vector<Shop> shops;

	_in_file.close();
	return shops; 
}

vector<Rental> init_rentals(){

	ifstream _in_file;
	ifstream _in_rental_cars;
	_in_file.open("./dataSet/rentals.txt", ios::in);
	_in_rental_cars.open("./dataSet/rental_cars.txt", ios::in);

	vector<Rental> rentals;

	string id_ren;
	int n; //rental_cars

	//car info
	string id;
	long double price;
	int dd, mm, yyyy;
	Power_supply ps;
	string color;
	int x, y, z;
	string model;
	string sc;
	

	while(_in_file >> id_ren >> n >> sc){
		Rental ren(id_ren);
		cout << ren;

		cout << "CARS IN RENTAL" << endl;
		while(n-- > 0){
			_in_rental_cars >> id 
				   						>> price 
				   						>> dd
				   						>> mm
				   						>> yyyy
				   						>> ps 
				   						>> color 
				   						>> x
				   						>> y
				   						>> z 
				   						>> model
								  		>> sc;
			Date yop(dd, mm, yyyy);
	  	vector<int> dim = {x, y, z};
	  	Car car(id, price, yop, ps, color, dim, model);

			cout << car;

			ren.add_car(car);
		}

		rentals.push_back(ren);
	}

	_in_file.close();
	_in_rental_cars.close();

	return rentals; 
}