#include "Vertice.h"

struct GDupla{
	int peso;
	Vertice* vertice;	
};



Vertice::Vertice(std::string nombre){
	this->nombre = nombre;
	this->adyacentes = new Lista<GDupla_t*>;
}

Vertice::~Vertice(){
	this->adyacentes->iniciarCursor();
	while(this->adyacentes->avanzarCursor()){
		GDupla_t* duplaActual = this->adyacentes->obtenerCursor();
		delete duplaActual;
	}
	delete this->adyacentes;
}

void Vertice::agregarVerticeAdyacente(Vertice* vertice, int peso){
	GDupla_t* dupla = new GDupla_t;
	dupla->peso = peso;
	dupla->vertice = vertice;
	this->adyacentes->agregar(dupla);
}

bool Vertice::estaVerticeAd(Vertice* vertice){
	this->adyacentes->iniciarCursor();
	bool esta = false;
	GDupla_t* duplaActual;
	while(this->adyacentes->avanzarCursor() && !esta){
		duplaActual = this->adyacentes->obtenerCursor();
		if(duplaActual->vertice == vertice){
			esta = true;
		}
	}
	return esta;
}

GDupla_t* Vertice::duplaConVertice(Vertice* vertice){
	if(this->estaVerticeAd(vertice)){
		this->adyacentes->iniciarCursor();
		while(this->adyacentes->avanzarCursor()){
			GDupla_t* duplaActual = this->adyacentes->obtenerCursor();
			if(duplaActual->vertice == vertice){
				return(duplaActual);
			}
		}
	}else{
		throw std::string ("El vertice no es adyacente");
	}
}

int Vertice::pesoVerticeAd(Vertice* vertice){
	GDupla_t* dupla = this->duplaConVertice(vertice);
	int peso = dupla->peso;
	return(dupla->peso);
}

std::string Vertice::getNombre(){
	return(this->nombre);
}

Lista<Vertice*>* Vertice::verticesAd(){
	this->adyacentes->iniciarCursor();
	Lista<Vertice*>* lista = new Lista<Vertice*>;
	while(this->adyacentes->avanzarCursor()){
		GDupla_t* duplaActual = this->adyacentes->obtenerCursor();
		lista->agregar(duplaActual->vertice);
	}
	return lista;
}
