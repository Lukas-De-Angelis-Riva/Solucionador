#ifndef SRC_NODOABB_H_
#define SRC_NODOABB_H_



/*
 *
 *  Un NodoABB guarda un dato y tiene tres punteros uno
 *  al padre y otros dos a sus hijos
 *
 *
 */
template <class T> class NodoABB{

	private:

		T dato;
		NodoABB<T> * izquierda;
		NodoABB<T> * derecha;

	public:


		/*
		 * Pre:
		 * Post: Crea un NodoABB con el dato y sin padre ni hijos
		 */
		NodoABB(T dato);

		/*
		 * Pre:
		 * Post: Devuelve el dato del nodo
		 */
		T obtenerDato();


		/*
		 * Pre:
		 * Post: Cambia el dato por nuevoDato
		 *
		 */
		void cambiarDato(T nuevoDato);


		/*
		 * Pre:
		 * Post: Devuelve un puntero al nodo de la izquierda
		 */
		NodoABB<T> * obtenerIzquierda();


		/*
		 * Pre:
		 * Post: Cambia el hijo izquierdo del nodo
		 */
		void cambiarIzquierda(NodoABB<T> * nuevoHijo);


		/*
		 * Pre:
		 * Post: Devuelve un puntero al nodo de la derecha
		 */
		NodoABB<T> * obtenerDerecha();


		/*
		 * Pre:
		 * Post: Cambia el hijo derecho del nodo
		 */
		void cambiarDerecha(NodoABB<T> * nuevoHijo);

		/*
		 * Pre:
		 * Post: Devuelve true si esUnaHoja
		 */
		bool esUnaHoja();

		/*
		 * Pre:
		 * Post: Devuelve true si tieneUnHijo
		 */
		bool tieneUnHijo();

		/*
		 * Pre:
		 * Post: Devuelve true si tieneDosHijos
		 */
		bool tieneDosHijos();

		/*
		 * Pre: El nodo tieneUnHijo
		 * Post: Devuelve un puntero al HijoUnico
		 */
		NodoABB<T> * obtenerHijoUnico();

};


template <class T>
NodoABB<T>::NodoABB(T dato){

	this->dato = dato;
	this->derecha = NULL;
	this->izquierda = NULL;
}


template <class T>
T NodoABB<T>::obtenerDato(){

	return this->dato;
}


template <class T>
void NodoABB<T>::cambiarDato(T nuevoDato){

	this->dato = nuevoDato;
}



template <class T>
NodoABB<T> * NodoABB<T>::obtenerIzquierda(){

	return this->izquierda;
}


template <class T>
void NodoABB<T>::cambiarIzquierda(NodoABB<T> * nuevoHijo){

	this->izquierda = nuevoHijo;
}




template <class T>
NodoABB<T> * NodoABB<T>::obtenerDerecha(){


	return this->derecha;
}


template <class T>
void NodoABB<T>::cambiarDerecha(NodoABB<T> * nuevoHijo){

	this->derecha = nuevoHijo;

}



template <class T>
bool NodoABB<T>::esUnaHoja(){

	return this->izquierda == NULL && this->derecha == NULL;
}

template <class T>
bool NodoABB<T>::tieneUnHijo(){

	return this->izquierda == NULL || this->derecha == NULL;

}

template <class T>
bool NodoABB<T>::tieneDosHijos(){

	return this->izquierda != NULL && this->derecha != NULL;

}

template <class T>
NodoABB<T> * NodoABB<T>::obtenerHijoUnico(){

	if(this->izquierda == NULL){

		return this->derecha;
	}

	return this->izquierda;
}

#endif /* SRC_NODOABB_H_ */
