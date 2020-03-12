#include "Solucionador.h"

using namespace std;

Solucionador::Solucionador(std::string metodo, std::string laberinto) {

	this->laberinto = laberinto;
	this->metodo = this->interpretarMetodo(metodo);

}

void Solucionador::solucionar(){

	//Variables para cronometrar
	clock_t iniciarReloj, pararReloj;
	double tiempo;

	cout << "Creando laberinto de imagen a grafo..." << endl;
	iniciarReloj = clock();

	//Se crea el laberinto a partir de la imagen
	Laberinto * lab = new Laberinto(this->laberinto);
	Grafo * grafo = lab->obtenerGrafo();
	int cantidadDeVertices = grafo->cantidadVertices();

	pararReloj = clock();
	tiempo = ((double) (pararReloj - iniciarReloj)) / CLOCKS_PER_SEC;
	cout << "Grafo creado con " << cantidadDeVertices << " de vertices..." <<endl;
	cout << "De imagen a grafo en: " << tiempo << " Segundos..." <<endl;

	cout << "Solucionando grafo..." << endl;
	iniciarReloj = clock();

	//Se selecciona el metodo y se resuelve
	Seleccionador * seleccionador = new Seleccionador(grafo, lab->obtenerEntrada(), lab->obtenerSalida());
	seleccionador->resolver(this->metodo);

	pararReloj = clock();
	tiempo = ((double) (pararReloj - iniciarReloj)) / CLOCKS_PER_SEC;
	cout << "Grafo solucionado en: " << tiempo << " Segundos..." <<endl;

	cout << "Graficando solucion..." << endl;

	//Se obtiene la solucion y se convierte en una imagen
	Lista<std::string> * solucion = seleccionador->obtenerSolucion();
	lab->dibujarImagen(solucion,"SOLUCION" + this->laberinto);

	cout << "Imagen solucion creada con nombre: " << ("SOLUCION" + this->laberinto) << endl;

	//Liberar recursos
	delete lab;
	delete seleccionador;
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

