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
	cout << "--> " << endl;
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
		case 5: 
			tmp_ft = GASOLINE;
			break; 
	}
	cout << "Price:" << endl;
	cin  >> tmp_price;
	cout << "Model: " << endl;
	cin  >> tmp_m;

	Fuel tmp_f(tmp_ft);

	Car* car = new Car(tmp_f, tmp_price, tmp_m);

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
		_rental.register_rental(c, today);
	}
}

void register_return(Rental& _rental){

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

		_rental.register_return(c, today);
	}
}

void calculate_return(Rental& _rental){

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

		cout << "Cost: " << _rental.calculate_rental(c, today) << endl;

		delete today;
	}
}

void management_shop(Shop& _shop){

	int choice;

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

	while(true){
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
		default:
			break;
		}
	}
}

void management_laboratory(Laboratory& _lab){

	int choice;

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

	while(true){
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
		default:
			break;
		}
	}
}

void management_rental(Rental& _rental){

	int choice;

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

	while(true){
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
		default:
			break;
		}
	}
}

void init_code(Concessionaria& _c){
	
	// vector<Car>        conc_cars     = init_cars();
  // vector<Laboratory> conc_labs     = init_labs(conc_cars);
  // vector<Laboratory> conc_labs     = init_labs();
  // vector<Shop>       conc_shops    = init_shops();
  // vector<Rental>     conc_rentals  = init_rentals();
}

/*
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
*/
/*
vector<Laboratory> init_labs(const vector<Car>& _cars)
vector<Laboratory> init_labs(){

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

		// cout << "CARS IN LAB" << endl;
		// while(n-- > 0) {
		// 	int i = rand() % _cars.size();
		// 	lab.add_car(_cars.at(i));
		// 	cout << _cars.at(i);
		// }

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
*/
/*
vector<Shop> init_shops(){ //point of sale

	ifstream _in_file;
	ifstream _in_shop_cars;
	_in_file.open("./dataSet/shops.txt", ios::in);
	_in_shop_cars.open("./dataSet/shop_cars.txt", ios::in);

	vector<Shop> shops;

	string id_s;
	int n; //num of cars in shop

	//car info
	string id;
	long double price;
	int dd, mm, yyyy;
	Power_supply ps;
	string color;
	int x, y, z;
	string model;
	string sc;

	while(_in_file >> id_s >> n >> sc) {
		Shop s(id_s);

		cout << s;

		cout << "CARS IN SHOP" << endl;
		while(n-- > 0){
			_in_shop_cars >> id 
				   					>> price 
				   					>> dd
				   					>> mm
				   					>> yyyy
				   					>> ps 
				   					>> color 
				   					>> x
				   					>> y
				   					>> z 

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
*/
/*
vector<Laboratory> init_labs(const vector<Car>& _cars)
vector<Laboratory> init_labs(){

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

		// cout << "CARS IN LAB" << endl;
		// while(n-- > 0) {
		// 	int i = rand() % _cars.size();
		// 	lab.add_car(_cars.at(i));
		// 	cout << _cars.at(i);
		// }

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
*/
/*
vector<Shop> init_shops(){ //point of sale

	ifstream _in_file;
	ifstream _in_shop_cars;
	_in_file.open("./dataSet/shops.txt", ios::in);
	_in_shop_cars.open("./dataSet/shop_cars.txt", ios::in);

	vector<Shop> shops;

	string id_s;
	int n; //num of cars in shop

	//car info
	string id;
	long double price;
	int dd, mm, yyyy;
	Power_supply ps;
	string color;
	int x, y, z;
	string model;
	string sc;

	while(_in_file >> id_s >> n >> sc) {
		Shop s(id_s);

		cout << s;

		cout << "CARS IN SHOP" << endl;
		while(n-- > 0){
			_in_shop_cars >> id 
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

			s.add_car(car);

			cout << car << endl;
		}

		shops.push_back(s);
	}

	_in_file.close();
	_in_shop_cars.close();

	return shops; 
}
*/
/*
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
*/
/*
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

		// cout << "CARS IN LAB" << endl;
		// while(n-- > 0) {
		// 	int i = rand() % _cars.size();
		// 	lab.add_car(_cars.at(i));
		// 	cout << _cars.at(i);
		// }

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
*/
/*
vector<Shop> init_shops(){ //point of sale

	ifstream _in_file;
	ifstream _in_shop_cars;
	_in_file.open("./dataSet/shops.txt", ios::in);
	_in_shop_cars.open("./dataSet/shop_cars.txt", ios::in);

	vector<Shop> shops;

	string id_s;
	int n; //num of cars in shop

	//car info
	string id;
	long double price;
	int dd, mm, yyyy;
	Power_supply ps;
	string color;
	int x, y, z;
	string model;
	string sc;

	while(_in_file >> id_s >> n >> sc) {
		Shop s(id_s);

		cout << s;

		cout << "CARS IN SHOP" << endl;
		while(n-- > 0){
			_in_shop_cars >> id 
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

			s.add_car(car);

			cout << car << endl;
		}

		shops.push_back(s);
	}

	_in_file.close();
	_in_shop_cars.close();

	return shops; 
}
*/
/*
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
				   					>> model
								  	>> sc;

			Date yop(dd, mm, yyyy);
			vector<int> dim = {x, y, z};
			Car car(id, price, yop, ps, color, dim, model);

			s.add_car(car);

			cout << car << endl;
		}

		shops.push_back(s);
	}

	_in_file.close();
	_in_shop_cars.close();

	return shops; 
}
*/
/*
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
*/