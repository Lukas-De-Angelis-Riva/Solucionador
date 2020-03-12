#ifndef LABERINTO_H_
#define LABERINTO_H_

#include <string>
#include "../TDA/Lista.h"
#include "../Grafo/Grafo.h"
#include "../BMP/EasyBMP.h"

#include "../global.h"

const std::string ARRIBA = "Arriba";
const std::string IZQUIERDA = "Izquierda";

const int MAXIMO = 255;
const int PASO = 10;

/*
 * Un Laberinto posee la imagen del laberinto que el usuario decidio cargar
 * y su representacion en un Grafo
 *
 */
class Laberinto {

	private:

		BMP * imagen;
		Grafo * grafo;
		std::string entrada;
		std::string salida;

	public:

		/*
		 * Pre: Existe una imagen .bmp que se encuentra en la rutaDelLaberinto
		 * 		y que es de 16-bits
		 * Post: Se ha creado un laberinto con su respectivo grafo
		 */
		Laberinto(std::string rutaDelLaberinto);

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
		 * Pre:
		 * Post: Se ha dibujado la imagen en la rutaDelLaberintoResuelto
		 */
		void dibujarImagen(Lista<std::string>* solucion, std::string rutaLaberintoResuelto);

		/*
		 * Pre:
		 * Post: Se ha liberado los recursos tomados por el Laberinto
		 */
		~Laberinto();

	private:

		/*
		 * Pre: Se ha guardado una imagen
		 * Post: El grafo ha sido creada
		 */
		void convertirImagenAGrafo();

		/*
		 * Pre:
		 * Post: Devuelve true si un pixel en (alto, ancho)
		 * 		 es negro
		 */
		bool esNegro(int alto, int ancho);

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
		 * Post: Dado dos vertices dibuja una camino
		 */
		void dibujarCamino(std::string anterior, std::string siguiente,
						   int& rojo, int& verde, int& azul);

		/*
		 * Pre:
		 * Post: Dibuja una linea Horizontal con el color adecuado
		 */
		void dibujarLineaHorizontal(int anchoDesde,int anchoHasta,int alto,int& rojo,int& verde,int& azul);

		/*
		 * Pre:
		 * Post: Dibuja una linea Horizontal con el color adecuado
		 */
		void dibujarLineaVertical(int altoDesde,int altoHasta,int ancho,int& rojo,int& verde,int& azul);

		/*
		 * Pre:
		 * Post: Dibuja un pixel con el color adecuado
		 */
		void dibujarPixel(int alto, int ancho, int& rojo, int& verde, int& azul);

		/*
		 * Pre:
		 * Post: Modifica el color RGB para obtener un degrade
		 */
		void obtenerColor(int& rojo, int& verde, int& azul);

		/*
		 * Pre:
		 * Post: Chequea que un color este en el rango [0, 255]
		 * 		 lo modifica en caso contrario
		 */
		void chequearColor(int& color);
};

#endif /* LABERINTO_H_ */
