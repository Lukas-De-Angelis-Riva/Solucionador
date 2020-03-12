#ifndef HASH_H_
#define HASH_H_

#include "ABB.h"
#include "NodoHash.h"


#define VALOR_CUALQUIERA 0
const int NUMERO_PRIMO = 37;

/*
 * Una tabla de hash sirve para almacenar elementos
 * y recuperarlos rapidamente
 *
 * Es obligatorio que el tipo de dato T
 * tenga el operador <
 *
 *
 */
template <class T> class Hash{

	private:

		ABB<NodoHash<T>* > ** tabla;
		unsigned int capacidad;
		unsigned int tamanio;

	public:

		/*
		 * Pre:
		 * Post: Crea un hash vacio
		 */
		Hash();

		//TODO REHASH
		/*
		 * Pre: El elemento no esta en el hash
		 * Post: Se ha agregado el elemento al hash
		 */
		void agregar(std::string clave, T elemento);

		/*
		 * Pre:
		 * Post: Devuelve true si el elemento esta en el hash
		 */
	    bool esta(std::string clave);

		/*
		 * Pre:
		 * Post: Devuelve true si estaVacio
		 */
		bool estaVacio();

		/*
		 * Pre: El elemento esta en el hash
		 * Post: Se ha devuelto el elemento encontrado
		 */
		T buscar(std::string clave);

		/*
		 * Pre:
		 * Post: Devuelve la cantidad de elementos presentes en el hash
		 */
		unsigned int obtenerTamanio();

		/*
		 * Pre:
		 * Post: Se ha llenado la lista con los elementos dentro del hash
		 */
		void recorrer(Lista<T> *& aLLenar);


		/*
		 * Pre: El elemento esta en el hash
		 * Post: Se ha borrado el elemento
		 */
		void borrar(std::string clave);

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el hash
		 */
		~Hash();

	private:

		/*
		 * Pre:
		 * Post: Se ha llenado la lista con los elementos dentro del hash
		 */
		void recorrer(Lista<NodoHash<T> * > *& aLLenar);

		/*
		 * Pre:
		 * Post: Devuelve un numero entero entre [0 - capacidad]
		 */
		unsigned int funcionHash(std::string clave);


};

template <class T>
bool funcionDeComparacion(NodoHash<T> * izquierda, NodoHash<T> * derecha){


	return ((*izquierda) < (*derecha));
}



template <class T>
Hash<T>::Hash(){

	this->capacidad = NUMERO_PRIMO;
	this->tamanio = 0;
	this->tabla = new ABB<NodoHash<T>* >*[this->capacidad];
	for(unsigned int i = 0; i < this->capacidad; i++){

		this->tabla[i] = NULL;

	}
}


template <class T>
unsigned int Hash<T>::funcionHash(std::string clave){

	unsigned int posicion = atoi(clave.c_str()) % this->capacidad;

	return posicion;

}


template <class T>
void Hash<T>::agregar(std::string clave, T elemento){


	unsigned int posicion = this->funcionHash(clave);
	ABB<NodoHash<T>* > * & lugarDeLaTabla = this->tabla[posicion];

	if(lugarDeLaTabla == NULL)
		lugarDeLaTabla = new ABB<NodoHash<T> * >(funcionDeComparacion);

	NodoHash<T> * aAgregar = new NodoHash<T>(clave, elemento);

	lugarDeLaTabla->agregar(aAgregar);
	this->tamanio++;


}

template <class T>
T Hash<T>::buscar(std::string clave){

	unsigned int posicion = this->funcionHash(clave);
	ABB<NodoHash<T> * > * lugarDeLaTabla = this->tabla[posicion];
	NodoHash<T> * datoSimilar = new NodoHash<T>(clave, VALOR_CUALQUIERA);

	if(lugarDeLaTabla == NULL)
		throw std::string("No esta el elemento al buscarlo");

	NodoHash<T> * encontrado = lugarDeLaTabla->buscar(datoSimilar);

	delete datoSimilar;
	return encontrado->obtenerValor();

}

template <class T>
bool Hash<T>::esta(std::string clave){

	unsigned int posicion = this->funcionHash(clave);
	ABB<NodoHash<T> * > * lugarDeLaTabla = this->tabla[posicion];
	NodoHash<T> * datoSimilar = new NodoHash<T>(clave, VALOR_CUALQUIERA);

	bool esta = false;

	if(lugarDeLaTabla != NULL)
		esta = lugarDeLaTabla->esta(datoSimilar);

	delete datoSimilar;

	return esta;

}

template <class T>
unsigned int Hash<T>::obtenerTamanio(){

	return this->tamanio;
}

template <class T>
bool Hash<T>::estaVacio(){

	return this->tamanio == 0;

}

template <class T>
void Hash<T>::recorrer(Lista<T> *& aLLenar){

	Lista<NodoHash<T> * > * lista = new Lista<NodoHash<T> * >;
	this->recorrer(lista);

	lista->iniciarCursor();
	while(lista->avanzarCursor()){

		NodoHash<T> * nodo = lista->obtenerCursor();
		aLLenar->agregar(nodo->obtenerValor());

	}

	delete lista;
}

template <class T>
void Hash<T>::recorrer(Lista<NodoHash<T> * > *& aLLenar){


	for(unsigned int i = 0; i < this->capacidad; i++){

		if(this->tabla[i] != NULL){

			ABB<NodoHash<T> * > * lugarDeLaTabla = this->tabla[i];
			lugarDeLaTabla->inOrder(aLLenar);

		}
	}
}


template <class T>
void Hash<T>::borrar(std::string clave){


	unsigned int posicion = this->funcionHash(clave);
	ABB<NodoHash<T> * > *& lugarDeLaTabla = this->tabla[posicion];
	NodoHash<T> * datoSimilar = new NodoHash<T>(clave, VALOR_CUALQUIERA);

	if (lugarDeLaTabla == NULL)
		throw std::string("No esta el elemento al borrarlo");

	NodoHash<T> * aBorrar = lugarDeLaTabla->buscar(datoSimilar);
	lugarDeLaTabla->borrar(aBorrar);
	delete aBorrar;
	delete datoSimilar;

}

template <class T>
Hash<T>::~Hash(){


	Lista<NodoHash<T> * > * lista = new Lista<NodoHash<T> * >;
	this->recorrer(lista);

	lista->iniciarCursor();
	while(lista->avanzarCursor()){

		delete lista->obtenerCursor();
	}

	for(unsigned int i = 0; i < this->capacidad; i++){

		if(this->tabla[i] != NULL)
			delete this->tabla[i];

	}
	delete []this->tabla;
	delete lista;
}


#endif /* HASH_H_ */
