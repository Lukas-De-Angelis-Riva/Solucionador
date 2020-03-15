#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "NodoDij.h"
#include "../Grafo/Grafo.h"
#include "../TDA/Lista.h"
#include "../global.h"
#include "../TDA/Hash.h"
#include "../TDA/Heap.h"

/* El algoritmo de Dijkstra se encarga de encontrar el camino más corto entre dos vértices (vIncio y vFin) en un grafo;
	este puede no ser único, pero todos ellos tendrán el mismo largo.
*/
class Dijkstra{

	public:
		/*Crea la estructura de Dijkstra. vInicio será el vértice partida y vFin el vértice llegada.*/
		Dijkstra(Grafo* g,std::string vInicio, std::string vFin);

		/*Elimina a Dijkstra y libera toda la memoria reservada por la clase.*/
		~Dijkstra();
		
		/* Resuelve el problema y lo guarda en resultado.
			Precondición: se llamará solo una vez al método.
		*/
		void resolver();
		
		/*Devuelve el resultado. Primero se debe llamar a resolver, de lo contrario resultado estará vacio.*/
		Lista<std::string>* getResultado();

		int getLargoCamino();

	private:

		std::string partida;

		std::string llegada;

		Grafo* grafo;

		Lista<std::string>* resultado;

		int largoCamino;

		Hash<NodoDij*>* crearHashClave_nodoDij();

		Heap* crearHeapCandidatos(Hash<NodoDij*>* hash);

		Lista<NodoDij*>* obtenerNodosAdyacentes(Hash<NodoDij*>* hash, NodoDij* nodoActual);

		bool mejoraDis(NodoDij* n1, NodoDij* n2);

		void actualizarPeso(NodoDij* llegada, NodoDij* salida);

		void actualizarNodoAnt(NodoDij* llegada, NodoDij* salida);

};
#endif /* DIJKSTRA_H_ */