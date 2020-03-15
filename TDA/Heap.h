#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include "../Dijkstra/NodoDij.h"
#include "NodoHeap.h"
#include "Hash.h"

class Heap{

	private:

		unsigned int capacidad;
		unsigned int tamanio;
		NodoHeap<NodoDij*> ** heap;
		Hash<int> * indices;

	public:

		/*
		 * Pre:
		 * Post: Se crea un heap vacio
		 */
		Heap();

		/*
		 * Pre:
		 * Post: Devuelve true si esta vacio
		 */
		bool estaVacio();

		/*
		 * Pre:
		 * Post: Se ha insertado un elemento
		 */
		void insertar(float clave, NodoDij* elemento);

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve el elemento minimo
		 */
		NodoDij* obtenerElementoMinimo();

		/*
		 * Pre: El elemento esta en el heap y la nuevaClave es minima
		 * Post: Se disminuido la clave y actualizado el heap
		 */
		void disminuirClave(NodoDij* elemento, float nuevaClave);

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Devuelve la clave minima
		 */
		float obtenerClaveMinima();

		/*
		 * Pre: El Heap no estaVacio
		 * Post: Se ha removido el minimo
		 */
		void removerMinimo();

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el Heap
		 */
		~Heap();

	private:

		/*
		 * Pre:
		 * Post: Se ha incrementado la capacidad del Heap
		 */
		void expandirHeap();

		/*
		 * Pre: Se ha insertado en el heap en el indiceDeInsercion
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaArriba(unsigned int indiceDeInsercion);

		/*
		 * Pre: Se ha removido el elemento minimo
		 * Post: Se ha restaurado el heap
		 */
		void propagarParaAbajo(unsigned int indice);

		/*
		 * Pre:
		 * Post: Devuelve true si izquierda < derecha
		 */
		bool funcionDeComparacion(NodoHeap<NodoDij*> * izquierda, NodoHeap<NodoDij*> * derecha);

		/*
		 * Pre:
		 * Post: Intercambio las posiciones cuando propago para abajo
		 */
		void intercambiar(NodoHeap<NodoDij*> * padre, NodoHeap<NodoDij*> * hijo,
						  unsigned int indicePadre, unsigned int indiceHijo);

};


#endif /* SRC_HEAP_H_ */
