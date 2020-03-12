#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
#include "../TDA/Lista.h"

typedef struct GDupla GDupla_t;

#define ERROR -1;



/*Un vértice es un elemento básicos de un grafo, posee un nombre y vértices adyacentes.*/
class Vertice {

	public:
		/* Crea un Vertice con el nombre 'nombre'*/
		Vertice(std::string nombre);

		/* Elimina el Vértice y toda la memoria que se ha utilizado internamente. */
		~Vertice();

		/* Agrega el vértice 'vertice' a la lista de vértices adyacentes con el peso que se pasa por referencia.
			PreCondición: No se llamará más de una vez a esta función con los mismos vértices.
			PostCondición: El vértice 'this' será adyacente a 'vertice' pero no vale la viceversa.
		*/
		void agregarVerticeAdyacente(Vertice* vertice,int peso);

		/* Devuelve true si el vértice 'this' es adyacente al vértice 'vertice'
			En caso caso contrario devuelve false.
		*/
		bool estaVerticeAd(Vertice* vertice);


		/* 	PreCondición: El vértice debe ser adyacentes.
			PostCondición: Devolverá el peso de adyacencia entre ambos vértices. 
		*/
		int pesoVerticeAd(Vertice* vertice);

		/*
			Devuelve una Lista que contiene punteros a los vértices adyacentes del vértice. 
		*/
		Lista<Vertice*>* verticesAd();
		
		/*
			Devuelve el nombre del vértice.
		*/
		std::string getNombre();

	private:

		std::string nombre;

		Lista<GDupla_t*>* adyacentes;
	
		/* Devuelve la dupla vértice - peso, que contiene al vértice 'vertice'.
			En caso de no exitir como adyacente se devuleve un throw diciendo que el vértice no es adyacente.
		*/
		GDupla_t* duplaConVertice(Vertice* vertice);

};



#endif /* VERTCE_H_ */
