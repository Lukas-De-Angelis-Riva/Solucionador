#ifndef NODODIJ_H_
#define NODODIJ_H_
#include <string>

class NodoDij{
	
	public:
		NodoDij(std::string nombre, NodoDij* nodoAnt ,bool visitado, float distancia);

		~NodoDij();

		NodoDij* getNodoAnt();

		bool getVisitado();

		float getDistancia();

		std::string getNombre();

		void setDistancia(float dis);

		void setVisitado();

		void setNodoAnt(NodoDij* nodo);

		bool operator< (const NodoDij& derecha);

	private:
		std::string nombre;
		float distancia;
		bool visitado;
		NodoDij* nodoAnterior;
};

#endif /* NODODIJ_H_ */