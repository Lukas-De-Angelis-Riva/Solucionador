#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <stdlib.h>

/*
 * TDA Nodo:
 * 		Un nodo es un  objeto que guarda un dato y un puntero al siguiente nodo
 *
 */

template<class T>
class Nodo{

	private:

		T dato;
		Nodo * siguiente;

	public:

		/* Pre:-
		 * Post: crea un nodo con el dato presente en el nodo
		 * 		 y un siguiente que apunta a NULL
		 */
		 Nodo(T dato);

		/*
		 * Pre:-
		 * Post: devuelve el dato presente en el nodo
		 */
		T obtenerDato() const;

		/* Pre:-
		 * Post: cambia el dato presente en el nodo con el nuevoDato
		 */
		void cambiarDato(T nuevoDato);

		/* Pre:-
		 * Post: devuelve un puntero al siguiente, ya sea un nodo o un NULL
		 */
		Nodo* obtenerSiguiente() const;

		/* Pre:-
		 * Post: recibe un puntero a un nuevo nodo y cambia el siguiente nodo a este
		 * 		 nuevo puntero
		 */
		void cambiarSiguiente(Nodo * nuevoSiguiente);

};



template<class T>
Nodo<T>::Nodo(T dato){

	this->dato = dato;
	this->siguiente = NULL;
}


template<class T>
T Nodo<T>::obtenerDato() const {

	return this->dato;
}


template<class T>
void Nodo<T>::cambiarDato(T nuevoDato){

	this->dato = nuevoDato;
}


template<class T>
Nodo<T>* Nodo<T>::obtenerSiguiente() const{

	return this->siguiente;
}


template<class T>
void Nodo<T>::cambiarSiguiente(Nodo * nuevoSiguiente){

	this->siguiente = nuevoSiguiente;
}


#endif /* SRC_NODO_H_ */
