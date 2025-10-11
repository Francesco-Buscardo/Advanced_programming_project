#include "car.h"
#include "Types/Date.h"
#include "Types/Power_supply.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Car::Car() : ID_car("CAR000"), price_car(0.0), production_year_car(0, 0, 0), power_supply_car(NOTHNG), color_car("#FFFFFF"), size_car({0, 0, 0}), model_car("null"){
  cout << "-------------------------------------------" << endl;
  cout << "Creating Deafault Car" << endl;
  cout << "-------------------------------------------" << endl;
}

Car::Car(string _id, long double _price, Date _date, Power_supply _ps, string _color, vector<int> _size, string _model) : ID_car(_id), price_car(_price), production_year_car(_date), power_supply_car(_ps), color_car(_color), size_car(_size), model_car(_model) {
  cout << "-------------------------------------------" << endl;
  cout << "Creating Car" << endl;
  cout << "-------------------------------------------" << endl;
  cout << "ID: " << ID_car << endl;
  cout << "Model: " << model_car << endl;
  cout << "Price: " << price_car << endl;
  cout << "Production Year: " << production_year_car << endl;

  cout << "Power Supply: " << power_supply_car << endl;
  switch (power_supply_car) {
    case GASOLINE: cout << "Gasoline"; 
                  break;
    case DIESEL: cout << "Diesel"; 
                break;
    case ELECTRIC: cout << "Electric"; 
                  break;
    case HYBRID: cout << "Hybrid"; 
                break;
    default: cout << "Nothing"; 
            break;
  }
  cout << endl;

  cout << "Color (HEX): " << color_car << endl;
  cout << "Size (mm): " << size_car << endl;
  if (size_car.size() == 3) {
    cout << "x: " << size_car[0] << "  y: " << size_car[1] << "  z: " << size_car[2];
  } else {
    cout << "null";
  }
  cout << endl << "-------------------------------------------" << endl;
}

Car::~Car(){

  //ridichiarazione metodo << per ogni attributo in class Car per
  // date
  // ps

  cout << "-------------------------------------------" << endl;
  cout << "Deleting Car" << endl;
  cout << "-------------------------------------------" << endl;
  cout << "ID: " << ID_car << endl;
  cout << "Model: " << model_car << endl;
  cout << "Price: " << price_car << endl;
  cout << "Production Year: " << production_year_car << endl;

  cout << "Power Supply: " << power_supply_car << endl;
  switch (power_supply_car) {
    case GASOLINE: cout << "Gasoline"; 
                  break;
    case DIESEL: cout << "Diesel"; 
                break;
    case ELECTRIC: cout << "Electric"; 
                  break;
    case HYBRID: cout << "Hybrid"; 
                break;
    default: cout << "Nothing"; 
            break;
  }
  cout << endl;

  cout << "Color (HEX): " << color_car << endl;
  cout << "Size (mm): " << size_car << endl;
  if (size_car.size() == 3) {
    cout << "x: " << size_car[0] << "  y: " << size_car[1] << "  z: " << size_car[2];
  } else {
    cout << "null";
  }
  cout << endl << "-------------------------------------------" << endl;
}

