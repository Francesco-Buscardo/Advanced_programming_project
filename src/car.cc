#include "car.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ostream& operator <<(ostream& os, const Power_supply& _ps) {
  switch (_ps) {
    case GASOLINE: os << "Gasoline"; 
                  break;
    case DIESEL: os << "Diesel"; 
                break;
    case ELECTRIC: os << "Electric"; 
                  break;
    case HYBRID: os << "Hybrid"; 
                break;
    default: os << "Nothing"; 
            break;
  }
  return os;
}

ostream& operator <<(ostream& os, const vector<int>& _size) {
  if (_size.size() == 3) {
    os << "x: " << _size[0] << "  y: " << _size[1] << "  z: " << _size[2];
  } else {
    os << "null";
  }

  return os;
}

ostream& operator <<(ostream& os, const Car& _car) {
  os << "-------------------------------------------" << endl
     << "Car " << "ID: " << _car.ID_car << endl
     << "-------------------------------------------" << endl
     << "Model: " << _car.model_car << endl 
     << "Price: " << _car.price_car << endl
     << "Production Year: " << _car.production_year_car << endl
     << "Power Supply: " << _car.power_supply_car << endl
     << "Color (HEX): " << _car.color_car << endl
     << "Size (mm): " << _car.size_car << endl
     << "-------------------------------------------" << endl;
  return os;
}

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
  cout << "Color (HEX): " << color_car << endl;
  cout << "Size (mm): " << size_car << endl;
  cout << endl << "-------------------------------------------" << endl;
}

Car::~Car(){
  cout << "-------------------------------------------" << endl;
  cout << "Deleting Car" << endl;
  cout << "-------------------------------------------" << endl;
  cout << "ID: " << ID_car << endl;
  cout << "Model: " << model_car << endl;
  cout << "Price: " << price_car << endl;
  cout << "Production Year: " << production_year_car << endl;
  cout << "Power Supply: " << power_supply_car << endl;
  cout << "Color (HEX): " << color_car << endl;
  cout << "Size (mm): " << size_car << endl;
  cout << endl << "-------------------------------------------" << endl;
}
