#include "BuscaMinas.h"

BuscaMinas::BuscaMinas(int level) {
	this->tableroBombas = new Tablero(level);
	tableroBombas->imprimir();
	cout<<endl;
	tableroBombas->imprimirBombas();
	jugar();
}

BuscaMinas::~BuscaMinas() {
	delete tableroBombas;

}
void BuscaMinas::jugar() {
	int opcion = 0 ;
	bool flag = true;
	while(flag == true) {


		opcion = menu();

		switch(opcion) {
			case 1: {
				int x,y=0;
				cout<<"Ingrese posicion x: ";
				cin >> x;
				while(x < 0 || x >=tableroBombas->getSize()) {
					cout<<"Ingrese posicion x: ";
					cin >> x;
				}
				cout<<"Ingrese posicion y: ";
				cin >> y;
				while(y < 0 || y >=tableroBombas->getSize()) {
					cout<<"Ingrese posicion y: ";
					cin >> y;
				}
				 tableroBombas->marcarCasilla(x,y);
				tableroBombas->imprimir();
				cout<<endl;
				tableroBombas->imprimirBombas();

				break;
			}case 2:{
				int x,y=0;
				cout<<"Ingrese posicion x: ";
				cin >> x;
				while(x < 0 || x >=tableroBombas->getSize()) {
					cout<<"Ingrese posicion x: ";
					cin >> x;
				}
				cout<<"Ingrese posicion y: ";
				cin >> y;
				while(y < 0 || y >=tableroBombas->getSize()) {
					cout<<"Ingrese posicion y: ";
					cin >> y;
				}
				if(tableroBombas->destaparCasilla(x,y)){
					
					flag = true;
				}else{
					cout<<"Perdio!\n";
					flag = false;
				}
				
				tableroBombas->imprimir();
				cout<<endl;
				tableroBombas->imprimirBombas();
			}
		}
	}
}


int BuscaMinas::menu() {
	int opcion = 0 ;
	cout<<"Ingrese: \n"
	    <<"1. Marcar casilla \n"
	    <<"2. Destapar casilla \n";
	cin >> opcion;
	return opcion;
}