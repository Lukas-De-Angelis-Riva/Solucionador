#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include "../Dijkstra/NodoDij.h"
#include "NodoHeap.h"
#include "Hash.h"

class Heap{

	private:

		unsigned int capacidad;
		unsigned int tamanio;
		NodoHeap<NodoDij*> ** heap;
		Hash<int> * indices;

	public:

		/*
		 * Pre:
		 * Post: Se crea un heap vacio
		 */
		Heap();

		/*
		 * Pre:
		 * Post: Devuelve true si esta vacio
		 */
		bool estaVacio();

		/*
		 * Pre:
		 * Post: Se ha insertado un elemento
		 */
		void insertar(float clave, NodoDij* elemento);

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve el elemento minimo
		 */
		NodoDij* obtenerElementoMinimo();

		/*
		 * Pre: El elemento esta en el heap y la nuevaClave es minima
		 * Post: Se disminuido la clave y actualizado el heap
		 */
		void disminuirClave(NodoDij* elemento, float nuevaClave);

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve la clave minima
		 */
		float obtenerClaveMinima();

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Se ha removido el minimo
		 */
		void removerMinimo();

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el Heap
		 */
		~Heap();

	private:

		/*
		 * Pre:
		 * Post: Se ha incrementado la capacidad del Heap
		 */
		void expandirHeap();

		/*
		 * Pre: Se ha insertado en el heap en el indiceDeInsercion
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaArriba(unsigned int indiceDeInsercion);

		/*
		 * Pre: Se ha removido el elemento minimo
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaAbajo(unsigned int indice);

		/*
		 * Pre:
		 * Post: Devuelve true si izquierda < derecha
		 */
		bool funcionDeComparacion(NodoHeap<NodoDij> * izquierda, NodoHeap<NodoDij> * derecha);
};



Heap::Heap(){

	this->capacidad = 3;
	this->tamanio = 0;
	this->heap = new NodoHeap<NodoDij*>*[this->capacidad];
	this->indices = new Hash<int>;
}



bool Heap::estaVacio(){

	return this->tamanio == 0;
}



NodoDij* Heap::obtenerElementoMinimo(){

	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");
	}

	NodoHeap<NodoDij*> * minimo = this->heap[0];
	return minimo->obtenerValor();
}



float Heap::obtenerClaveMinima(){

	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");
	}

	NodoHeap<NodoDij*> * minimo = this->heap[0];
	return minimo->obtenerClave();
}



void Heap::insertar(float clave, NodoDij* elemento){


	if(tamanio == this->capacidad){

		this->expandirHeap();
	}

	NodoHeap<NodoDij*> * aAgregar = new NodoHeap<NodoDij*>(clave, elemento);

	this->heap[this->tamanio] = aAgregar;

	this->indices->agregar(elemento->getNombre(), this->tamanio);

	this->propagarParaArriba(this->tamanio);

	this->tamanio++;

}

void Heap::disminuirClave(NodoDij* elemento, float nuevaClave){

	int indice = this->indices->buscar(elemento->getNombre());

	NodoHeap<NodoDij*> * aCambiar = this->heap[indice];

	if(aCambiar->obtenerClave() < nuevaClave){

		throw std::string("Se quiso disminuirClave con una clave de mayor tamaño");
	}
	aCambiar->cambiarClave(nuevaClave);
	this->propagarParaArriba(indice);

}

void Heap::expandirHeap(){


	NodoHeap<NodoDij*> ** nuevoHeap = new NodoHeap<NodoDij*>*[this->capacidad * 2];

	for(unsigned int i = 0; i < this->capacidad; i++){

		nuevoHeap[i] = this->heap[i];

	}

	this->capacidad = this->capacidad * 2;
	delete []this->heap;
	this->heap = nuevoHeap;

}


void Heap::propagarParaArriba(unsigned int indiceDeInsercion){


	if(indiceDeInsercion == 0){
		return;
	}

	unsigned int indiceDelPadre;
	if(indiceDeInsercion % 2 == 0){

		indiceDelPadre = (indiceDeInsercion - 2) / 2;
	}else{

		indiceDelPadre = (indiceDeInsercion - 1) / 2;
	}

	NodoHeap<NodoDij*> * hijo = this->heap[indiceDeInsercion];
	NodoHeap<NodoDij*> * padre = this->heap[indiceDelPadre];

	bool esMenor = this->funcionDeComparacion(hijo, padre);

	if(esMenor){

		this->heap[indiceDelPadre] = hijo;
		this->heap[indiceDeInsercion] = padre;

		std::string nombreDelHijo = hijo->obtenerValor()->getNombre();
		std::string nombreDelPadre = padre->obtenerValor()->getNombre();

		this->indices->cambiarElemento(nombreDelHijo, indiceDelPadre);
		this->indices->cambiarElemento(nombreDelPadre, indiceDeInsercion);

		this->propagarParaArriba(indiceDelPadre);
	}

}


//TODO Probable error de fuera de rango

void Heap::removerMinimo(){


	if(this->estaVacio()){

		throw std::string("No se puede obtener el minimo si el Heap esta vacio");

	}

	NodoHeap<NodoDij*> * aRemover = this->heap[0];

	if(this->tamanio != 1){

		NodoHeap<NodoDij*> * ultimo = this->heap[this->tamanio - 1];
		this->heap[0] = ultimo;
		this->heap[this->tamanio - 1] = NULL;
		std::string verticeUltimo = ultimo->obtenerValor()->getNombre();
		this->indices->cambiarElemento(verticeUltimo, 0);

		this->propagarParaAbajo(0);
	}

	std::string aBorrar = aRemover->obtenerValor()->getNombre();
	this->indices->borrar(aBorrar);

	delete aRemover;
	this->tamanio--;
}



void Heap::propagarParaAbajo(unsigned int indice){

	if(indice == this->tamanio - 1 ||
	   this->tamanio - 1 < (2 * indice) + 2){
		return;
	}

	NodoHeap<NodoDij*> * padre = this->heap[indice];
	NodoHeap<NodoDij*> * hijoIzquierdo = this->heap[(2 * indice) + 1];
	NodoHeap<NodoDij*> * hijoDerecho = this->heap[(2 * indice) + 2];

	std::string papa = padre->obtenerValor()->getNombre();
	std::string izquierdo = hijoIzquierdo->obtenerValor()->getNombre();
	std::string derecho = hijoDerecho->obtenerValor()->getNombre();

	if(this->funcionDeComparacion(hijoIzquierdo, padre)){

		this->heap[indice] = hijoIzquierdo;
		this->heap[(2 * indice) + 1] = padre;
		this->indices->cambiarElemento(izquierdo, indice);
		this->indices->cambiarElemento(papa, (2 * indice) + 1);

		this->propagarParaAbajo((2 * indice) + 1);

	}else if(this->funcionDeComparacion(hijoDerecho, padre)){

		this->heap[indice] = hijoDerecho;
		this->heap[(2 * indice) + 2] = padre;
		this->indices->cambiarElemento(derecho, indice);
		this->indices->cambiarElemento(papa, (2 * indice) + 2);

		this->propagarParaAbajo((2 * indice) + 2);

	}

}



bool Heap::funcionDeComparacion(NodoHeap<NodoDij*> * izquierda, NodoHeap<NodoDij*> * derecha){

	return (*izquierda < *derecha);
}



Heap::~Heap(){


	for(unsigned int i = 0; i < this->tamanio; i++){

		delete this->heap[i];
	}

	delete []this->heap;
}

#endif /* SRC_HEAP_H_ */
