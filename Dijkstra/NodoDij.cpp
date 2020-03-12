#include "NodoDij.h"
#define str std::string


NodoDij::NodoDij(str nombre, NodoDij* nodoAnt,bool visitado, float distancia){
	this->nombre = nombre;
	this->visitado = visitado;
	this->nodoAnterior = nodoAnt;
	this->distancia = distancia;
}
NodoDij::~NodoDij(){
}

NodoDij* NodoDij::getNodoAnt(){
	return this->nodoAnterior;
}
float NodoDij::getDistancia(){
	return this->distancia;
}
str NodoDij::getNombre(){
	return this->nombre;
}
bool NodoDij::getVisitado(){
	return this->visitado;
}

void NodoDij::setVisitadoT(){
	this->visitado = true;
}
		
void NodoDij::setDistancia(float dis){
	this->distancia = dis;
}
void NodoDij::setNodoAnt(NodoDij* nodo){
	this->nodoAnterior = nodo;
}
bool NodoDij::operator< (const NodoDij& derecha){
	return (this->nombre < derecha.nombre);
}