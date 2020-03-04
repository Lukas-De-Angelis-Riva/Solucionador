#ifndef SRC_COLA_H_
#define SRC_COLA_H_

#include "Nodo.h"
#include <string>



/*
 * Una Cola es una estructura dinámica de datos organizada de acuerdo al
 * principio FIFO (First In - First Out).
 *
 */
template<class T>
class Cola{

	private:

		Nodo<T> * frente;
		Nodo<T> * fondo;

	public:


		/* Pre:
		 * Post: Crea una cola vacia
		 */
		Cola();


		/* Pre:
		 * Post: Acola un elemento al fondo de la cola
		 */
		void acolar(T elemento);


		/* Pre:
		 * Post: Descola un elemento al frente de la cola
		 */
		T desacolar();


		/* Pre: La cola no esta vacia
		 * Post: Devuelve el frente de la cola sin desacolarlo
		 */
		T obtenerFrente();


		/* Pre:
		 * Post: Devuelve true si la cola esta vacia
		 */
		bool estaVacia();


		/* Pre:
		 * Post: Libera los recursos tomados
		 */
		~Cola();

};


template<class T>
Cola<T>::Cola(){

	this->frente = NULL;
	this->fondo = NULL;
}


template<class T>
bool Cola<T>::estaVacia(){

	return this->frente == NULL;
}


template<class T>
T Cola<T>::obtenerFrente(){

	if(this->estaVacia()){

		throw std::string("No se puede obtener el frente de una cola vacia");
	}

	return this->frente->obtenerDato();
}


template<class T>
void Cola<T>::acolar(T elemento){

	Nodo<T> * nuevoFondo = new Nodo<T>(elemento);

	if(this->estaVacia()){

		this->frente = nuevoFondo;

	}else{

		this->fondo->cambiarSiguiente(nuevoFondo);
	}

	this->fondo = nuevoFondo;
}


template<class T>
T Cola<T>::desacolar(){

	if (this->estaVacia()){

		throw std::string("No se puede desacolar en una cola vacia");
	}

	Nodo<T> * viejoFrente = this->frente;
	this->frente = viejoFrente->obtenerSiguiente();

	if(this->frente == NULL){

		this->fondo = NULL;
	}

	T elementoDesacolado = viejoFrente->obtenerDato();
	delete viejoFrente;
	return elementoDesacolado;

}


template<class T>
Cola<T>::~Cola(){

	while(!(this->estaVacia())){

		this->desacolar();
	}
}




#endif /* SRC_COLA_H_ */
