#include "NodoDij.h"
#define str std::string


NodoDij::NodoDij(str nombre, NodoDij* nodoAnt ,bool visitado, float distancia){
	this->nombre = nombre;
	this->nodoAnterior = nodoAnt;
	this->visitado = visitado;
	this->distancia = distancia;
}
NodoDij::~NodoDij(){
}

NodoDij* NodoDij::getNodoAnt(){
	return this->nodoAnterior;
}
bool NodoDij::getVisitado(){
	return this->visitado;
}
float NodoDij::getDistancia(){
	return this->distancia;
}
str NodoDij::getNombre(){
	return this->nombre;
}

void NodoDij::setDistancia(float dis){
	this->distancia = dis;
}
void NodoDij::setVisitado(){
	this->visitado = true;
}
void NodoDij::setNodoAnt(NodoDij* nodo){
	this->nodoAnterior = nodo;
}
bool NodoDij::operator< (const NodoDij& derecha){
	return (this->nombre < derecha.nombre);
}