#include "Heap.h"

Heap::Heap(){
	this->capacidad = 3;
	this->tamanio = 0;
	this->heap = new NodoHeap<NodoDij*>*[this->capacidad];
	this->indices = new Hash<int>;
}



bool Heap::funcionDeComparacion(NodoHeap<NodoDij*> * izquierda, NodoHeap<NodoDij*> * derecha){

	return (*izquierda < *derecha);
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

Heap::~Heap(){


	for(unsigned int i = 0; i < this->tamanio; i++){

		delete this->heap[i];
	}

	delete []this->heap;
	delete this->indices;
}