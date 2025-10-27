#include "concessionaria.h"
#include <iostream>
#include <string>
using namespace std;

#define NAME_CONCESSIONARIA "My CConcessionaria"

int main(void){

  Concessionaria c(NAME_CONCESSIONARIA);

  c.init_datas();

  c.run_menu();

  return 0;
}