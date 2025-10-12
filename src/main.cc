#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream& operator >>(istream& is, Power_supply& _ps) {

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

vector<Laboratory> init_labs(){

	ifstream _in_file;
	_in_file.open("./dataSet/labs.txt", ios::in);
	
	vector<Laboratory> labs;

	_in_file.close();
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
	_in_file.open("./dataSet/rentals.txt", ios::in);

	vector<Rental> rentals;

	_in_file.close();
	return rentals; 
}