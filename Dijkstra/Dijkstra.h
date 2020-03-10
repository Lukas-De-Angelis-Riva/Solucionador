#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "../Grafo.h"
#include "../Lista.h"
#include "../global.h"
class Dijkstra {

	public:

		Dijkstra(Grafo* g,std::string v_inicio, std::string v_fin);

		~Dijkstra();

		void resolver();

		Lista<std::string>* getResultado();


	private:

		std::string partida;

		std::string llegada;

		Grafo* grafo;

		Lista<std::string>* resultado;

};
#endif /* DIJKSTRA_H_ */
