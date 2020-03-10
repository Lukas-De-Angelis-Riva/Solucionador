#ifndef GRAFO_H_
#define GRAFO_H_

#include <string>
#include <math.h>
#include "Vertice.h"
#include "Lista.h"

class Grafo{
	private:

		Lista<Vertice*>* vertices;

		Vertice* obtenerVertice(std::string nombre);

	public:

		Grafo();

		~Grafo();

		void ingresarVertice(std::string nombre);

		void ingresarArista(std::string v1, std::string v2, int peso);


		bool estaVertice(std::string v);

		bool sonAdyacentes(std::string v1, std::string v2);

		float pesoAdyacentes(std::string v1, std::string v2);

		Lista<std::string>* obtenerVertices();
	
		Lista<std::string>* adyacentesAlVertice(std::string v);


};

#endif /* GRAFO_H_ */
