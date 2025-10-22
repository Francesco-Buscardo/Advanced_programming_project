#include "main.h"
#include "concessionaria.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

  cout << "-------------------------------------------" << endl;
  cout << "Initializing Concessionaria . . ." << endl;
  cout << "-------------------------------------------" << endl;
  
  string name;
  if(argc == 1) {
    name = "My Concessioanria";
  } else {
    name = argv[1];
  }
  Concessionaria c(name);

  init_code(c);

  cout << "-------------------------------------------" << endl;
  cout << "Stop Initialization!" << endl;
  cout << "-------------------------------------------" << endl;

  int choice;

  while(true) {
    cout << "-------------------------------------------" << endl;
    cout << "SISTEMA GESTIONE CONCESSIONARIA" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. Gestione Parco Auto (Negozio)" << endl;
    cout << "2. Gestione Noleggio" << endl;
    cout << "3. Gestione Officina" << endl;
    cout << "0. Esci" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Scelta: ";
    cin >> choice;

    switch(choice){
      case 0: 
        return 0;
        break;
      case 1:
        management_shop(c.get_shop());
        break;
      case 2:
        management_rental(c.get_rental());
        break;
      case 3:
        management_laboratory(c.get_laboratory());
        break;
      default: cout << "Wrong choice!" << endl;
        break;
    }
  }

  return 0;
}


