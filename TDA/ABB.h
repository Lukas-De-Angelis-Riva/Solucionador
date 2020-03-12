#ifndef SRC_ABB_H_
#define SRC_ABB_H_

#include <iostream>
#include "NodoABB.h"
#include "Lista.h"

/*
 *  Un ABB es una estructura dinamica de tipo arbol
 *
 *
 */
template <class T> class ABB{

	private:

		NodoABB<T> * raiz;
		bool (*comparador)(T izquierda, T derecha);

	public:

		/*
		 * Pre:
		 * Post: Crea un arbol sin hijos y con una
		 * 		 funcion comparador por defecto
		 */
		ABB();

		/*
		 * Pre: La funcion comparador devuelve true si
		 * 		 un elemento izquierda < derecha
		 * Post: Crea un arbol sin hijos y con una
		 * 		 funcion comparador pasada por parametro
		 */
		ABB(bool (*comparador)(T izquierda, T derecha));


		/*
		 * Pre:
		 * Post: agrega un elemento al arbol
		 */
		void agregar(T elemento);


		/*
		 * Pre:
		 * Post: Devuelve true si el elemento se encuentra en el arbol
		 */
		bool esta(T elemento);

		/*
		 * Pre: El elemento esta en el arbol
		 * Post: Devuelve el elemento dentro del arbol
		 */
		T buscar(T elemento);

		/*
		 * Pre:
		 * Post: Devuelve true si el arbol esta vacio
		 */
		bool estaVacio();

		/* :(
		 * Pre: El elemento esta en el arbol
		 * Post: Borra el elemento del arbol
		 */
		void borrar(T elemento);


		/*
		 * Pre:
		 * Post: Imprime por pantalla el recorrido preOrder
		 */
		void preOrder(Lista<T> *& aLLenar);


		/*
		 * Pre:
		 * Post: Imprime por pantalla el recorrido inOrder
		 */
		void inOrder(Lista<T> *& aLLenar);


		/*
		 * Pre:
		 * Post: Imprime por pantalla el recorrido postOrder
		 */
		void postOrder(Lista<T> *& aLLenar);


		/*
		 * Pre:
		 * Post: Imprime el arbol
		 */
		void imprimir();



		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el ABB
		 */
		~ABB();


	private:


		/*
		 * Pre:
		 * Post: Imprime el arbol que tiene al nodo como raiz
		 */
		void imprimir(NodoABB<T> * nodo, int contador);


		/*
		 * Pre:
		 * Post: Devuelve el nodo anterior al elemento a agregar
		 */
		NodoABB<T> * buscarAnteriorAAgregar(T elemento);

		/*
		 * Pre:
		 * Post: Agruega el elemento en el arbol que
		 * tiene como raiz al nodo
		 */
		void agregar(NodoABB<T> * &nodo, T elemento);

		/*
		 * Pre:
		 * Post: Devuelve true si el elemento esta en el arbol que
		 * tiene como raiz al nodo
		 */
		bool esta(NodoABB<T> * nodo, T elemento);

		/*
		 * Pre: nodo no es NULL y el elemento esta
		 * Post: Devuelve un puntero al nodo que posee el elemento
		 */
		NodoABB<T> * buscar(NodoABB<T> * nodo, T elemento);

		/*
		 * Pre:
		 * Post: Recorre preOrder el arbol que
		 * tiene como raiz al nodo
		 */
		void preOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar);


		/*
		 * Pre:
		 * Post: Recorre inOrder el arbol que
		 * tiene como raiz al nodo
		 */
		void inOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar);


		/*
		 * Pre:
		 * Post: Recorre postOrder el arbol que
		 * tiene como raiz al nodo
		 */
		void postOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar);


		/*
		 * Pre: aBorrar no es NULL
		 * Post: Se ha borrado el nodo aBorrar
		 */
		void borrar(NodoABB<T> * aBorrar, NodoABB<T> * padre);

		/*
		 * Pre:
		 * Post: Devuelve el padre del elemento
		 */
		NodoABB<T> * obtenerPadre(T elemento);

		/*
		 * Pre:
		 * Post: Devuelve el hijo del padre
		 */
		NodoABB<T> * obtenerHijoDe(NodoABB<T> * padre,T elemento);

		/*
		 * Pre: aBorrar no es NULL
		 * Post: se ha borrado la hoja
		 */
		void borrarHoja(NodoABB<T> * aBorrar, NodoABB<T> * padre);

		/*
		 * Pre: aBorrar no es NULL
		 * Post: se ha borrado aBorrar
		 */
		void borrarPadreConUnHijo(NodoABB<T> * aBorrar, NodoABB<T> * padre);


		/*
		 * Pre: aBorrar no es NULL
		 * Post: se ha borrado aBorrar
		 */
		void borrarPadreConDosHijos(NodoABB<T> * aBorrar, NodoABB<T> * padre);

		/*
		 * Pre: padre no es NULL
		 * Post: Develve el nodo mayorDeLosMenores
		 */
		NodoABB<T> * encontrarMayorDeLosMenores(NodoABB<T> * padre);

		/*
		 * Pre:
		 * Post: Encuentra el padre del mayor de los menores
		 */
		NodoABB<T> * encontrarPadreMayorDeLosMenores(NodoABB<T> * padre);

		/*
		 * Pre:
		 * Post: Se destruye el arbol que tiene como raiz al nodo
		 */
		void destruir(NodoABB<T> * nodo);


};

/*
 * Pre:
 * Post: Devuelve true si izquierda < derecha
 */
template <class T>
bool comparadorABBPorDefecto(T izquierda, T derecha);


template <class T>
ABB<T>::ABB(){


	this->raiz = NULL;
	this->comparador = comparadorABBPorDefecto;

}


template <class T>
ABB<T>::ABB(bool (*comparador)(T izquierda, T derecha)){


	this->raiz = NULL;
	this->comparador = comparador;

}

template <class T>
bool comparadorABBPorDefecto(T izquierda, T derecha){

	return izquierda < derecha;

}



template <class T>
void ABB<T>::agregar(T elemento){


	NodoABB<T> * aAgregar = new NodoABB<T>(elemento);

	if(this->raiz == NULL){

		this->raiz = aAgregar;

	}else{

		NodoABB<T> * anterior = this->buscarAnteriorAAgregar(elemento);

		if(this->comparador(anterior->obtenerDato(), elemento)){

			anterior->cambiarDerecha(aAgregar);

		}else if(this->comparador(elemento, anterior->obtenerDato())){

			anterior->cambiarIzquierda(aAgregar);

		}
	}

}

template <class T>
NodoABB<T> * ABB<T>::buscarAnteriorAAgregar(T elemento){

	NodoABB<T> * actual = this->raiz;
	NodoABB<T> * anterior = NULL;

	while(actual != NULL){

		anterior = actual;

		if(this->comparador(actual->obtenerDato(), elemento)){

			actual = actual->obtenerDerecha();

		}else if(this->comparador(elemento, actual->obtenerDato())){

			actual = actual->obtenerIzquierda();

		}else{

			throw std::string("El elemento ya esta en el arbol");

		}

	}

	return anterior;

}


template <class T>
bool ABB<T>::esta(T elemento){


	return this->esta(this->raiz, elemento);

}

template <class T>
bool ABB<T>::esta(NodoABB<T> * nodo, T elemento){


	if(nodo == NULL){

		return false;

	}else if(this->comparador(nodo->obtenerDato(), elemento)){

		return this->esta(nodo->obtenerDerecha(), elemento);

	}else if(this->comparador(elemento, nodo->obtenerDato())){

		return this->esta(nodo->obtenerIzquierda(), elemento);

	}else{

		return true;
	}
}

template <class T>
T ABB<T>::buscar(T elemento){

	NodoABB<T> * nodo = this->buscar(this->raiz, elemento);
	return nodo->obtenerDato();

}


template <class T>
bool ABB<T>::estaVacio(){

	return this->raiz == NULL;

}


template <class T>
void ABB<T>::preOrder(Lista<T> *& aLLenar){


	this->preOrder(this->raiz, aLLenar);

}


template <class T>
void ABB<T>::inOrder(Lista<T> *& aLLenar){


	this->inOrder(this->raiz, aLLenar);

}


template <class T>
void ABB<T>::postOrder(Lista<T> *& aLLenar){


	this->postOrder(this->raiz, aLLenar);

}


template <class T>
void ABB<T>::preOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar){

	if(nodo != NULL){

		aLLenar->agregar(nodo->obtenerDato());
		preOrder(nodo->obtenerIzquierda(), aLLenar);
		preOrder(nodo->obtenerDerecha(), aLLenar);

	}

}



template <class T>
void ABB<T>::inOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar){

	if(nodo != NULL){

		inOrder(nodo->obtenerIzquierda(), aLLenar);
		aLLenar->agregar(nodo->obtenerDato());
		inOrder(nodo->obtenerDerecha(), aLLenar);

	}

}



template <class T>
void ABB<T>::postOrder(NodoABB<T> * nodo, Lista<T> *& aLLenar){

	if(nodo != NULL){

		postOrder(nodo->obtenerIzquierda(), aLLenar);
		postOrder(nodo->obtenerDerecha(), aLLenar);
		aLLenar->agregar(nodo->obtenerDato());

	}

}



template <class T>
void ABB<T>::imprimir(){


	this->imprimir(this->raiz, 0);

}


template <class T>
void ABB<T>::imprimir(NodoABB<T> * nodo, int contador){


	if(nodo == NULL){

		for(int i=0; i<contador;i++){
			std::cout << ("   ");
		}
		std::cout <<"N" << std::endl;
		return;
	}
	this->imprimir(nodo->obtenerDerecha(), contador + 1);
	for(int i=0; i<contador;i++){
		std::cout << "   ";
	}
	std::cout << nodo->obtenerDato();
	this->imprimir(nodo->obtenerIzquierda(), contador + 1);

}



template <class T>
NodoABB<T> * ABB<T>::buscar(NodoABB<T> * nodo, T elemento){

	if(nodo == NULL){

		throw std::string("No se encuentra el elemento");

	}else if(this->comparador(nodo->obtenerDato(), elemento)){

		return this->buscar(nodo->obtenerDerecha(), elemento);

	}else if(this->comparador(elemento, nodo->obtenerDato())){

		return this->buscar(nodo->obtenerIzquierda(), elemento);

	}else{

		return nodo;

	}
}




template <class T>
void ABB<T>::borrar(T elemento){

	if(this->estaVacio()){

		throw std::string("No se puede borrar el elemento en un arbol vacio");

	}

	NodoABB<T> * padre = this->obtenerPadre(elemento);
	NodoABB<T> * aBorrar = this->obtenerHijoDe(padre, elemento);

	this->borrar(aBorrar, padre);


}

template <class T>
NodoABB<T> * ABB<T>::obtenerPadre(T elemento){

	NodoABB<T> * padre = NULL;
	NodoABB<T> * hijo = this->raiz;

	while(hijo != NULL){


		if(this->comparador(hijo->obtenerDato(), elemento)){

			padre = hijo;
			hijo = hijo->obtenerDerecha();

		}else if(this->comparador(elemento, hijo->obtenerDato())){

			padre = hijo;
			hijo = hijo->obtenerIzquierda();

		}else{

			return padre;
		}

	}

	throw std::string("No se encuentra el elemento a borrar");

}

template <class T>
NodoABB<T> * ABB<T>::obtenerHijoDe(NodoABB<T> * padre,T elemento){

	if(padre == NULL){

		return this->raiz;

	}else if(this->comparador(padre->obtenerDato(), elemento)){

		return padre->obtenerDerecha();

	}else{

		return padre->obtenerIzquierda();

	}

}



template <class T>
void ABB<T>::borrar(NodoABB<T> * aBorrar, NodoABB<T> * padre){

	if(aBorrar->esUnaHoja()){

		this->borrarHoja(aBorrar, padre);

	}else if(aBorrar->tieneDosHijos()){

		this->borrarPadreConDosHijos(aBorrar, padre);

	}else{

		this->borrarPadreConUnHijo(aBorrar, padre);

	}


}

template <class T>
void ABB<T>::borrarHoja(NodoABB<T> * aBorrar, NodoABB<T> * padre){

	if(padre == NULL){

		this->raiz = NULL;

	}else if(padre->obtenerDerecha() == aBorrar){

		padre->cambiarDerecha(NULL);

	}else{

		padre->cambiarIzquierda(NULL);

	}
	delete aBorrar;

}

template <class T>
void ABB<T>::borrarPadreConUnHijo(NodoABB<T> * aBorrar, NodoABB<T> * padre){

	NodoABB<T> * hijo = aBorrar->obtenerHijoUnico();

	if(padre == NULL){

		this->raiz = hijo;

	}else if(padre->obtenerDerecha() == aBorrar){

		padre->cambiarDerecha(hijo);

	}else{

		padre->cambiarIzquierda(hijo);

	}
	delete aBorrar;

}


template <class T>
void ABB<T>::borrarPadreConDosHijos(NodoABB<T> * aBorrar, NodoABB<T> * padre){

	NodoABB<T> * padreMayorDeLosMenores = this->encontrarPadreMayorDeLosMenores(aBorrar);
	NodoABB<T> * mayorDeLosMenores = encontrarMayorDeLosMenores(aBorrar);

	aBorrar->cambiarDato(mayorDeLosMenores->obtenerDato());

	aBorrar = mayorDeLosMenores;

	if(aBorrar->esUnaHoja()){

		this->borrarHoja(aBorrar, padreMayorDeLosMenores);

	}else{

		this->borrarPadreConUnHijo(aBorrar, padreMayorDeLosMenores);

	}
}


template <class T>
NodoABB<T> * ABB<T>::encontrarPadreMayorDeLosMenores(NodoABB<T> * padre){


	NodoABB<T> * hijo = padre->obtenerIzquierda();


	while(hijo->obtenerDerecha() != NULL){

		padre = hijo;

		hijo = hijo->obtenerDerecha();

	}

	return padre;

}

template <class T>
NodoABB<T> * ABB<T>::encontrarMayorDeLosMenores(NodoABB<T> * padre){


	NodoABB<T> * mayorDeLosMenores = padre->obtenerIzquierda();

	while(mayorDeLosMenores->obtenerDerecha() != NULL){

		mayorDeLosMenores = mayorDeLosMenores->obtenerDerecha();

	}

	return mayorDeLosMenores;

}



template <class T>
ABB<T>::~ABB(){

	destruir(this->raiz);

}


template <class T>
void ABB<T>::destruir(NodoABB<T> * nodo){


	if(nodo != NULL){

		this->destruir(nodo->obtenerDerecha());
		this->destruir(nodo->obtenerIzquierda());

		delete nodo;

	}

}







#endif /* SRC_ABB_H_ */
