#include "main.h"
#include <iostream>
using namespace std;

/*
 * Reparti:
 *   negozio 
 *   noleggio
 *   officina.
 * La parte principale:
 *   compravendita di veicoli (nuovi e usati), 
 *   gestione parco auto
 * Un'altra parte:
 *   gestione del noleggio di una gamma di macchine in possesso 
 * L'autoconcessionaria fornirà assistenza ai clienti tramite officina, 
 * che dovrà anche occuparsi della riparazione delle macchine destinate 
 * sia alla rivendita che al noleggio.
*/

int main(int argc, char *argv[]){

  cout << "-------------------------------------------" << endl;
  cout << "Initializing Concessionaria . . ." << endl;
  cout << "-------------------------------------------" << endl;
  
  // Concessionaria concessionaria(argv[1]);

  // vector<Car>        conc_cars     = init_cars();
  // vector<Laboratory> conc_labs     = init_labs(conc_cars);
  // vector<Laboratory> conc_labs     = init_labs();
  // vector<Shop>       conc_shops    = init_shops();
  // vector<Rental>     conc_rentals  = init_rentals();

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
        management_shop();
        break;
      case 2:
        management_rental();
        break;
      case 3:
        management_laboratory();
        break;
      default: cout << "Wrong choice!" << endl;
        break;
    }
  }

  return 0;
}


