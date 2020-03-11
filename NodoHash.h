#ifndef SRC_NODOHASH_H_
#define SRC_NODOHASH_H_


template <class T> class NodoHash{

	private:

		std::string clave;
		T valor;

	public:

		/*
		 * Pre:
		 * Post: Se ha creado un NodoDiccionario
		 */
		NodoHash(std::string clave, T valor);

		/*
		 * Pre:
		 * Post: Devuelve la clave
		 */
		std::string obtenerClave() const;

		/*
		 * Pre:
		 * Post: Devuelve el valor
		 */
		T obtenerValor() const;

		/*
		 * Pre:
		 * Post: Se ha cambiado el valor
		 */
		void cambiarValor(T nuevoValor);

		bool operator< (const NodoHash& derecha);

		NodoHash& operator =(const NodoHash& otro);

		/*
		 * Pre:
		 * Post: Se han liberado los recursos tomados por el NodoDiccionario
		 */
		~NodoHash();

};

template <class T>
NodoHash<T>::NodoHash(std::string clave, T valor){

	this->clave = clave;
	this->valor = valor;

}

template <class T>
std::string NodoHash<T>::obtenerClave() const{

	return this->clave;
}

template <class T>
T NodoHash<T>::obtenerValor() const{

	return this->valor;
}


template <class T>
void NodoHash<T>::cambiarValor(T nuevoValor){

	this->valor = nuevoValor;
}

template <class T>
NodoHash<T>::~NodoHash(){


}

template <class T>
bool NodoHash<T>::operator< (const NodoHash& derecha){

	return (this->obtenerClave() < derecha.obtenerClave());
}


template <class T>
NodoHash<T>& NodoHash<T>::operator =(const NodoHash& otro){

	this->clave = otro.obtenerClave();
	this->valor = otro.obtenerValor();
	return (*this);

}

#endif /* SRC_NODOHASH_H_ */
