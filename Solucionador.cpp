#include "Solucionador.h"

Solucionador::Solucionador(std::string metodo, std::string laberinto) {

	this->laberinto = laberinto;
	this->metodo = this->interpretarMetodo(metodo);

}

void Solucionador::solucionar(){

	//Se crea el laberinto a partir de la imagen
	Laberinto * lab = new Laberinto(this->laberinto);
	int** matriz = lab->obtenerMatriz();

	//Se convierte la matriz en un grafo
	Conversor * conversor = new Conversor(matriz, lab->obtenerAltura(), lab->obtenerAnchura());
	Grafo * grafo = conversor->obtenerGrafo();

	//Se obtiene el inicio y el fin
	std::string inicio = "";
	std::string fin = "";
	this->obtenerInicioYFin(grafo, inicio, fin);

	//Se selecciona el metodo y se resuelve
	Seleccionador * seleccionador = new Seleccionador(grafo, inicio, fin);
	seleccionador->resolver(this->metodo);

	//Se obtiene la solucion y se convierte en una imagen
	Lista<std::string> * solucion = seleccionador->obtenerSolucion();
	int ** matrizSolucion = conversor->obtenerSolucion(solucion);
	lab->cambiarMatriz(matrizSolucion);
	lab->dibujarImagen("SOLUCION" + this->laberinto);

	//Liberar recursos
	delete lab;
	delete conversor;
	delete seleccionador;
}


void Solucionador::obtenerInicioYFin(Grafo* grafo, std::string& inicio, std::string& fin){

	Lista<std::string> * vertices = grafo->obtenerVertices();
	inicio = vertices->obtener(1);
	fin = vertices->obtener(vertices->cantidadElementos());
	delete vertices;
}

int Solucionador::interpretarMetodo(std::string metodo){

	if(metodo == DIJKSTRA){

		return METODO_DIJKSTRA;
	}else if(metodo == DFS){

		return METODO_DFS;
	}else if(metodo == BFS){

		return METODO_BFS;
	}else{

		return METODO_A_ESTRELLA;
	}
}

Solucionador::~Solucionador() {

}

