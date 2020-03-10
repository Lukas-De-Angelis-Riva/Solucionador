#ifndef TESTER_H_
#define TESTER_H_

#include <iostream>

class Tester {

	private:

		unsigned int pruebasTotales;
		unsigned int pruebasPasadas;

	public:

		/*
		 * Pre:
		 * Post: Crea un tester y no se han hecho pruebas
		 *
		 */
		Tester();

		/*
		 * Pre: prueba es una funcion que hace la prueba
		 * Post: Suma uno a las pruebasTotales y en caso de que
		 * la prueba devuelva true suma uno a las pruebas pasadas
		 *
		 */
		void hacerPrueba(bool (*prueba) (void), std::string nombreDeLaPrueba);

		/*
		 * Pre:
		 * Post: Si la condicion es verdadera paso el assert sino
		 * lanza una excepcion
		 *
		 */
		void assert(bool condicion);

		/*
		 * Pre:
		 * Post: imprime por pantalla el veredicto siendo este
		 * la cantidad de pruebas pasadas y el total de pruebas hecho
		 *
		 */
		void veredicto();


		/*
		 * Pre:
		 * Post: Destructor del tester
		 */
		~Tester();
};

#endif /* TESTER_H_ */
