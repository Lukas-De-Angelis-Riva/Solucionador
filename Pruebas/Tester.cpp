
#include "Tester.h"

using namespace std;

Tester::Tester() {

	this->pruebasPasadas = 0;
	this->pruebasTotales = 0;

}

void Tester::hacerPrueba(bool (*prueba) (void), string nombreDeLaPrueba){

	this->pruebasTotales++;

	bool aprobo = prueba();

	if(aprobo){

		this->pruebasPasadas++;
	}
	cout << endl;
	cout << nombreDeLaPrueba << ":" << endl;
	cout <<"Prueba numero " << this->pruebasTotales << " resultado: " << (aprobo? "aprobada" : "desaprobada") << endl;

}

void Tester::assert(bool condicion){

	if (!condicion){

		throw string("Excepcion Assert: requisito no cumplido");
	}

}

void Tester::veredicto(){

	cout << endl;
	cout << "		.:: RESULTADOS DE LAS PRUEBAS ::.		" << endl;
	cout << endl;
	cout << "De "<<this->pruebasTotales << " pruebas se aprobaron " << this->pruebasPasadas << endl;
	cout << "De "<<this->pruebasTotales << " pruebas se desaprobaron " << (this->pruebasTotales - this->pruebasPasadas) << endl;
	cout << endl;
}

Tester::~Tester() {


}

