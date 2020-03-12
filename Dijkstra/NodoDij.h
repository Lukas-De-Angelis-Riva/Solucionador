#ifndef NODODIJ_H_
#define NODODIJ_H_
#include <string>

class NodoDij{
	
	public:
		
		/* Crea un nodo dijkstra.*/
		NodoDij(std::string nombre, NodoDij* nodoAnt,bool visitado, float distancia);
		
		/*Borra el nodo dijkstra.*/
		~NodoDij();

		/* Devuelve el nodo anterior.*/
		NodoDij* getNodoAnt();
		
		/*Devuelve la distancia.*/
		float getDistancia();

		/*Devuelve el nombre.*/
		std::string getNombre();

		/*Devuelve el atributo visitado*/
		bool getVisitado();

		/* Cambia el atributo visitado por true.*/
		void setVisitadoT();
		
		/* Cambia la distancia del nodo.*/
		void setDistancia(float dis);

		/* Cambia el nodo anterior por 'nodo'.*/
		void setNodoAnt(NodoDij* nodo);

		bool operator< (const NodoDij& derecha);

	private:
		std::string nombre;
		float distancia;
		bool visitado;
		NodoDij* nodoAnterior;
};

#endif /* NODODIJ_H_ */