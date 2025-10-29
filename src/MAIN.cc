#include "concessionaria.h"
#include "Exceptions/not_available_value_exception.h"
#include <iostream>
#include <string>
using namespace std;

#define NAME_CONCESSIONARIA "My Concessionaria"

int main(void){

  Concessionaria c(NAME_CONCESSIONARIA);

  try {
    c.init_datas();
  } catch(const Not_Available_Value_Exception& e) {
    cout << e.what() << endl;
  }

  c.run_menu();

  return 0;
}