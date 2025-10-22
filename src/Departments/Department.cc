#include "Department.h"
#include <iostream>
#include <set>
#include <utility>

Department::Department(): cars(), employees(), customers(){
}

Department::Department(const Department& _d): cars(_d.cars), employees(_d.employees), customers(_d.customers){
}

// Department::~Department(){
//   for(auto e: employees){
//     delete e;
//   }
// }

void Department::register_customer(Customer* _c){

  auto it = customers.find(_c);

  if(it == customers.end()) {
    customers.insert(*it);
  } else {
    cout << "Customer already registered!" << endl;
  }
}
    
void Department::remove_customer(Customer* _c){
  
  auto it = customers.find(_c);

  if(it != customers.end()) {
    customers.erase(*it);
  } else {
    cout << "Customer doesnt exist!" << endl;
  }
}

Customer* Department::get_customer(const int& _id) const{

  for(auto it = customers.begin(); it != customers.end(); ++it) {
    if((*it)->get_ID() == _id){
      return *it;
    }
  }

  return nullptr;
}
