#include "Grafo.h"

#define str std::string


// '#define' n === nombre.
// '#define' v === vertice.

Grafo::Grafo(){
	this->vertices = new Lista<Vertice*>;
}
Grafo::~Grafo(){
	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		delete this->vertices->obtenerCursor();
	}
	delete this->vertices;
}
void Grafo::ingresarVertice(str nombre){
	Vertice* vertice = new Vertice(nombre);
	this->vertices->agregar(vertice);
}

Vertice* Grafo::obtenerVertice(str nombre){
	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		Vertice* verticeActual = this->vertices->obtenerCursor(); 
		if(verticeActual->getNombre() == nombre){
			return verticeActual;
		}
	}
	throw str ("No existe dicho vertice");
}

void Grafo::ingresarArista(str n1, str n2, int peso){
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);
	v1->agregarVerticeAdyacente(v2,peso);
	v2->agregarVerticeAdyacente(v1,peso);
}
bool Grafo::estaVertice(str n){
	Vertice* v = this->obtenerVertice(n);
	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		if(this->vertices->obtenerCursor() == v){
			return true;
		}
	}
	return false;
}

bool Grafo::sonAdyacentes(str n1, str n2){
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);

	if(v1->estaVerticeAd(v2) && v2->estaVerticeAd(v1)){
		return true;
	}else if(!v1->estaVerticeAd(v2) && !v2->estaVerticeAd(v1)){
		return false;
	}else{
		throw str ("Los vertices no cumplen ser adyacentes ambos a la vez, OJO.");
	}
}
float Grafo::pesoAdyacentes(str n1, str n2){
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);
	
	if(v1 == v2){
		return 0;
	}
	
	if(this->sonAdyacentes(n1,n2)){
		if(v1->pesoVerticeAd(v2) == v2->pesoVerticeAd(v1)){
			return v1->pesoVerticeAd(v2);
		}else{
			throw str ("Los pesos no coinciden.");
		}
	}else{
		return INFINITY;
		//throw str ("Los vertices no son adyacentes.");
	}
}

Lista<str>* Grafo::obtenerVertices(){
	Lista<str>* lista = new Lista<str>;
	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		lista->agregar(this->vertices->obtenerCursor()->getNombre());
	}
	return lista;
}

Lista<str>* Grafo::adyacentesAlVertice(str n){
	Vertice* v = this->obtenerVertice(n);
	Lista<Vertice*>* listaDeVertices = v->verticesAd();
	Lista<str>* listaDeNombres = new Lista<str>;
	listaDeVertices->iniciarCursor();
	while(listaDeVertices->avanzarCursor()){
		listaDeNombres->agregar(listaDeVertices->obtenerCursor()->getNombre());
	}
	return listaDeNombres;
}
