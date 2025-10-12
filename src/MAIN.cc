#include "Concessionaria.h"
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
 * L'autoconcessionaria fornirà assistenza ai clienti tramite officina, che dovrà anche occuparsi della riparazione delle macchine destinate sia alla rivendita che al noleggio.
*/

int main(int argc, char *argv[]){

  //datas inizialization
  cout << "-------------------------------------------" << endl;
  cout << "Initializing Concessionaria . . ." << endl;
  cout << "-------------------------------------------" << endl;
  
  Concessionaria concessionaria(argv[1]);

  vector<Car>        conc_cars     = init_cars();
  // vector<Laboratory> conc_labs     = init_labs();
  // vector<Shop>       conc_shops    = init_shops();
  // vector<Rental>     conc_rentals  = init_rentals();


  cout << "-------------------------------------------" << endl;

 // while(true) {}

  return 0;
}
