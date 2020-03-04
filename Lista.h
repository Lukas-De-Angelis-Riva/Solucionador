#ifndef SRC_LISTA_H_
#define SRC_LISTA_H_

#include <string>

#include "Nodo.h"


/*
 *
 *  Una Lista es una colección dinámica de elementos dispuestos en una secuencia.
 *	Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */


template<class T>
class Lista{

	private:

		Nodo<T> * primero;
		Nodo<T> * ultimo;
		unsigned int tamanio;
		Nodo<T> * cursor;

	public:


	/* Pre:
	 * Post: Crea una lista vacia
	 */
	Lista();


	/* Pre:
	 * Post: Crea una lista copiando lo de otraLista
	 */
	Lista(Lista& otraLista);


	/* Pre:
	 * Post: Agrega un elemento al fina de la lista
	 */
	void agregar(T elemento);


	/* Pre: Posicion pertenece al intervalo [1, cantidadElementos() + 1]
	 * Post: Agrega el elemento en la posicion indicada desplazando a los demas
	 */
	void agregar(T elemento, unsigned int posicion);


	/* Pre:
	 * Post: Agrega otraLista al final de la Lista
	 */
	void agregar(Lista& otraLista);

	/* Pre: Posicion pertenece al intervalo [1, contarElementos()]
	 * Post: Remplaza el elemento en posicion con nuevoElemento
	 */
	void asignar(T elemento, unsigned int posicion);


	/* Pre: Posicion pertenece al intervalo [1, contarElementos()]
	 * Post: Devuelve el elemento en esa posicion
	 */
	T obtener(unsigned int posicion);


	/* Pre: Posicion pertenece al intervalo [1, contarElementos()]
	 * Post: Remueve el elemento desplazando a los demas
	 */
	void remover(unsigned int posicion);


	/* Pre:
	 * Post: Devuelve true si estaVacia
	 */
	bool estaVacia() const;


	/* Pre:
	 * Post: Devuelve la cantidaElementos
	 */
	unsigned int cantidadElementos() const;


	/* Pre:
	 * Post: incial el cursor para poder avanzarCursor
	 */
	void iniciarCursor();


	/* Pre: Se ha iniciado el cursor y desde entonces no se han removido o
	 * agregado elementos
	 * Post: Avanza el cursor devolviendo true si esta sobre un elemento
	 *  o false si se encuentra apuntando a NULL
	 */
	bool avanzarCursor();


	/* Pre: Se ha iniciado el cursor y se ha avanzado el cursor
	 * Post: Devuelve el elemento al que apunta el cursor
	 */
	T obtenerCursor();


	/* Pre:
	 * Post: Libera los recursos tomados por la Lista
	 */
	~Lista();

	private:


	/* Pre: Posicion pertenece al intervalo [1, cantidadElementos()]
	 * Post: Devuelve un puntero al nodo en dicha posicion
	 */
	Nodo<T> * obtenerNodo(unsigned int posicion);

};



template<class T>
Lista<T>::Lista(){

	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
	this->cursor = NULL;
}


template<class T>
Lista<T>::Lista(Lista<T> & otraLista){

	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
	this->cursor = NULL;

	this->agregar(otraLista);
}


template<class T>
void Lista<T>::agregar(T elemento){

	this->agregar(elemento, this->cantidadElementos() + 1);
}


template<class T>
Nodo<T> * Lista<T>::obtenerNodo(unsigned int posicion){

	Nodo<T> * actual = this->primero;

	for(unsigned int posicionActual = 1; posicionActual < posicion; posicionActual++){

		actual = actual->obtenerSiguiente();
	}

	return actual;
}


template<class T>
void Lista<T>::agregar(T elemento, unsigned int posicion){


	if(posicion < 1 || posicion > this->cantidadElementos() + 1){

		throw std::string("Posicion invalida al agregar");
	}

	Nodo<T> * aAgregar = new Nodo<T>(elemento);

	if(posicion == 1){

		aAgregar->cambiarSiguiente(this->primero);
		this->primero = aAgregar;
		this->ultimo = aAgregar;

	}else if(posicion == this->cantidadElementos() + 1){

		this->ultimo->cambiarSiguiente(aAgregar);
		this->ultimo = aAgregar;

	}else{

		Nodo<T> * anterior = this->obtenerNodo(posicion - 1);
		aAgregar->cambiarSiguiente(anterior->obtenerSiguiente());
		anterior->cambiarSiguiente(aAgregar);

	}

	this->tamanio++;
	this->iniciarCursor();

}


template<class T>
void Lista<T>::agregar(Lista& otraLista){


	otraLista.iniciarCursor();

	while(otraLista.avanzarCursor()){

		this->agregar(otraLista.obtenerCursor());
	}
}


template<class T>
void Lista<T>::asignar(T elemento, unsigned int posicion){

	if(posicion < 1 || posicion > this->cantidadElementos()){

		throw std::string("Posicion invalida al asignar");
	}

	Nodo<T> * actual = this->obtenerNodo(posicion);
	actual->cambiarDato(elemento);

}


template<class T>
T Lista<T>::obtener(unsigned int posicion){

	if(posicion < 1 || posicion > this->cantidadElementos()){

		throw std::string("Posicion invalida al obtener");
	}

	Nodo<T> * actual = this->obtenerNodo(posicion);
	return actual->obtenerDato();


}


template<class T>
void Lista<T>::remover(unsigned int posicion){


	if(this->estaVacia() || posicion < 1 || posicion > this->cantidadElementos()){

		throw std::string("Posicion invalida al remover");
	}

	Nodo<T> * nodoARemover;

	if(posicion == 1){

		nodoARemover = this->primero;
		this->primero == nodoARemover->obtenerSiguiente();

		if(this->cantidadElementos() == 1){
			this->ultimo = NULL;
		}

	}else{

		Nodo<T> * anterior = this->obtenerNodo(posicion - 1);
		nodoARemover = anterior->obtenerSiguiente();
		anterior->cambiarSiguiente(nodoARemover->obtenerSiguiente());

		if(this->cantidadElementos() == posicion){

			this->ultimo = anterior;

		}

	}

	delete nodoARemover;
	this->tamanio--;
	this->iniciarCursor();

}


template<class T>
bool Lista<T>::estaVacia() const{

	return (this->primero == NULL);
}


template<class T>
unsigned int Lista<T>::cantidadElementos() const{

	return this->tamanio;
}



template<class T>
void Lista<T>::iniciarCursor(){

	this->cursor = NULL;
}


template<class T>
bool Lista<T>::avanzarCursor(){


	if (this->cursor == NULL){

		this->cursor = this->primero;

	}else{

		this->cursor = this->cursor->obtenerSiguiente();

	}

	return (this->cursor != NULL);
}


template<class T>
T Lista<T>::obtenerCursor(){

	if (this->cursor == NULL){

		throw std::string("Posicion invalida al obtener cursor");

	}

	return this->cursor->obtenerDato();

}


template<class T>
Lista<T>::~Lista(){

	while(this->primero != NULL){

		Nodo<T> * NodoABorrar = this->primero;

		this->primero = this->primero->obtenerSiguiente();

		delete NodoABorrar;
	}
	this->ultimo = NULL;
}




#endif /* SRC_LISTA_H_ */
