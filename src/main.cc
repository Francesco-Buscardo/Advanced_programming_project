#include "main.h"
#include "Types/fuel.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void management_shop(Shop& _shop){

	int choice;

	cout << "-------------------------------------------" << endl;
	cout << "SHOP" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "1. Visualizza parco auto" << endl;
	cout << "2. Aggiungi nuovo veicolo" << endl;
	cout << "3. Rimuovi veicolo venduto" << endl;
	cout << "4. Vendita veicolo a cliente" << endl;
	cout << "5. Ricerca veicolo (per targa, marca, modello)" << endl;
	cout << "6. Aggiungi dipendente" << endl;
	cout << "7. Licenzia" << endl;
	cout << "0. Torna al menu principale" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Scelta: ";
	cin >> choice;

	while(true){
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _shop;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
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
	cout << "4. Ricerca veicolo (per targa, marca, modello)" << endl;
	cout << "5. Aggiungi dipendente" << endl;
	cout << "6. Licenzia" << endl;
	cout << "0. Torna al menu principale" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Scelta: ";
	cin >> choice;

	while(true){
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _lab;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
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
	cout << "7. Ricerca veicolo (per targa, marca, modello)" << endl;
	cout << "8. Aggiungi dipendente" << endl;
	cout << "9. Licenzia" << endl;
	cout << "0. Torna al menu principale" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Scelta: ";
	cin >> choice;

	while(true){
		switch (choice){
		case 0:
			return;
			break;
		case 1:
			cout << _rental;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			break;
		}
	}
}

// vector<Car> init_cars(){

// 	ifstream _in_file;
// 	_in_file.open("./dataSet/cars.txt", ios::in);

// 	vector<Car> cars;

// 	string id;
// 	long double price;
// 	int dd, mm, yyyy;
// 	Power_supply ps;
// 	string color;
// 	int x, y, z;
// 	string model;
// 	string sc;

// 	while (_in_file >> id 
// 				   				>> price 
// 				   				>> dd
// 				   				>> mm
// 				   				>> yyyy
// 				   				>> ps 
// 				   				>> color 
// 				   				>> x
// 				   				>> y
// 				   				>> z 
// 				   				>> model
// 								  >> sc) {

// 	  Date yop(dd, mm, yyyy);
// 	  vector<int> dim = {x, y, z};
// 	  Car car(id, price, yop, ps, color, dim, model);
// 		cout << car << endl;

// 		cars.push_back(car);
// 	}

// 	_in_file.close();
// 	return cars;
// }

// vector<Laboratory> init_labs(const vector<Car>& _cars)
// vector<Laboratory> init_labs(){

// 	srand((unsigned) time(0));

// 	ifstream _in_file_lab;
// 	ifstream _in_file_mechanic;
// 	_in_file_lab.open("./dataSet/labs.txt", ios::in);
// 	_in_file_mechanic.open("./dataSet/mechanics.txt", ios::in);

	
// 	vector<Laboratory> labs;

// 	string ID_lab;
// 	int n; //cars num
// 	int m; //mechenics num
// 	string sc; //;

// 	string ID_employee;
//   string name_employee;
//   string lastname_employee;
//   int age_employee;

// 	while (_in_file_lab >> ID_lab 
// 											>> n 
// 											>> m
// 											>> sc){
// 		Laboratory lab(ID_lab);

// 		cout << lab << endl;

// 		// cout << "CARS IN LAB" << endl;
// 		// while(n-- > 0) {
// 		// 	int i = rand() % _cars.size();
// 		// 	lab.add_car(_cars.at(i));
// 		// 	cout << _cars.at(i);
// 		// }

// 		cout << "MECHANICS IN LAB" << endl;
// 		while(m-- > 0) {
// 			_in_file_mechanic >> ID_employee
// 								 	 			>> name_employee 
// 								 	 			>> lastname_employee
// 								 	 			>> age_employee
// 								 	 			>> sc;
// 			Mechanic m(ID_employee, name_employee, lastname_employee, age_employee);
// 			lab.add_mechanic(m);

// 			cout << m << endl;
// 		}

// 		labs.push_back(lab);
// 	}

// 	_in_file_lab.close();
// 	_in_file_mechanic.close();

// 	return labs; 
// }

// vector<Shop> init_shops(){ //point of sale

// 	ifstream _in_file;
// 	ifstream _in_shop_cars;
// 	_in_file.open("./dataSet/shops.txt", ios::in);
// 	_in_shop_cars.open("./dataSet/shop_cars.txt", ios::in);

// 	vector<Shop> shops;

// 	string id_s;
// 	int n; //num of cars in shop

// 	//car info
// 	string id;
// 	long double price;
// 	int dd, mm, yyyy;
// 	Power_supply ps;
// 	string color;
// 	int x, y, z;
// 	string model;
// 	string sc;

// 	while(_in_file >> id_s >> n >> sc) {
// 		Shop s(id_s);

// 		cout << s;

// 		cout << "CARS IN SHOP" << endl;
// 		while(n-- > 0){
// 			_in_shop_cars >> id 
// 				   					>> price 
// 				   					>> dd
// 				   					>> mm
// 				   					>> yyyy
// 				   					>> ps 
// 				   					>> color 
// 				   					>> x
// 				   					>> y
// 				   					>> z 
// 				   					>> model
// 								  	>> sc;

// 			Date yop(dd, mm, yyyy);
// 			vector<int> dim = {x, y, z};
// 			Car car(id, price, yop, ps, color, dim, model);

// 			s.add_car(car);

// 			cout << car << endl;
// 		}

// 		shops.push_back(s);
// 	}

// 	_in_file.close();
// 	_in_shop_cars.close();

// 	return shops; 
// }

// vector<Rental> init_rentals(){

// 	ifstream _in_file;
// 	ifstream _in_rental_cars;
// 	_in_file.open("./dataSet/rentals.txt", ios::in);
// 	_in_rental_cars.open("./dataSet/rental_cars.txt", ios::in);

// 	vector<Rental> rentals;

// 	string id_ren;
// 	int n; //rental_cars

// 	//car info
// 	string id;
// 	long double price;
// 	int dd, mm, yyyy;
// 	Power_supply ps;
// 	string color;
// 	int x, y, z;
// 	string model;
// 	string sc;
	

// 	while(_in_file >> id_ren >> n >> sc){
// 		Rental ren(id_ren);
// 		cout << ren;

// 		cout << "CARS IN RENTAL" << endl;
// 		while(n-- > 0){
// 			_in_rental_cars >> id 
// 				   						>> price 
// 				   						>> dd
// 				   						>> mm
// 				   						>> yyyy
// 				   						>> ps 
// 				   						>> color 
// 				   						>> x
// 				   						>> y
// 				   						>> z 
// 				   						>> model
// 								  		>> sc;
// 			Date yop(dd, mm, yyyy);
// 	  	vector<int> dim = {x, y, z};
// 	  	Car car(id, price, yop, ps, color, dim, model);

// 			cout << car;

// 			ren.add_car(car);
// 		}

// 		rentals.push_back(ren);
// 	}

// 	_in_file.close();
// 	_in_rental_cars.close();

// 	return rentals; 
// }
