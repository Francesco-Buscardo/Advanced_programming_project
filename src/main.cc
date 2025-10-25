#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
Car* find_by_id(T& _x){

	int tmp_id;

	cout << "Ins id car: " << endl;
	cin  >> tmp_id;

	return _x.find_car_by_ID(tmp_id);
}

template<typename T>
Car* find_by_model(T& _x){

	string tmp_m;

	cout << "Ins model car: " << endl;
	cin  >> tmp_m;

	return _x.find_car_by_model(tmp_m);
}

template<typename T>
void find_car(T& _x){

  int choice;

	cout << "-------------------------------------------" << endl;
	cout << "RICERCA" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1. ID" << endl;
	cout << "2. Modello" << endl;
	cout << "0. Torna indietro" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Scelta: ";
	cin  >> choice;

	while(true){
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << find_by_id(_x) << endl;
			break;
		case 2:
			cout << find_by_model(_x) << endl;
			break;
		default:
			break;
		}
	}
}

template<typename T>
void add_car(T& _x){

	int					c;
	Fuel_t      tmp_ft;
	long double tmp_price;
	string      tmp_m;
	
	cout << "Fuel: " << endl;
	cout << "1. GASOLINE" << endl;
	cout << "2. HYBRID" << endl;
	cout << "3. DIESEL" << endl;
	cout << "4. GPL" << endl;
	cout << "--> ";
	cin  >> c;

	switch(c){
		case 1: 
			tmp_ft = GASOLINE;
			break; 
		case 2: 
			tmp_ft = HYBRID;
			break; 
		case 3: 
			tmp_ft = DIESEL;
			break; 
		case 4: 
		  tmp_ft = GPL;
			break;  
		default: 
			tmp_ft = GASOLINE;
			break;
	}
	Fuel tmp_f(tmp_ft);
	cout << "Price:";
	cin  >> tmp_price;
	cout << "Model: ";
	cin  >> tmp_m;

	Car* car = new Car(tmp_f, tmp_price, tmp_m);
	cout << "" << endl;
	_x.add_car(car);
}

template<typename T>
void remove_car(T& _x){

	Car* c = find_by_id<T>(_x);

	if(c != nullptr) {
    _x.remove_car(c);        
	}
}

void sell_to(Shop& _shop){

	int tmp_id;
	cout << "Ins ID car: ";
	cin  >> tmp_id;

	Car* tmp_car = _shop.find_car_by_ID(tmp_id);
	
	string name_c; 
	string last_c;
	int    age_c; 

	cout << "Ins name: " << endl;
	cin  >> name_c;
  cout << "Ins lastname: " << endl;
	cin  >> last_c;
	cout << "Ins age: " << endl;
	cin  >> age_c;

	Customer* c = new Customer(name_c, last_c, age_c);

	_shop.sell_to(tmp_car, c);
}

template<typename T, typename K>
void add_employee(T& _x){

	string tmp_name;
	string tmp_last;
	int 	 tmp_age;

	cout << "Ins name: " << endl;
	cin  >> tmp_name;
	cout << "last name: " << endl;
	cin  >> tmp_last;
	cout << "age: " << endl;
	cin  >> tmp_age;

	K* empl = new K(tmp_name, tmp_last, tmp_age);

	_x.add_employee(empl);
}

template<typename T, typename K>
void remove_employee(T& _x){

	int    tmp_id;
	string tmp_name;
	string tmp_last;
	int 	 tmp_age;

	cout << "Ins ID: " << endl;
	cin  >> tmp_id;
	cout << "Ins name: " << endl;
	cin  >> tmp_name;
	cout << "last name: " << endl;
	cin  >> tmp_last;
	cout << "age: " << endl;
	cin  >> tmp_age;

	K tmp_empl(tmp_id, tmp_name, tmp_last, tmp_age);

	_x.remove_employee(&tmp_empl);
}

void fix_car(Laboratory& _lab){

	Car* c = find_by_id<Laboratory>(_lab);

	if(c != nullptr) {
		_lab.fix_car(c);
	}
}

void register_rental(Rental& _rental){

	Car* car = find_by_id<Rental>(_rental);
	if(car == nullptr){
		cout << "Not available car!" << endl;
		return;
	}
	
	int tmp_id; 

	cout << "ID customer: " << endl;
	cin  >> tmp_id;

	Customer* c = _rental.get_customer(tmp_id);
	if(c == nullptr) {
		cout << "Customer non registered!" << endl; 
		return; 
	} 

	time_t now = time(nullptr);
	tm* n      = localtime(&now);

	Date* today = new Date(n->tm_mday, n->tm_mon, n->tm_year);

	_rental.register_rental(c, today, car);
}

void register_return(Rental& _rental){

	Car* car = find_by_id<Rental>(_rental);
	if(car == nullptr){
		cout << "Error!" << endl;
		return;
	}

	int tmp_id; 

	cout << "ID customer: " << endl;
	cin  >> tmp_id;

	Customer* c = _rental.get_customer(tmp_id);

	if(c == nullptr) {
		cout << "Customer non registered!" << endl; 
		return; 
	} 
	time_t now = time(nullptr);
	tm* n      = localtime(&now);

	Date* today = new Date(n->tm_mday, n->tm_mon, n->tm_year);

	_rental.register_return(c, today, car);
}

void calculate_return(Rental& _rental){

	Car* car = find_by_id<Rental>(_rental);
	if(car == nullptr){
		cout << "Error!" << endl;
		return;
	}

	int tmp_id; 

	cout << "ID customer: " << endl;
	cin  >> tmp_id;

	Customer* c = _rental.get_customer(tmp_id);

	if(c == nullptr) {
		cout << "Customer non registered!" << endl; 
		return; 
	} else {
		time_t now = time(nullptr);
		tm* n      = localtime(&now);

		Date* today = new Date(n->tm_mday, n->tm_mon, n->tm_year);

		cout << "Cost: " << _rental.calculate_rental(c, today, car) << endl;

		delete today;
	}
}

void management_shop(Shop& _shop){

	int choice;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "SHOP" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Visualizza parco auto" << endl;
		cout << "2. Aggiungi nuovo veicolo" << endl;
		cout << "3. Rimuovi veicolo venduto" << endl;
		cout << "4. Vendita veicolo a cliente" << endl;
		cout << "5. Ricerca veicolo" << endl;
		cout << "6. Aggiungi dipendente" << endl;
		cout << "7. Licenzia" << endl;
		cout << "0. Torna al menu principale" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Scelta: ";
		cin  >> choice;
	
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _shop;
			break;
		case 2:
			add_car<Shop>(_shop);
			break;
		case 3:
			remove_car<Shop>(_shop);
			break;
		case 4:
			sell_to(_shop);
			break;
		case 5:
			find_car<Shop>(_shop);
			break;
		case 6:
			add_employee<Shop, Shop_employee>(_shop);
			break;
		case 7:
			remove_employee<Shop, Shop_employee>(_shop);
			break;
		}
	}
}

void management_laboratory(Laboratory& _lab){

	int choice;

	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "LABORATORY" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Visualizza officina" << endl;
		cout << "2. Aggiungi nuova macchina da riparare" << endl;
		cout << "3. Ripara veicolo" << endl;
		cout << "4. Ricerca veicolo" << endl;
		cout << "5. Aggiungi dipendente" << endl;
		cout << "6. Licenzia" << endl;
		cout << "0. Torna al menu principale" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Scelta: ";
		cin  >> choice;
	
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _lab;
			break;
		case 2:
			add_car<Laboratory>(_lab);
			break;
		case 3:
			fix_car(_lab);
			break;
		case 4:
			find_car<Laboratory>(_lab);
			break;
		case 5:
			add_employee<Laboratory, Mechanic>(_lab);
			break;
		case 6:
			remove_employee<Laboratory, Mechanic>(_lab);	
			break;
		}
	}
}

void management_rental(Rental& _rental){

	int choice;
	
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "RENTAL" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Visualizza auto a noleggio" << endl;
		cout << "2. Aggiungi nuova auto a noleggio" << endl;
		cout << "3. Rimuovgi auto a noleggio" << endl;
		cout << "4. Registra noleggio" << endl;
		cout << "5. Registra restituzione" << endl;
		cout << "6. Calcola costo noleggio" << endl;
		cout << "7. Ricerca veicolo" << endl;
		cout << "8. Aggiungi dipendente" << endl;
		cout << "9. Licenzia" << endl;
		cout << "0. Torna al menu principale" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Scelta: ";
		cin  >> choice;
	
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _rental;
			break;
		case 2:
			add_car<Rental>(_rental);
			break;
		case 3:
			remove_car<Rental>(_rental);
			break;
		case 4:
			register_rental(_rental);
			break;
		case 5:
			register_return(_rental);
			break;
		case 6:
			calculate_return(_rental);
			break;
		case 7:
			find_car<Rental>(_rental);
			break;
		case 8:
			add_employee<Rental, Rental_employee>(_rental);
			break;
		case 9:
			remove_employee<Rental, Rental_employee>(_rental);
			break;
		}
	}
}

void init_datas(Concessionaria& _c){

	ifstream init_file;
	init_file.open("./DataSet/init_file.txt", ios::in);

	int n_shops; 
	int n_labs; 
	int n_rentals;

	while(init_file >> n_shops >> n_labs >> n_rentals) {
		while(n_shops > 0) {
			Shop* s = new Shop();
			_c.add_shop(s);
			--n_shops;
		}
		while(n_labs > 0) {
			Laboratory* l = new Laboratory();
			_c.add_laboratory(l);
			--n_labs;
		}
		while(n_rentals > 0) {
			Rental* r = new Rental();
			_c.add_rental(r);
			--n_rentals;
		}
	}
}