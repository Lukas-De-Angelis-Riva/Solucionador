#ifndef GRAFO_H_
#define GRAFO_H_

#include <string>
#include <math.h>
#include "Vertice.h"
#include "../TDA/Lista.h"
#include "../TDA/Hash.h"


/*
	Un grafo se define como un par de conjuntos, los vértices y las aristas, y de una función de emparejamiento.
	Se ha optado por la implementación del grafo como un conjunto de vértices que poseen vértices adyacentes simulando las aristas.
	El grafo se encargará de manipular los vértices. Dos vértices del mismo nombre serán el mismo vértice.
	Insertar dos vértices iguales (mismo nombre) puede afectar al correcto funcionamiento del grafo.
	El grafo sera pesado, es decir, las aristas poseeran peso.
	En caso de que dos vértices no sean adyacenentes se considera que el peso es infinito y se utiliza la constante INFINITY de math.h
*/
class Grafo{
	private:

		Hash<Vertice*>* vertices;

		Vertice* obtenerVertice(std::string nombre);

	public:
		
		/* Crea un grafo vacio,*/
		Grafo();
		
		/*Elimina el grafo, y toda la memoria que se ha utlizado internamiente*/
		~Grafo();
		
		/*Ingresa un vértice al grafo, éste será un vértice aislado.
			Precond: Dos vértices no poseen el mismo nombre.
		*/
		void ingresarVertice(std::string nombre);
		
		/*Ingresa una arista entre dos vértices.
		  En caso de que sean el mismo vértice no se hará nada. (por definicion un vértice es adyacente a sí mismo con peso 0).
		  En caso de que ya sean adyacentes no se hará nada. (no se actualizará el peso).
		  El grafo NO es dirigido, por lo cual v1 será adyacente a v2 y viceversa.
		*/
		void ingresarArista(std::string v1, std::string v2, int peso);

		/*Devuelve true si el vértice pertenece al grafol.*/
		bool estaVertice(std::string v);

		/*Devuelve true si dos vértices son adyancentes.
			En caso de ser el mismo vértice se devolverá true.
		*/
		bool sonAdyacentes(std::string v1, std::string v2);

		/*Devuelve un float con el peso que une ambos vértices.
			En caso de ser el mismo vértice se devolverá 0.
			En caso de ser dos vértices no adyacentes, se devolverá la constante INFINITY de la biblioteca math.h.
		*/
		float pesoAdyacentes(std::string v1, std::string v2);

		/*Devuelve una Lista de strings representando los nombres de los vértices que pertenecen al grafo. */
		Lista<std::string>* obtenerVertices();

		/*Devuelve la cantidad de vértices que posee el grafo.*/
		int cantidadVertices();
		
		/*Devuelve una lista con strings representando los nombres de los vértices que son adyacentes al vértice v. */
		Lista<std::string>* adyacentesAlVertice(std::string v);


};

#endif /* GRAFO_H_ */
