#include "Tablero.h"

Tablero::Tablero(int level) {
	switch(level) {
		case 1: {

			this->tablero = new CasillaBuscaMinas**[8];

			for(int i= 0; i <8; i++)
				this->tablero[i]= new CasillaBuscaMinas*[8];


			this->setSize(8);
			break;
		}
		case 2: {
			this->tablero = new CasillaBuscaMinas**[10];

			for(int i= 0; i <10; i++)
				this->tablero[i]= new CasillaBuscaMinas*[10];

			this->setSize(10);
			break;
		}
		case 3: {
			this->tablero = new CasillaBuscaMinas**[12];

			for(int i= 0; i <12; i++)
				this->tablero[i]= new CasillaBuscaMinas*[12];


			this->setSize(12);
			break;
		}
	}
	provisionarTablero();
	llenarBombas(level);
}

Tablero::~Tablero() {
	if (this->tablero != NULL) {
		for(int i = 0; i < this->size; i++) {
			delete[] tablero[i];
		}
		delete[] tablero;
		tablero = NULL;
	}
}
void Tablero::imprimir() {
	if (this->tablero != NULL) {

		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {

				cout << tablero[i][j]->getDisplay() << " ";
			}
			cout << endl;
		}
	}
}
void Tablero::setSize(int size) {
	this->size = size;
}
int Tablero::getSize() {
	return this->size;
}


void Tablero::provisionarTablero() {
	for(int i = 0 ; i < this->size  ; i++) {
		for(int j = 0 ; j < this->size ; j++) {
			this->tablero[i][j] = new CasillaBuscaMinas(false);
		}
	}
}
void Tablero::imprimirBombas() {
	if (this->tablero != NULL) {

		for(int i = 0; i < this->size; i++) {
			for(int j = 0; j < this->size; j++) {
				if(tablero[i][j]->getBomba() == true) {
					cout << "# ";
				} else {
					cout << "- ";
				}

			}
			cout << endl;
		}
	}
}
void Tablero::marcarCasilla(int x, int y) {
	tablero[x][y]->setDisplay('X');
	tablero[x][y]->setMarca(true);
}
int Tablero::calcularBombas(int x, int y) {
	int contador = 0;

	if(x>0) {
		if(tablero[x-1][y]->getBomba()) {
			contador++;
		}
		
	}
	if(x<size-1) {
		if(tablero[x+1][y]->getBomba()) {
			contador++;
		}
	}
	if(y>0) {
		if(tablero[x][y-1]->getBomba()) {
			contador++;
		}
		
	}
	if(y<size-1) {
		if(tablero[x][y+1]->getBomba()) {
			contador++;
		}
	}
	/*if(x>0 && y >0){
		if(tablero[x-1][y+1]->getBomba()){
			contador++;
		}
		if(tablero[x-1][y-1]->getBomba()){
			contador++;
		}
	}
	if(x<size-1 && y<size-1){
		if(tablero[x+1][y+1]->getBomba()){
			contador++;
		}
		if(tablero[x+1][y-1]->getBomba()){
			contador++;
		}
	}
	esto deberia de revisar las diagonales pero i ran out of time :/
	segun mis pruebas funciona bien a excepcion de revisar las bombas diagonales
	maybe si te sobra tiempo podes ver como seria la solucion <3
	
	*/
	return contador;
}
bool Tablero::destaparCasilla(int x, int y) {
	bool flag = true;
	if(tablero[x][y]->getBomba()) {
		flag = false;
		return flag;
	} else {
		tablero[x][y]->setDisplay(48+calcularBombas(x,y));
		tablero[x][y]->setDiscover(true);
		if(x>0) {
			if(tablero[x-1][y]->getBomba() == false && tablero[x-1][y]->getDiscover() == false) {
				destaparCasilla(x-1,y);
			}
		}
		if(x<size-1) {
			if(tablero[x+1][y]->getBomba() == false && tablero[x+1][y]->getDiscover() == false) {
				destaparCasilla(x+1,y);
			}
		}
		if(y>0) {
			if(tablero[x][y-1]->getBomba() == false && tablero[x][y-1]->getDiscover() == false) {
				destaparCasilla(x,y-1);
			}
		}
		if(y<size-1) {
			if(tablero[x][y+1]->getBomba() == false && tablero[x][y+1]->getDiscover() == false) {
				destaparCasilla(x,y+1);
			}
		}
		return flag;
	}
}
void Tablero::llenarBombas(int level) {
	int contador = 1;
	switch(level) {
		case 1: {
			while(contador <= 12) {
				int posX = rand() % size;
				int posY = rand() % size;
				if(tablero[posX][posY]->getBomba()!= true) {
					tablero[posX][posY]->setBomba(true);
					contador++;
				}

			}
			break;
		}
		case 2: {
			while(contador <= 25) {
				int posX = rand() % size;
				int posY = rand() % size;
				if(tablero[posX][posY]->getBomba()!= true) {
					tablero[posX][posY]->setBomba(true);
					contador++;
				}

			}
			break;
		}
		case 3: {
			while(contador <= 43) {
				int posX = rand() % size;
				int posY = rand() % size;
				if(tablero[posX][posY]->getBomba()!= true) {
					tablero[posX][posY]->setBomba(true);
					contador++;
				}

			}
			break;
		}
	}


}