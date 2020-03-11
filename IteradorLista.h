#ifndef SRC_ITERADORLISTA_H_
#define SRC_ITERADORLISTA_H_

#include "Lista.h"


template <class T> class IteradorLista{

	private:

		Lista<T> * lista;
		Nodo<T> * cursor;

	public:

		/*
		 * Pre:
		 * Post: Se ha creado un iterador sobre lista
		 */
		IteradorLista(Lista<T> * lista);

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

		/*
		 * Pre:
		 * Post: Se ha liberado los recursos tomados por el Iterador
		 */
		~IteradorLista();
};

template <class T>
IteradorLista<T>::IteradorLista(Lista<T> * lista){

	this->lista = lista;
	this->cursor = NULL;
}

template <class T>
void IteradorLista<T>::iniciarCursor(){

	this->cursor = NULL;
}

template <class T>
bool IteradorLista<T>::avanzarCursor(){


	if (this->cursor == NULL){

		this->cursor = this->lista->primero;

	}else{

		this->cursor = this->cursor->obtenerSiguiente();

	}

	return (this->cursor != NULL);
}

template <class T>
T IteradorLista<T>::obtenerCursor(){

	if (this->cursor == NULL){

		throw std::string("Posicion invalida al obtener cursor");

	}

	return this->cursor->obtenerDato();

}

template <class T>
IteradorLista<T>::~IteradorLista(){


}


#endif /* SRC_ITERADORLISTA_H_ */
