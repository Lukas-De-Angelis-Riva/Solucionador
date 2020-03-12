#include "pruebas.h"
using namespace std;


std::string nombre(int alto, int ancho){

	char * stringC = new char[100];
	sprintf(stringC, "%d;%d", alto, ancho);
	std::string nombre(stringC);
	delete []stringC;
	return nombre;
}


bool ejemplo1(){

	//BMP 16 - bits prueba
	std::string laberinto = "ejemplo1.bmp";

	//Se crea un laberinto con la imagen y su grafo
	Laberinto * lab = new Laberinto(laberinto);
	Grafo * grafo = lab->obtenerGrafo();

	//Se prueba que los vertices sean adyacentes con el peso correcto
	std::string vertice02 = nombre(0, 2);
	std::string vertice11 = nombre(1, 1);
	std::string vertice12 = nombre(1, 2);
	std::string vertice13 = nombre(1, 3);
	std::string vertice21 = nombre(2, 1);
	std::string vertice22 = nombre(2, 2);
	std::string vertice23 = nombre(2, 3);
	std::string vertice31 = nombre(3, 1);
	std::string vertice32 = nombre(3, 2);
	std::string vertice33 = nombre(3, 3);
	std::string vertice41 = nombre(4, 1);


	//Resultado
	bool resultado = grafo->sonAdyacentes(vertice02, vertice12) &&
					 grafo->sonAdyacentes(vertice11, vertice12) &&
					 grafo->sonAdyacentes(vertice11, vertice21) &&
					 grafo->sonAdyacentes(vertice12, vertice13) &&
					 grafo->sonAdyacentes(vertice12, vertice22) &&
					 grafo->sonAdyacentes(vertice13, vertice23) &&
					 grafo->sonAdyacentes(vertice21, vertice22) &&
					 grafo->sonAdyacentes(vertice21, vertice31) &&
					 grafo->sonAdyacentes(vertice22, vertice32) &&
					 grafo->sonAdyacentes(vertice22, vertice23) &&
					 grafo->sonAdyacentes(vertice23, vertice33) &&
					 grafo->sonAdyacentes(vertice31, vertice41) &&
					 grafo->sonAdyacentes(vertice31, vertice32) &&
					 grafo->sonAdyacentes(vertice32, vertice33);

	//Solucion

/*
	Lista<std::string> * solucion= new Lista<std::string>;

	solucion->agregar(vertice02);
	solucion->agregar(vertice12);
	solucion->agregar(vertice22);
	solucion->agregar(vertice32);
	solucion->agregar(vertice31);
	solucion->agregar(vertice41);
*/

	Dijkstra * dijkstra = new Dijkstra(grafo, vertice02, vertice41);
	dijkstra->resolver();
	Lista<std::string> * solucion = dijkstra->getResultado();
	lab->dibujarImagen(solucion, "SOLUCIONejemplo1.bmp");

	//Se liberan recursos
	delete lab;
	delete dijkstra;
	return resultado;
}

bool ejemplo2(){

	//BMP 16 - bits prueba
	std::string laberinto = "ejemplo2.bmp";

	//Se crea un laberinto con la imagen y su grafo
	Laberinto * lab = new Laberinto(laberinto);
	Grafo * grafo = lab->obtenerGrafo();

	//Se prueba que los vertices sean adyacentes con el peso correcto
	std::string vertice02 = nombre(0, 2);
	std::string vertice11 = nombre(1, 1);
	std::string vertice12 = nombre(1, 2);
	std::string vertice13 = nombre(1, 3);
	std::string vertice31 = nombre(3, 1);
	std::string vertice33 = nombre(3, 3);
	std::string vertice43 = nombre(4, 3);

	//Adyacentes
	bool estanAristasCorrectas = grafo->sonAdyacentes(vertice02, vertice12) &&
					 	 	 	 grafo->sonAdyacentes(vertice11, vertice12) &&
								 grafo->sonAdyacentes(vertice12, vertice13) &&
								 grafo->sonAdyacentes(vertice11, vertice31) &&
								 grafo->sonAdyacentes(vertice31, vertice33) &&
								 grafo->sonAdyacentes(vertice33, vertice43);

	//Pesos
	bool estanPesosCorrectos = grafo->pesoAdyacentes(vertice02, vertice12) == 1 &&
						 	   grafo->pesoAdyacentes(vertice11, vertice12) == 1 &&
							   grafo->pesoAdyacentes(vertice12, vertice13) == 1 &&
							   grafo->pesoAdyacentes(vertice11, vertice31) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice33) == 2 &&
							   grafo->pesoAdyacentes(vertice33, vertice43) == 1;

	//Resultado
	bool resultado = estanAristasCorrectas && estanPesosCorrectos;

	Dijkstra * dijkstra = new Dijkstra(grafo, vertice02, vertice43);
	dijkstra->resolver();
	Lista<std::string> * solucion = dijkstra->getResultado();
	lab->dibujarImagen(solucion,"SOLUCIONejemplo2.bmp");

	//Se liberan recursos
	delete lab;
	delete dijkstra;
	return resultado;
}


bool ejemplo3(){

	//BMP 16 - bits prueba
	std::string laberinto = "ejemplo3.bmp";

	//Se crea un laberinto con la imagen y su grafo
	Laberinto * lab = new Laberinto(laberinto);
	Grafo * grafo = lab->obtenerGrafo();


	//Se prueba que los vertices sean adyacentes con el peso correcto
	std::string vertice03 = nombre(0, 3);
	std::string vertice11 = nombre(1, 1);
	std::string vertice13 = nombre(1, 3);
	std::string vertice31 = nombre(3, 1);
	std::string vertice32 = nombre(3, 2);
	std::string vertice42 = nombre(4, 2);

	//Adyacentes
	bool estanAristasCorrectas = grafo->sonAdyacentes(vertice03, vertice13) &&
					 	 	 	 grafo->sonAdyacentes(vertice13, vertice11) &&
								 grafo->sonAdyacentes(vertice11, vertice31) &&
								 grafo->sonAdyacentes(vertice31, vertice32) &&
								 grafo->sonAdyacentes(vertice32, vertice42);

	//Pesos
	bool estanPesosCorrectos = grafo->pesoAdyacentes(vertice03, vertice13) == 1 &&
						 	   grafo->pesoAdyacentes(vertice13, vertice11) == 2 &&
							   grafo->pesoAdyacentes(vertice11, vertice31) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice32) == 1 &&
							   grafo->pesoAdyacentes(vertice32, vertice42) == 1;

	//Resultado
	bool resultado = estanAristasCorrectas && estanPesosCorrectos;

	Dijkstra * dijkstra = new Dijkstra(grafo, vertice03, vertice42);
	dijkstra->resolver();
	Lista<std::string> * solucion = dijkstra->getResultado();
	lab->dibujarImagen(solucion, "SOLUCIONejemplo3.bmp");


	//Se liberan recursos
	delete lab;
	delete dijkstra;
	return resultado;
}


bool ejemplo4(){

	//BMP 16 - bits prueba
	std::string laberinto = "ejemplo4.bmp";

	//Se crea un laberinto con la imagen y su grafo
	Laberinto * lab = new Laberinto(laberinto);
	Grafo * grafo = lab->obtenerGrafo();


	//Se prueba que los vertices sean adyacentes con el peso correcto
	std::string vertice03 = nombre(0, 3);
	std::string vertice11 = nombre(1, 1);
	std::string vertice13 = nombre(1, 3);
	std::string vertice15 = nombre(1, 5);
	std::string vertice18 = nombre(1, 8);
	std::string vertice31 = nombre(3, 1);
	std::string vertice33 = nombre(3, 3);
	std::string vertice37 = nombre(3, 7);
	std::string vertice38 = nombre(3, 8);
	std::string vertice43 = nombre(4, 3);
	std::string vertice45 = nombre(4, 5);
	std::string vertice51 = nombre(5, 1);
	std::string vertice63 = nombre(6, 3);
	std::string vertice64 = nombre(6, 4);
	std::string vertice67 = nombre(6, 7);
	std::string vertice71 = nombre(7, 1);
	std::string vertice81 = nombre(8, 1);
	std::string vertice84 = nombre(8, 4);
	std::string vertice87 = nombre(8, 7);
	std::string vertice88 = nombre(8, 8);
	std::string vertice97 = nombre(9, 7);

	//Adyacentes
	bool estanAristasCorrectas = grafo->sonAdyacentes(vertice03, vertice13) &&
					 	 	 	 grafo->sonAdyacentes(vertice13, vertice11) &&
								 grafo->sonAdyacentes(vertice15, vertice18) &&
								 grafo->sonAdyacentes(vertice11, vertice31) &&
								 grafo->sonAdyacentes(vertice13, vertice33) &&
								 grafo->sonAdyacentes(vertice31, vertice51) &&
								 grafo->sonAdyacentes(vertice31, vertice33) &&
								 grafo->sonAdyacentes(vertice43, vertice33) &&
								 grafo->sonAdyacentes(vertice43, vertice45) &&
								 grafo->sonAdyacentes(vertice45, vertice15) &&
								 grafo->sonAdyacentes(vertice18, vertice38) &&
								 grafo->sonAdyacentes(vertice37, vertice38) &&
								 grafo->sonAdyacentes(vertice37, vertice67) &&
								 grafo->sonAdyacentes(vertice63, vertice64) &&
								 grafo->sonAdyacentes(vertice64, vertice67) &&
								 grafo->sonAdyacentes(vertice64, vertice84) &&
								 grafo->sonAdyacentes(vertice71, vertice81) &&
								 grafo->sonAdyacentes(vertice81, vertice84) &&
								 grafo->sonAdyacentes(vertice84, vertice87) &&
								 grafo->sonAdyacentes(vertice87, vertice88) &&
								 grafo->sonAdyacentes(vertice87, vertice97);
	//Pesos
	bool estanPesosCorrectos = grafo->pesoAdyacentes(vertice03, vertice13) == 1 &&
							   grafo->pesoAdyacentes(vertice13, vertice11) == 2 &&
							   grafo->pesoAdyacentes(vertice15, vertice18) == 3 &&
							   grafo->pesoAdyacentes(vertice11, vertice31) == 2 &&
							   grafo->pesoAdyacentes(vertice13, vertice33) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice51) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice33) == 2 &&
							   grafo->pesoAdyacentes(vertice43, vertice33) == 1 &&
							   grafo->pesoAdyacentes(vertice43, vertice45) == 2 &&
							   grafo->pesoAdyacentes(vertice45, vertice15) == 3 &&
							   grafo->pesoAdyacentes(vertice18, vertice38) == 2 &&
							   grafo->pesoAdyacentes(vertice37, vertice38) == 1 &&
							   grafo->pesoAdyacentes(vertice37, vertice67) == 3 &&
							   grafo->pesoAdyacentes(vertice63, vertice64) == 1 &&
							   grafo->pesoAdyacentes(vertice64, vertice67) == 3 &&
							   grafo->pesoAdyacentes(vertice64, vertice84) == 2 &&
							   grafo->pesoAdyacentes(vertice71, vertice81) == 1 &&
							   grafo->pesoAdyacentes(vertice81, vertice84) == 3 &&
							   grafo->pesoAdyacentes(vertice84, vertice87) == 3 &&
							   grafo->pesoAdyacentes(vertice87, vertice88) == 1 &&
 							   grafo->pesoAdyacentes(vertice87, vertice97) == 1;
	//Resultado
	bool resultado = estanAristasCorrectas && estanPesosCorrectos;

	Dijkstra * dijkstra = new Dijkstra(grafo, vertice03, vertice97);
	dijkstra->resolver();
	Lista<std::string> * solucion = dijkstra->getResultado();
	lab->dibujarImagen(solucion,"SOLUCIONejemplo4.bmp");

	//Se liberan recursos
	delete lab;
	delete dijkstra;
	return resultado;
}

bool ejemplo5(){

	//BMP 16 - bits prueba
	std::string laberinto = "ejemplo5.bmp";

	//Se crea un laberinto con la imagen y su grafo
	Laberinto * lab = new Laberinto(laberinto);
	Grafo * grafo = lab->obtenerGrafo();


	//Se prueba que los vertices sean adyacentes con el peso correcto
	std::string vertice08 = nombre(0, 8);
	std::string vertice11 = nombre(1, 1);
	std::string vertice15 = nombre(1, 5);
	std::string vertice27 = nombre(2, 7);
	std::string vertice28 = nombre(2, 8);
	std::string vertice31 = nombre(3, 1);
	std::string vertice33 = nombre(3, 3);
	std::string vertice35 = nombre(3, 5);
	std::string vertice37 = nombre(3, 7);
	std::string vertice51 = nombre(5, 1);
	std::string vertice53 = nombre(5, 3);
	std::string vertice55 = nombre(5, 5);
	std::string vertice57 = nombre(5, 7);
	std::string vertice58 = nombre(5, 8);
	std::string vertice71 = nombre(7, 1);
	std::string vertice72 = nombre(7, 2);
	std::string vertice73 = nombre(7, 3);
	std::string vertice75 = nombre(7, 5);
	std::string vertice76 = nombre(7, 6);
	std::string vertice85 = nombre(8, 5);
	std::string vertice87 = nombre(8, 7);
	std::string vertice88 = nombre(8, 8);
	std::string vertice92 = nombre(9, 2);

	//Adyacentes
	bool estanAristasCorrectas = grafo->sonAdyacentes(vertice11, vertice15) &&
					 	 	 	 grafo->sonAdyacentes(vertice08, vertice28) &&
								 grafo->sonAdyacentes(vertice15, vertice35) &&
								 grafo->sonAdyacentes(vertice27, vertice28) &&
								 grafo->sonAdyacentes(vertice35, vertice37) &&
								 grafo->sonAdyacentes(vertice31, vertice33) &&
								 grafo->sonAdyacentes(vertice31, vertice51) &&
								 grafo->sonAdyacentes(vertice35, vertice55) &&
								 grafo->sonAdyacentes(vertice37, vertice57) &&
								 grafo->sonAdyacentes(vertice51, vertice53) &&
								 grafo->sonAdyacentes(vertice53, vertice55) &&
								 grafo->sonAdyacentes(vertice55, vertice57) &&
								 grafo->sonAdyacentes(vertice57, vertice58) &&
								 grafo->sonAdyacentes(vertice53, vertice73) &&
								 grafo->sonAdyacentes(vertice58, vertice88) &&
								 grafo->sonAdyacentes(vertice71, vertice72) &&
								 grafo->sonAdyacentes(vertice72, vertice73) &&
								 grafo->sonAdyacentes(vertice73, vertice75) &&
								 grafo->sonAdyacentes(vertice75, vertice76) &&
								 grafo->sonAdyacentes(vertice75, vertice85) &&
								 grafo->sonAdyacentes(vertice87, vertice88) &&
								 grafo->sonAdyacentes(vertice72, vertice92);
	//Pesos
	bool estanPesosCorrectos = grafo->pesoAdyacentes(vertice11, vertice15) == 4 &&
							   grafo->pesoAdyacentes(vertice08, vertice28) == 2 &&
							   grafo->pesoAdyacentes(vertice15, vertice35) == 2 &&
							   grafo->pesoAdyacentes(vertice27, vertice28) == 1 &&
							   grafo->pesoAdyacentes(vertice35, vertice37) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice33) == 2 &&
							   grafo->pesoAdyacentes(vertice31, vertice51) == 2 &&
							   grafo->pesoAdyacentes(vertice35, vertice55) == 2 &&
							   grafo->pesoAdyacentes(vertice37, vertice57) == 2 &&
							   grafo->pesoAdyacentes(vertice51, vertice53) == 2 &&
							   grafo->pesoAdyacentes(vertice53, vertice55) == 2 &&
							   grafo->pesoAdyacentes(vertice55, vertice57) == 2 &&
							   grafo->pesoAdyacentes(vertice57, vertice58) == 1 &&
							   grafo->pesoAdyacentes(vertice53, vertice73) == 2 &&
							   grafo->pesoAdyacentes(vertice58, vertice88) == 3 &&
							   grafo->pesoAdyacentes(vertice71, vertice72) == 1 &&
							   grafo->pesoAdyacentes(vertice72, vertice73) == 1 &&
							   grafo->pesoAdyacentes(vertice73, vertice75) == 2 &&
							   grafo->pesoAdyacentes(vertice75, vertice76) == 1 &&
							   grafo->pesoAdyacentes(vertice75, vertice85) == 1 &&
							   grafo->pesoAdyacentes(vertice87, vertice88) == 1 &&
							   grafo->pesoAdyacentes(vertice72, vertice92) == 2;
	//Resultado
	bool resultado = estanAristasCorrectas && estanPesosCorrectos;

	Dijkstra * dijkstra = new Dijkstra(grafo, vertice08, vertice92);
	dijkstra->resolver();
	Lista<std::string> * solucion = dijkstra->getResultado();
	lab->dibujarImagen(solucion,"SOLUCIONejemplo5.bmp");

	//Se liberan recursos
	delete lab;
	delete dijkstra;
	return resultado;
}
