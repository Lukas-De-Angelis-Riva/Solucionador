#ifndef SOLUCIONADOR_H_
#define SOLUCIONADOR_H_

#include <string>
#include "Laberinto.h"
#include "Conversor.h"
#include "Seleccionador.h"
#include "global.h"


/*
 * Un Solucionador se encarga de solucionar un
 * laberinto en una imagen de 16 bits .bmp
 *
 */
class Solucionador {

	private:

		std::string laberinto;
		int metodo;

	public:

		/*
		 * Pre: El metodo y el laberinto existen
		 * Post: Se ha creado un solucionador en condiciones de
		 * 		 solucionar
		 */
		Solucionador(std::string metodo, std::string laberinto);

		/*
		 * Pre:
		 * Post: Soluciona el laberinto
		 */
		void solucionar();

		/*
		 * Pre:
		 * Post: Libera los recursos tomados por el Solucionador
		 */
		~Solucionador();

	private:

		/*
		 * Pre:
		 * Post: Obtiene el inicio y el fin del laberinto
		 */
		void obtenerInicioYFin(Grafo* grafo, std::string& inicio, std::string& fin);

		/*
		 * Pre:
		 * Post: Interpreta el metodo a utilizar
		 */
		int interpretarMetodo(std::string metodo);
};

#endif /* SOLUCIONADOR_H_ */
