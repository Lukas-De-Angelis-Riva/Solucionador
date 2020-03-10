#include "Conversor.h"


Conversor::Conversor(int ** &matriz, int altura, int anchura) {

	this->matriz = matriz;
	this->altura = altura;
	this->anchura = anchura;
	this->grafo = new Grafo();

	this->convertirMatrizAGrafo(matriz);
}

Grafo * Conversor::obtenerGrafo(){

	return this->grafo;
}

int ** Conversor::obtenerSolucion(Lista<std::string>* solucion){

	if(solucion->estaVacia()){
		throw std::string("No hay solucion");
	}
	std::string verticeAnterior = solucion->obtener(1);

	solucion->iniciarCursor();
	while(solucion->avanzarCursor()){
		std::string verticeSiguiente = solucion->obtenerCursor();

		this->dibujarCamino(verticeAnterior, verticeSiguiente);
		verticeAnterior = verticeSiguiente;
	}
	return this->matriz;
}

void Conversor::dibujarCamino(std::string desde, std::string hasta){

	int altoDesde = 0;
	int anchoDesde = 0;
	sscanf(desde.c_str(), "%i;%i", &altoDesde, &anchoDesde);

	int altoHasta = 0;
	int anchoHasta = 0;
	sscanf(hasta.c_str(), "%i;%i", &altoHasta, &anchoHasta);

	if(altoDesde == altoHasta){
		int anchoMenor = obtenerMenor(anchoDesde, anchoHasta);
		int anchoMayor = obtenerMayor(anchoDesde, anchoHasta);

		for(int i = anchoMenor; i <= anchoMayor; i++){
			this->matriz[altoDesde][i] = VALOR_RUTA;
		}
	}else{
		int altoMenor = obtenerMenor(altoDesde, altoHasta);
		int altoMayor = obtenerMayor(altoDesde, altoHasta);

		for(int i = altoMenor; i <= altoMayor; i++){
			this->matriz[i][anchoDesde] = VALOR_RUTA;
		}
	}
}

int Conversor::obtenerMayor(int uno, int dos){

	if(uno > dos){

		return uno;
	}
	return dos;
}

int Conversor::obtenerMenor(int uno, int dos){

	if(uno < dos){

		return uno;
	}
	return dos;
}

void Conversor::convertirMatrizAGrafo(int** &matriz){

	for(int i = 0; i < this->altura; i++){
		for(int j = 0; j < this->anchura; j++){
			//cout << "i: " << i << "  j: " << j << endl;
			if(!this->esPared(i, j) && !this->esPasillo(i, j)){

				//cout << "entro" <<endl;
				std::string nuevoVertice = this->nombrar(i, j);
				this->grafo->ingresarVertice(nuevoVertice);

				this->conectarVertice(nuevoVertice);
			}

		}
	}

}

void Conversor::conectarVertice(std::string vertice){

	int alto = 0;
	int ancho = 0;
	sscanf(vertice.c_str(), "%i;%i", &alto, &ancho);

	if(alto - 1 >= 0){

		this->conectarAdyacenteEn(alto - 1, ancho , ARRIBA, vertice);
	}

	this->conectarAdyacenteEn(alto, ancho - 1, IZQUIERDA, vertice);

}

void Conversor::conectarAdyacenteEn(int alto, int ancho, std::string direccion, std::string vertice){

	if(this->esPasillo(alto, ancho)){

		int peso = 0;
		std::string verticeAdyacente = this->buscarAdyacente(alto, ancho, peso, direccion);
		this->grafo->ingresarArista(vertice, verticeAdyacente, peso);
	}else if(!this->esPared(alto, ancho)){

		int peso = 1;
		std::string verticeAdyacente = this->nombrar(alto, ancho);
		this->grafo->ingresarArista(vertice, verticeAdyacente, peso);
	}

}

std::string Conversor::buscarAdyacente(int alto, int ancho, int& peso, std::string direccion){

	peso++;
	if(!this->esPasillo(alto, ancho) && !this->esPared(alto, ancho)){

		return this->nombrar(alto, ancho);
	}else if(direccion == ARRIBA){

		return this->buscarAdyacente(alto - 1, ancho, peso, ARRIBA);
	}else{

		return this->buscarAdyacente(alto, ancho - 1, peso, IZQUIERDA);
	}

}

bool Conversor::esPasillo(int alto, int ancho){


	if(this->esPared(alto, ancho) ||
	   alto == 0 || alto == this->altura - 1){
		
		return false;
	}
	return (this->esPasilloVertical(alto, ancho) ||
			this->esPasilloHorizontal(alto, ancho));
}

bool Conversor::esPasilloVertical(int alto, int ancho){

	return (this->matriz[alto - 1][ancho] == VALOR_PASILLO &&
			this->matriz[alto + 1][ancho] == VALOR_PASILLO &&
			this->matriz[alto][ancho - 1] == VALOR_PARED &&
			this->matriz[alto][ancho + 1] == VALOR_PARED);

}

bool Conversor::esPasilloHorizontal(int alto, int ancho){

	return (this->matriz[alto - 1][ancho] == VALOR_PARED &&
			this->matriz[alto + 1][ancho] == VALOR_PARED &&
			this->matriz[alto][ancho - 1] == VALOR_PASILLO &&
			this->matriz[alto][ancho + 1] == VALOR_PASILLO);


}

bool Conversor::esPared(int alto, int ancho){

	return this->matriz[alto][ancho] == VALOR_PARED;
}

std::string Conversor::nombrar(int alto, int ancho){

	char * stringC = new char[100];
	sprintf(stringC, "%d;%d", alto, ancho);
	std::string nombre(stringC);
	delete []stringC;
	return nombre;
}

Conversor::~Conversor() {

	delete this->grafo;

}

