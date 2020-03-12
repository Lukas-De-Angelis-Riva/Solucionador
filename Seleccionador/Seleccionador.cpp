#include "Seleccionador.h"

Seleccionador::Seleccionador(Grafo * grafo, std::string inicio, std::string fin) {

	this->grafo = grafo;
	this->solucion = NULL;
	this->inicio = inicio;
	this->fin = fin;
	this->dijkstra = new Dijkstra(this->grafo, this->inicio, this->fin);
}


void Seleccionador::resolver(int metodo){

	switch(metodo){

		case METODO_DIJKSTRA: this->solucionarConDijkstra();
		break;
		case METODO_DFS: this->solucionarConDFS();
		break;
		case METODO_BFS: this->solucionarConBFS();
		break;
		case METODO_A_ESTRELLA: this->solucionarConAEstrella();
		break;
	}

}

Lista<std::string> * Seleccionador::obtenerSolucion(){

	return this->solucion;
}

void Seleccionador::solucionarConDijkstra(){

	this->dijkstra->resolver();
	this->solucion = this->dijkstra->getResultado();
}

void Seleccionador::solucionarConDFS(){

}

void Seleccionador::solucionarConBFS(){

}

void Seleccionador::solucionarConAEstrella(){


}


Seleccionador::~Seleccionador() {

	delete this->dijkstra;
}

