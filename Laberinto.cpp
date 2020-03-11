#include "Laberinto.h"

using namespace std;


Laberinto::Laberinto(std::string rutaDelLaberinto){

	this->imagen = new BMP;
	this->imagen->ReadFromFile(rutaDelLaberinto.c_str());
	this->matriz = NULL;
	this->ancho = this->imagen->TellWidth();
	this->alto = this->imagen->TellHeight();

	this->convertirImagenEnMatriz();
}

void Laberinto::cambiarMatriz(int **&nuevaMatriz){


	this->matriz = nuevaMatriz;

}

int ** Laberinto::obtenerMatriz(){

	return this->matriz;
}

int Laberinto::obtenerAltura(){

	return this->alto;
}

int Laberinto::obtenerAnchura(){

	return this->ancho;
}

void Laberinto::dibujarImagen(std::string rutaLaberintoResuelto){

	int rojo = MAXIMO;
	int verde = 0;
	int azul = 0;

	for(int i = 0; i < this->alto; i++){
		for(int j = 0; j < this->ancho; j++){
			if(this->matriz[i][j] == VALOR_RUTA){

				this->obtenerColor(rojo, verde, azul);
				(*this->imagen)(j, i)->Red = rojo;
				(*this->imagen)(j, i)->Green = verde;
				(*this->imagen)(j, i)->Blue = azul;
				(*this->imagen)(j, i)->Alpha = 0;


			}
		}
	}
	this->imagen->WriteToFile(rutaLaberintoResuelto.c_str());
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

void Laberinto::convertirImagenEnMatriz(){

	this->matriz = new int * [alto];
	for(int i = 0; i < alto; i++){

		this->matriz[i] = new int[ancho];
	}

	for(int i = 0; i < alto; i++){
		for(int j = 0; j < ancho; j++){

			if(this->esNegro(i, j)){

				this->matriz[i][j] = VALOR_PARED;
			}else{

				this->matriz[i][j] = VALOR_PASILLO;
			}
		}
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
	this->liberarMatriz();
}

void Laberinto::liberarMatriz(){

	for(int i = 0; i < this->alto; i++){
		delete[] this->matriz[i];
	}
	delete[] this->matriz;
	this->matriz = NULL;

}
