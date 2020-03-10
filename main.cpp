#include <iostream>
#include "Laberinto.h"
#include "Conversor.h"
#include "Pruebas/pruebas.h"
#include "Pruebas/Tester.h"
using namespace std;



int main(int argc, char** argv){

	//std::string metodoDeSolucion = argv[1];
	//std::string laberinto = argv[2];

	//pruebas
	Tester * examinador = new Tester();

	examinador->hacerPrueba(ejemplo1,"ejemplo1");
	examinador->hacerPrueba(ejemplo2,"ejemplo2");
	examinador->hacerPrueba(ejemplo3,"ejemplo3");
	examinador->hacerPrueba(ejemplo4,"ejemplo4");
	examinador->hacerPrueba(ejemplo5,"ejemplo5");

	examinador->veredicto();
	delete examinador;


	return 0;
}



