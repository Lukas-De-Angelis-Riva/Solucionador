#ifndef DFS_DFS_H_
#define DFS_DFS_H_

#include "../Grafo/Grafo.h"
#include <string>
#include "NodoDFS.h"
#include "../TDA/Lista.h"
#include "../TDA/Pila.h"


/*
 * En busqueda de caminos dados un inicio y un fin, DFS se encarga
 * de encontrar un camino a ciegas priorizando alejarse lo maximo posible
 * del inicio
 */
class DFS {

	private:

		Grafo * grafo;
		std::string inicio;
		std::string fin;
		Lista<std::string> * solucion;

	public:

		/*
		 * Pre: En el grafo se encuentran el inicio y el fin
		 * Post: Se ha creado un DFS en condiciones de resolver
		 */
		DFS(Grafo * grafo, std::string inicio, std::string fin);

		/*
		 * Pre:
		 * Post: Se ha resuelto el camino
		 */
		void resolver();

		/*
		 * Pre: Se ha resuelto el camino
		 * Post: Se ha obtenido el resultado
		 */
		Lista<std::string> * obtenerResultado();

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por DFS
		 */
		~DFS();

	private:

		/*
		 * Pre:
		 * Post: Se crea un hash de nodos
		 */
		Hash<NodoDFS*>* crearHashDeNodos();

		/*
		 * Pre:
		 * Post: Se obtiene una lista de nodos adyacentes a actual
		 */
		Lista<NodoDFS*>* obtenerNodosAdyacentes(Hash<NodoDFS*>* hash, NodoDFS* actual);

		/*
		 * Pre:
		 * Post: Se ha armado el camino de principio a fin
		 */
		Lista<std::string> * armarResultado(NodoDFS* fin);

		/*
		 * Pre:
		 * Post: Se ha liberado el hash
		 */
		void liberarHash(Hash<NodoDFS*>* hash);
};

#endif /* DFS_DFS_H_ */
