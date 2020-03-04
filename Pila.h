#ifndef SRC_PILA_H_
#define SRC_PILA_H_

#include <string>
#include "Nodo.h"


/*
 * TDA Pila:
 *
 *  Estructura Dinamica de datos de axioma  LIFO
 *
 */

template<class T> class Pila{

	private:

		Nodo<T> * tope;

	public:

		/* Pre:
		 * Post: Crea una Pila vacia
		 */
		Pila();


		/* Pre:
		 * Post: Devuelve true si la pila esta vacia
		 */
		bool estaVacia();


		/* Pre:
		 * Post: Apila el elemento
		 */
		void apilar(T elemento);


		/* Pre: La pila no esta vacia
		 * Post: Desapila el elemento devolviendolo
		 */
		T desapilar();


		/* Pre: La pila no esta vacia
		 * Post: Devuelve el elemneto del tope sin desapilarlo
		 */
		T obtenerTope();


		/* Pre:
		 * Post: Libera los recursos tomados por la estructura
		 */
		~Pila();
};



template<class T>
Pila<T>::Pila(){

	this->tope = NULL;
}


template<class T>
bool Pila<T>::estaVacia(){

	return (this->tope == NULL);
}


template<class T>
void Pila<T>::apilar(T elemento){


	Nodo<T> * nuevoTope = new Nodo<T>(elemento);
	nuevoTope->cambiarSiguiente(this->tope);
	this->tope = nuevoTope;

}


template<class T>
T Pila<T>::desapilar(){

	if(this->estaVacia()){

		throw std::string("No se puede desapilar de una pila vacia");
	}

	Nodo<T> * viejoTope = this->tope;
	this->tope = viejoTope->obtenerSiguiente();
	T elementoDesapilado = viejoTope->obtenerDato();
	delete viejoTope;

	return elementoDesapilado;
}


template<class T>
T Pila<T>::obtenerTope(){

	if(this->estaVacia()){
		throw std::string("No se puede obtener el Tope de una pila vacia");
	}
	return this->tope->obtenerDato();
}


template<class T>
Pila<T>::~Pila(){

	while(!(this->estaVacia())){

		this->desapilar();
	}
}



#endif /* SRC_PILA_H_ */
