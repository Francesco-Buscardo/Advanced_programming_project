#include "Concessionaria.h"
#include <iostream>
using namespace std;

Concessionaria::Concessionaria(){
  cout << "Create Concessionaria!" << endl;
}

Concessionaria::Concessionaria(const Concessionaria& _c){ //copia
  cout << "Create Concessionaria!" << endl;
}

Concessionaria::~Concessionaria(){
  cout << "Delete Concessionaria!" << endl; 
}
