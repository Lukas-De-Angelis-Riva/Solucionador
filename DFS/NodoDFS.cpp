#include "NodoDFS.h"

NodoDFS::NodoDFS(std::string vertice, bool visitado, NodoDFS * anterior){

	this->vertice = vertice;
	this->visitado = false;
	this->anterior = anterior;
}

std::string NodoDFS::obtenerVertice(){

	return this->vertice;
}

bool NodoDFS::obtenerVistado(){

	return this->visitado;
}

void NodoDFS::fueVisitado(){

	this->visitado = true;
}

void NodoDFS::cambiarAnterior(NodoDFS * nuevoAnterior){

	this->anterior = nuevoAnterior;
}

NodoDFS * NodoDFS::obtenerAnterior(){

	return this->anterior;
}

bool NodoDFS::operator< (const NodoDFS& derecha){

	return (this->vertice < derecha.vertice);
}

NodoDFS::~NodoDFS(){


}
