#ifndef DFS_NODODFS_H_
#define DFS_NODODFS_H_

#include <string>

/*
 * Un NodoDFS se encarga de guardar informacion importante para
 * poder realizar el algoritmo DFS de busqueda de caminos
 *
 */
class NodoDFS {

	private:

		std::string vertice;
		bool visitado;
		NodoDFS * anterior;

	public:

		/*
		 * Pre:
		 * Post: Se ha creado un NodoDFS con el vertice, si ha sido visitado
		 * 		 y el anterior
		 */
		NodoDFS(std::string vertice, bool visitado, NodoDFS * anterior);

		/*
		 * Pre:
		 * Post: Se ha obtenido el vertice
		 */
		std::string obtenerVertice();

		/*
		 * Pre:
		 * Post: Se ha obtenido si ha sido visitado
		 */
		bool obtenerVistado();

		/*
		 * Pre:
		 * Post: El nodo fueVisitado por lo tanto vistado = true
		 */
		void fueVisitado();

		/*
		 * Pre:
		 * Post: Se ha cambiado el anterior
		 */
		void cambiarAnterior(NodoDFS * nuevoAnterior);

		/*
		 * Pre:
		 * Post: Se ha obtenido el anterior
		 */
		NodoDFS * obtenerAnterior();

		bool operator< (const NodoDFS& derecha);

		/*
		 * Pre:
		 * Post: Se ha liberado los recursos tomados por el NodoDFS
		 */
		~NodoDFS();
};

#endif /* DFS_NODODFS_H_ */
