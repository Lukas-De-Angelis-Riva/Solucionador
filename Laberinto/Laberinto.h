#ifndef LABERINTO_H_
#define LABERINTO_H_

#include <string>
#include "../BMP/EasyBMP.h"

#include "../global.h"

const int MAXIMO = 255;
const int PASO = 50;

/*
 * Un Laberinto posee la imagen del laberinto que el usuario decidio cargar
 * y su representacion en una matriz
 *
 */
class Laberinto {

	private:

		BMP * imagen;
		int ** matriz;
		int ancho, alto;

	public:

		/*
		 * Pre: Existe una imagen .bmp que se encuentra en la rutaDelLaberinto
		 * 		y que es de 16-bits
		 * Post: Se ha creado un laberinto con su respectiva matriz
		 */
		Laberinto(std::string rutaDelLaberinto);

		/*
		 * Pre:
		 * Post: Se ha cambiado la matriz del laberinto por nuevaMatriz
		 */
		void cambiarMatriz(int ** &nuevaMatriz);

		/*
		 * Pre:
		 * Post: Se ha devuelto la matriz del laberinto
		 */
		int ** obtenerMatriz();

		/*
		 * Pre:
		 * Post: Devuelve la altura de la matriz
		 */
		int obtenerAltura();

		/*
		 * Pre:
		 * Post: Devuelve la anchura de la matriz
		 */
		int obtenerAnchura();

		/*
		 * Pre:
		 * Post: Se ha dibujado la imagen en la rutaDelLaberintoResuelto
		 */
		void dibujarImagen(std::string rutaLaberintoResuelto);

		/*
		 * Pre:
		 * Post: Se ha liberado los recursos tomados por el Laberinto
		 */
		~Laberinto();

	private:

		/*
		 * Pre: Se ha guardado una imagen
		 * Post: La matriz ha sido creada
		 */
		void convertirImagenEnMatriz();

		/*
		 * Pre:
		 * Post: Devuelve true si un pixel en (alto, ancho)
		 * 		 es negro
		 */
		bool esNegro(int alto, int ancho);

		/*
		 * Pre:
		 * Post: Se ha liberado la matriz guardada
		 */
		void liberarMatriz();

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
