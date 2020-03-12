#include "Laberinto.h"

using namespace std;


Laberinto::Laberinto(std::string rutaDelLaberinto){

	this->grafo = new Grafo;
	this->imagen = new BMP;
	this->imagen->ReadFromFile(rutaDelLaberinto.c_str());
	this->entrada = "";
	this->salida = "";

	this->convertirImagenAGrafo();
}


Grafo * Laberinto::obtenerGrafo(){

	return this->grafo;
}

std::string Laberinto::obtenerEntrada(){

	return this->entrada;
}

std::string Laberinto::obtenerSalida(){

	return this->salida;
}

//Crear Grafo

void Laberinto::convertirImagenAGrafo(){

	int contador = 0;
	int alto = this->imagen->TellHeight();
	int ancho = this->imagen->TellWidth();

	for(int i = 0; i < alto; i++){
		for(int j = 0; j < ancho; j++){
			if(!this->esPared(i, j) && !this->esPasillo(i, j)){

				std::string nuevoVertice = this->nombrar(i, j);
				this->grafo->ingresarVertice(nuevoVertice);

				this->conectarVertice(nuevoVertice);

				if(contador == 0){
					this->entrada = nuevoVertice;
				}
				this->salida = nuevoVertice;
				contador++;
			}

		}
	}
}


void Laberinto::conectarVertice(std::string vertice){

	int alto = 0;
	int ancho = 0;
	sscanf(vertice.c_str(), "%i;%i", &alto, &ancho);

	if(alto - 1 >= 0){

		this->conectarAdyacenteEn(alto - 1, ancho , ARRIBA, vertice);
	}

	this->conectarAdyacenteEn(alto, ancho - 1, IZQUIERDA, vertice);

}

void Laberinto::conectarAdyacenteEn(int alto, int ancho, std::string direccion, std::string vertice){

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

std::string Laberinto::buscarAdyacente(int alto, int ancho, int& peso, std::string direccion){

	peso++;
	if(!this->esPasillo(alto, ancho) && !this->esPared(alto, ancho)){

		return this->nombrar(alto, ancho);
	}else if(direccion == ARRIBA){

		return this->buscarAdyacente(alto - 1, ancho, peso, ARRIBA);
	}else{

		return this->buscarAdyacente(alto, ancho - 1, peso, IZQUIERDA);
	}

}

bool Laberinto::esPasillo(int alto, int ancho){

	int altura = this->imagen->TellHeight();

	if(this->esPared(alto, ancho) ||
	   alto == 0 || alto == altura - 1){

		return false;
	}
	return (this->esPasilloVertical(alto, ancho) ||
			this->esPasilloHorizontal(alto, ancho));
}

bool Laberinto::esPasilloVertical(int alto, int ancho){

	return (!this->esPared(alto - 1, ancho) &&
			!this->esPared(alto + 1, ancho) &&
			 this->esPared(alto, ancho - 1) &&
			 this->esPared(alto, ancho + 1));

}

bool Laberinto::esPasilloHorizontal(int alto, int ancho){

	return ( this->esPared(alto - 1, ancho) &&
			 this->esPared(alto + 1, ancho) &&
			!this->esPared(alto, ancho - 1) &&
			!this->esPared(alto, ancho + 1));


}

bool Laberinto::esPared(int alto, int ancho){

	return this->esNegro(alto, ancho);
}

std::string Laberinto::nombrar(int alto, int ancho){

	char * stringC = new char[100];
	sprintf(stringC, "%d;%d", alto, ancho);
	std::string nombre(stringC);
	delete []stringC;
	return nombre;
}

//Dibujar



void Laberinto::dibujarImagen(Lista<std::string>* solucion, std::string rutaLaberintoResuelto){

	int rojo = MAXIMO;
	int verde = 0;
	int azul = 0;


	if(solucion->estaVacia()){
		throw std::string("No hay solucion");
	}
	std::string verticeAnterior = solucion->obtener(1);

	solucion->iniciarCursor();
	while(solucion->avanzarCursor()){
		std::string verticeSiguiente = solucion->obtenerCursor();

		this->dibujarCamino(verticeAnterior, verticeSiguiente, rojo, verde, azul);
		verticeAnterior = verticeSiguiente;
	}

	this->imagen->WriteToFile(rutaLaberintoResuelto.c_str());
}


void Laberinto::dibujarCamino(std::string anterior, std::string siguiente,
				   	   	   	  int& rojo, int& verde, int& azul){

	int altoDesde = 0;
	int anchoDesde = 0;
	sscanf(anterior.c_str(), "%i;%i", &altoDesde, &anchoDesde);

	int altoHasta = 0;
	int anchoHasta = 0;
	sscanf(siguiente.c_str(), "%i;%i", &altoHasta, &anchoHasta);

	if(altoDesde == altoHasta){

		this->dibujarLineaHorizontal(anchoDesde, anchoHasta, altoDesde, rojo, verde, azul);
	}else{

		this->dibujarLineaVertical(altoDesde, altoHasta, anchoDesde, rojo, verde, azul);
	}

}

void Laberinto::dibujarLineaHorizontal(int anchoDesde,int anchoHasta,int alto,int& rojo,int& verde,int& azul){

	if(anchoDesde < anchoHasta){

		for(int i = anchoDesde; i <= anchoHasta; i++){

			this->dibujarPixel(alto, i, rojo, verde, azul);
		}
	}else{

		for(int i = anchoDesde; i >= anchoHasta; i--){

			this->dibujarPixel(alto, i, rojo, verde, azul);
		}
	}
}


void Laberinto::dibujarLineaVertical(int altoDesde,int altoHasta,int ancho,int& rojo,int& verde,int& azul){


	if(altoDesde < altoHasta){

		for(int i = altoDesde; i <= altoHasta; i++){

			this->dibujarPixel(i, ancho, rojo, verde, azul);
		}
	}else{

		for(int i = altoDesde; i >= altoHasta; i--){

			this->dibujarPixel(i, ancho, rojo, verde, azul);
		}
	}
}

void Laberinto::dibujarPixel(int alto, int ancho, int& rojo, int& verde, int& azul){

	this->obtenerColor(rojo, verde, azul);
	(*this->imagen)(ancho, alto)->Red = rojo;
	(*this->imagen)(ancho, alto)->Green = verde;
	(*this->imagen)(ancho, alto)->Blue = azul;
	(*this->imagen)(ancho, alto)->Alpha = 0;

}

void Laberinto::obtenerColor(int& rojo, int& verde, int& azul){

	if(rojo == MAXIMO && verde != MAXIMO && azul == 0){

		verde += PASO;
		chequearColor(verde);
	}else if(rojo != 0 && verde == MAXIMO && azul == 0){

		rojo -= PASO;
		chequearColor(rojo);
	}else if(rojo == 0 && verde == MAXIMO && azul != MAXIMO){

		azul += PASO;
		chequearColor(azul);
	}else if(rojo == 0 && verde != 0 && azul == MAXIMO){

		verde -= PASO;
		chequearColor(verde);
	}else if(rojo != MAXIMO && verde == 0 && azul == MAXIMO){

		rojo += PASO;
		chequearColor(rojo);
	}else if(rojo == MAXIMO && verde == 0 && azul != 0){

		azul -= PASO;
		chequearColor(azul);
	}

}

void Laberinto::chequearColor(int& color){

	if(color > MAXIMO){
		color = MAXIMO;
	}else if(color < 0){
		color = 0;
	}
}


bool Laberinto::esNegro(int alto, int ancho){

	int rojo = (int)((*this->imagen)(ancho, alto)->Red);
	int azul = (int)((*this->imagen)(ancho, alto)->Blue);
	int verde = (int)((*this->imagen)(ancho, alto)->Green);
	int alpha = (int)((*this->imagen)(ancho, alto)->Alpha);

	return ( rojo == 0 &&
			 azul == 0 &&
			 verde == 0 &&
			 alpha == 0 );

}

Laberinto::~Laberinto(){

	delete this->imagen;
	delete this->grafo;
}


