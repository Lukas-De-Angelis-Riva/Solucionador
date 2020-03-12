#ifndef SELECCIONADOR_H_
#define SELECCIONADOR_H_

#include "../Grafo/Grafo.h"
#include "../Dijkstra/Dijkstra.h"
#include "../global.h"

/*
 * Un Seleccionador se encarga de elegir el metodo para
 * solucionar el laberinto dependiendo de la eleccion del
 * usuario
 */
class Seleccionador {

	private:

		Lista<std::string> * solucion;
		Grafo * grafo;
		std::string inicio;
		std::string fin;
		Dijkstra * dijkstra;
		//DFS * dfs;
		//BFS * bfs;
		//AEstrella * aEstrella;

	public:

		/*
		 * Pre: inicio y fin son vertices del grafo
		 * Post: Se ha creado un seleccionadoren condiciones de
		 * 		 resolver
		 */
		Seleccionador(Grafo * grafo, std::string inicio, std::string fin);

		/*
		 * Pre:
		 * Post: Se ha resuelto el laberinto
		 */
		void resolver(int metodo);

		/*
		 * Pre: Se ha resolvido el laberinto
		 * Post: Devuelve la solucion del laberinto
		 */
		Lista<std::string> * obtenerSolucion();

		/*
		 * Pre:
		 * Post: Libera recursos tomados por el Seleccionador
		 */
		~Seleccionador();

	private:

		/*
		 * Pre:
		 * Post: Se ha solucionado el laberinto
		 * 		 con Dijkstra
		 */
		void solucionarConDijkstra();

		/*
		 * Pre:
		 * Post: Se ha solucionado el laberinto
		 * 		 con DFS
		 */
		void solucionarConDFS();

		/*
		 * Pre:
		 * Post: Se ha solucionado el laberinto
		 * 		 con BFS
		 */
		void solucionarConBFS();

		/*
		 * Pre:
		 * Post: Se ha solucionado el laberinto
		 * 		 con A*
		 */
		void solucionarConAEstrella();
};

#endif /* SELECCIONADOR_H_ */
