#include "CasillaBuscaMinas.h"

CasillaBuscaMinas::CasillaBuscaMinas(bool bomba)
{
	this->esBomba = bomba;
	this->descubierta = false;
	this->display = '-';
	this->marcada = false;
}
char CasillaBuscaMinas::getDisplay(){
	return this->display;
}
bool CasillaBuscaMinas::getBomba(){
	return this->esBomba;
}
bool CasillaBuscaMinas::getMarca(){
	return this->marcada;
}
void CasillaBuscaMinas::setBomba(bool bomba){
	this->esBomba = bomba;
}
void CasillaBuscaMinas::setMarca(bool marca){
	this->marcada = marca;
}
void CasillaBuscaMinas::setDisplay(char x){
	this->display = x;
}
bool CasillaBuscaMinas::getDiscover(){
	return this->descubierta;
}
void CasillaBuscaMinas::setDiscover(bool x){
	this->descubierta = x;
}