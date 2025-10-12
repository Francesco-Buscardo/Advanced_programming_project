#include "Concessionaria.h"
#include <iostream>
using namespace std;

Concessionaria::Concessionaria() : name("null"){
  cout << "Create Default Concessionaria!" << endl;
}

Concessionaria::Concessionaria(string _n) : name(_n){
  cout << "Create Concessionaria " << _n << "!" << endl;
}

Concessionaria::Concessionaria(const Concessionaria& _c){ //copia
  cout << "Copy Concessionaria!" << endl;
}

Concessionaria::~Concessionaria(){
  cout << "Delete Concessionaria!" << endl; 
}
