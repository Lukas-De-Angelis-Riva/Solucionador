#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
#include "Lista.h"

typedef struct GDupla GDupla_t;

#define ERROR -1;




class Vertice {

	public:

		Vertice(std::string nombre);

		~Vertice();

		void agregarVerticeAdyacente(Vertice* vertice,int peso);

		bool estaVerticeAd(Vertice* vertice);

		int pesoVerticeAd(Vertice* vertice);

		Lista<Vertice*>* verticesAd();
		
		std::string getNombre();

	private:

		std::string nombre;

		Lista<GDupla_t*>* adyacentes;
		
		GDupla_t* duplaConVertice(Vertice* vertice);

};



#endif /* VERTCE_H_ */
