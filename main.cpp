#include <iostream>
#include "BuscaMinas.h"
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::string;
using std::cin;
using std::endl;

int menu();

int main(int argc, char** argv) {
	srand (time(NULL));
	int opcion = 0;

	while(opcion!=4) {
		
		opcion = menu();
		
		if(opcion >= 1 && opcion <=3){
			BuscaMinas* juego = new BuscaMinas(opcion);
			delete juego;
		}
	}

	return 0;
}

int menu() {
	int opcion = 0;
	cout<<"Menu\n"
	    <<"1. Facil (8x8)\n"
	    <<"2. Medio (10x10)\n"
	    <<"3. Dificil (12x12)\n"
	    <<"4. Salir\n"
	    <<"Ingrese opcion: ";
	cin >> opcion;
	return opcion;
}