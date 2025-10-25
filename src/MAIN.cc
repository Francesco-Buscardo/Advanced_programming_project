#include "main.h"
#include "concessionaria.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){

  // "-------------------------------------------
  // "Initializing Concessionaria!
  // "-------------------------------------------
  
  string name;
  if(argc == 1) {
    name = "My Concessioanria";
  } else {
    name = argv[1];
  }
  Concessionaria c(name);

  init_datas(c);

  // -------------------------------------------
  // Stop Initialization!
  // -------------------------------------------

  int choice;
  int id;

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
        cout << "Ins Shop ID: " << endl;
        cin  >> id;

        if(c.get_shop(id) != nullptr) {
          management_shop(*c.get_shop(id));
        } else {
          cout << "No shop found!" << endl;
        }
        break;
      case 2:
        cout << "Ins Shop ID: " << endl;
        cin  >> id;

        if(c.get_rental(id) != nullptr) {
          management_rental(*c.get_rental(id));
        } else {
          cout << "No rental found!" << endl;
        }
        break;
      case 3:
        cout << "Ins Shop ID: " << endl;
        cin  >> id;

        if(c.get_laboratory(id) != nullptr) {
          management_laboratory(*c.get_laboratory(id));
        } else {
          cout << "No lab found!" << endl;
        }
        break;
      default: cout << "Wrong choice!" << endl;
        break;
    }
  }

  return 0;
}


