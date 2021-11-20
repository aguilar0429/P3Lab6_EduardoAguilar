#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H
#include "Tablero.h"
#include <stdlib.h>
#include <time.h>
class BuscaMinas
{
	public:
		BuscaMinas(int);
		~BuscaMinas();
		int menu();
		void jugar();
	private:
		Tablero* tableroBombas;
	protected:
};
					
#endif