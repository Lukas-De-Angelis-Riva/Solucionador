#include "Vertice.h"

struct GDupla{
	int peso;
	Vertice* vertice;	
};


/* Crea un Vertice con el nombre 'nombre'*/
Vertice::Vertice(std::string nombre){
	this->nombre = nombre;
	this->adyacentes = new Lista<GDupla_t*>;
}

/* Elimina el Vértice y toda la memoria que se ha utilizado internamente. */
Vertice::~Vertice(){
	this->adyacentes->iniciarCursor();
	while(this->adyacentes->avanzarCursor()){
		GDupla_t* duplaActual = this->adyacentes->obtenerCursor();
		delete duplaActual;
	}
	delete this->adyacentes;
}

/* Agrega el vértice 'vertice' a la lista de vértices adyacentes con el peso que se pasa por referencia.
	PreCondición: No se llamará más de una vez a esta función con los mismos vértices.
	PostCondición: El vértice 'this' será adyacente a 'vertice' pero no vale la viceversa.
*/
void Vertice::agregarVerticeAdyacente(Vertice* vertice, int peso){
	GDupla_t* dupla = new GDupla_t;
	dupla->peso = peso;
	dupla->vertice = vertice;
	this->adyacentes->agregar(dupla);
}

/* Devuelve true si el vértice 'this' es adyacente al vértice 'vertice'
	En caso caso contrario devuelve false.
*/
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
/*
	Devuelve la dupla vértice - peso, que contiene al vértice 'vertice'.
	En caso de no exitir como adyacente se devuleve un throw diciendo que el vértice no es adyacente.
*/
GDupla_t* Vertice::duplaConVertice(Vertice* vertice){
	this->adyacentes->iniciarCursor();
	while(this->adyacentes->avanzarCursor()){
		if(this->adyacentes->obtenerCursor()->vertice == vertice){
			return(this->adyacentes->obtenerCursor());
		}
	}
	throw std::string ("El vertice no es adyacente");
}


/* 	
	PreCondición: El vértice debe ser adyacentes.
	PostCondición: Devolverá el peso de adyacencia entre ambos vértices. 
*/
int Vertice::pesoVerticeAd(Vertice* vertice){
	GDupla_t* dupla = this->duplaConVertice(vertice);
	return(dupla->peso);
}

/*
	Devuelve una Lista que contiene punteros a los vértices adyacentes del vértice. 
*/
Lista<Vertice*>* Vertice::verticesAd(){
	this->adyacentes->iniciarCursor();
	Lista<Vertice*>* lista = new Lista<Vertice*>;
	while(this->adyacentes->avanzarCursor()){
		GDupla_t* duplaActual = this->adyacentes->obtenerCursor();
		lista->agregar(duplaActual->vertice);
	}
	return lista;
}

/*
	Devuelve el nombre del vértice.
*/
std::string Vertice::getNombre(){
	return(this->nombre);
}
