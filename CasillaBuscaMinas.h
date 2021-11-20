#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H

#include <stdlib.h>
#include <time.h>
class CasillaBuscaMinas
{
	public:
		CasillaBuscaMinas(bool);
		char getDisplay();
		void setDisplay(char);
		bool getBomba();
		bool getMarca();
		void setBomba(bool);
		void setMarca(bool);
		bool getDiscover();
		void setDiscover(bool);
	private:
		bool esBomba;
		bool descubierta;
		char display;
		bool marcada;
	protected:
};

#endif