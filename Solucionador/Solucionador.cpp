#include "Solucionador.h"

using namespace std;

Solucionador::Solucionador(std::string metodo, std::string laberinto, std::string rutaSolucion) {

	this->laberinto = laberinto;
	this->rutaSolucion = rutaSolucion;
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

	//Se obtiene la solucion y se convierte en una imagen
	Lista<std::string> * solucion = seleccionador->obtenerSolucion();

	cout << "Graficando solucion..." << endl;

	lab->dibujarImagen(solucion,this->rutaSolucion);

	cout << "Imagen solucion creada con nombre: " << (this->rutaSolucion) << endl;

	//Liberar recursos
	delete lab;
	delete seleccionador;
}



int Solucionador::interpretarMetodo(std::string metodo){

	if(metodo == DIJKSTRA){

		return METODO_DIJKSTRA;
	}else if(metodo == DepthFirstSearch){

		return METODO_DFS;
	}else if(metodo == BreadthFirstSearch){

		return METODO_BFS;
	}else{

		return METODO_A_ESTRELLA;
	}
}

Solucionador::~Solucionador() {

}

