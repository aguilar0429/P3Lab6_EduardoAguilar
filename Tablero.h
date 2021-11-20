#ifndef TABLERO_H
#define TABLERO_H

#include <stdlib.h>
#include <time.h>
#include <cstddef>
#include <iostream>
#include "CasillaBuscaMinas.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

class Tablero
{
	public:
		Tablero(int);
		~Tablero();
		bool destaparCasilla(int, int);
		int calcularBombas(int,int);
		void marcarCasilla(int,int);
		void imprimirBombas();
		void provisionarTablero();
		void setSize(int);
		int getSize();
		void llenarBombas(int);
		void imprimir();
	private:
		CasillaBuscaMinas*** tablero;
		int size;
	protected:
};

#endif