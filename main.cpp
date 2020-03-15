#include <iostream>
#include "./Pruebas/pruebas.h"
#include "./Pruebas/Tester.h"
#include "./Solucionador/Solucionador.h"
using namespace std;
#include <stdio.h>


bool esLaberintoValido(std::string rutaLaberinto){

	FILE* fp = fopen(rutaLaberinto.c_str(), "rb");
	bool pudoAbrir = (fp != NULL);
	if(!pudoAbrir){
		cout << "No existe el laberinto: " << rutaLaberinto << endl;
	}else{
		fclose(fp);
	}
	return pudoAbrir;
}

bool esMetodoValido(std::string metodo){

	if(metodo != DIJKSTRA && metodo != DepthFirstSearch &&
	   metodo != BreadthFirstSearch && metodo != A_ESTRELLA){

		cout << "Metodo ingresado invalido..." <<endl;
		cout << "Metodos validos: " << endl;
		cout << DIJKSTRA << " " << DepthFirstSearch << " " << BreadthFirstSearch << " " << A_ESTRELLA << endl;
		return false;
	}
	return true;
}


int main(int argc, char** argv){


	if(argc != 4){
		cout << "Faltan comandos..." << endl;
		cout << "Ejecutar: ./SolucionadorDeLaberintos 'Método' 'Laberinto.bmp' 'Output.bmp'..." << endl;
		return 0;
	}

	std::string metodo = argv[1];
	std::string laberinto = argv[2];
	std::string rutaSolucion = argv[3];

	if(!esLaberintoValido(laberinto) || !esMetodoValido(metodo)){

		return 0;
	}

 	Solucionador * solucionador = new Solucionador(metodo, laberinto, rutaSolucion);
 	solucionador->solucionar();
 	delete solucionador;

/*
	//pruebas
	Tester * examinador = new Tester();

	examinador->hacerPrueba(ejemplo1,"ejemplo1");
	examinador->hacerPrueba(ejemplo2,"ejemplo2");
	examinador->hacerPrueba(ejemplo3,"ejemplo3");
	examinador->hacerPrueba(ejemplo4,"ejemplo4");
	examinador->hacerPrueba(ejemplo5,"ejemplo5");

	examinador->veredicto();

	delete examinador;
*/

	return 0;
}



