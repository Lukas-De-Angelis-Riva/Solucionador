#ifndef CONVERSOR_H_
#define CONVERSOR_H_

#include <stdio.h>

#include "global.h"
#include "Lista.h"
#include "Grafo.h"

const std::string ARRIBA = "Arriba";
const std::string IZQUIERDA = "Izquierda";

/*
 * Un Conversor se encarga de convertir una matriz que
 * representa un laberinto en un grafo de ese laberinto
 * y de un camino que soluciona el laberinto en una matriz
 * del laberinto solucionado
 *
 */
class Conversor {

		int ** matriz;
		Grafo * grafo;
		int altura,anchura;
		std::string entrada;
		std::string salida;


	public:

		/*
		 * Pre: La matriz representa el laberinto y sus
		 * 		dimensiones son [altura] x [anchura]
		 * Post: Se ha creado un Conversor con su grafo
		 */
		Conversor(int ** &matriz, int altura, int anchura);

		/*
		 * Pre:
		 * Post: Devuelve el grafo
		 */
		Grafo * obtenerGrafo();

		/*
		 * Pre:
		 * Post: Se ha obtenido el verticeEntrada
		 */
		std::string obtenerEntrada();

		/*
		 * Pre:
		 * Post: Se ha obtenido el verticeSalida
		 */
		std::string obtenerSalida();

		/*
		 * Pre: Los vertices forman un camino desde la entrada
		 * 		hasta la salida
		 * Post: Devuelve una matriz que representa el laberinto
		 * 		 solucionado
		 */
		int ** obtenerSolucion(Lista<std::string>* solucion);

		/*
		 * Pre:
		 * Post: Se ha liberado los recursos tomados por el Conversor
		 */
		~Conversor();

	private:

		/*
		 * Pre: La matriz representa el laberinto
		 * Post: Se ha creado un grafo
		 */
		void convertirMatrizAGrafo(int **& matriz);

		/*
		 * Pre:
		 * Post: Devuelve true si esPasillo
		 */
		bool esPasillo(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Devuelve true si la celda esPasilloVertical
		 */
		bool esPasilloVertical(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Devuelve true si la celda esPasilloHorizontal
		 */
		bool esPasilloHorizontal(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Devuelve true si la celda esPared
		 */
		bool esPared(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Devuelve el nombre del vertice en la
		 * 		 posicion
		 */
		std::string nombrar(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Conecta el vertice con sus adyacentes
		 */
		void conectarVertice(std::string vertice);

		/*
		 * Pre:
		 * Post: Conecta el vertice segun la direccion
		 */
		void conectarAdyacenteEn(int alto, int ancho, std::string direccion, std::string vertice);

		/*
		 * Pre:
		 * Post: Busca un vertice adyacente en la direccion
		 */
		std::string buscarAdyacente(int alto, int ancho, int& peso, std::string direccion);

		/*
		 * Pre:
		 * Post: Dibuja un camino entre el vertice desde a hasta
		 */
		void dibujarCamino(std::string desde, std::string hasta);

		/*
		 * Pre:
		 * Post devuelve el valor mayor de los dos
		 */
		int obtenerMayor(int uno, int dos);

		/*
		 * Pre:
		 * Post devuelve el valor menor de los dos
		 */
		int obtenerMenor(int uno, int dos);
};

#endif /* CONVERSOR_H_ */
