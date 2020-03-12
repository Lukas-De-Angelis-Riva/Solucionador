#include "Grafo.h"

#define str std::string


// '#define' n === nombre.
// '#define' v === vertice.



/* Crea un grafo vacio,*/
Grafo::Grafo(){
	this->vertices = new Hash<Vertice*>;
}


/*Elimina el grafo, y toda la memoria que se ha utlizado internamiente*/
Grafo::~Grafo(){
	Lista<Vertice*>* lista = new Lista<Vertice*>;
	this->vertices->recorrer(lista);
	lista->iniciarCursor();
	while(lista->avanzarCursor()){
		delete lista->obtenerCursor();
	}
	delete lista;
	delete this->vertices;
}


/*Ingresa un vértice al grafo, éste será un vértice aislado.
	Precond: Dos vértices no poseen el mismo nombre.
*/
void Grafo::ingresarVertice(str nombre){
	Vertice* vertice = new Vertice(nombre);
	this->vertices->agregar(nombre,vertice);
}


/* Devuelve el vértice dentro del grafo que poseea como nombre a 'nombre'.
	En caso de no existir lanza un throw avisando que no existe el vértice en el grafo.
*/
Vertice* Grafo::obtenerVertice(str nombre){
	Vertice* v = this->vertices->buscar(nombre);
	return v;
}

/*Ingresa una arista entre dos vértices.
	
	En caso de que sean el mismo vértice no se hará nada. (por definicion un vértice es adyacente a sí mismo con peso 0).
	
	En caso de que ya sean adyacentes no se hará nada. (no se actualizará el peso).
	
	El grafo NO es dirigido, por lo cual v1 será adyacente a v2 y viceversa.
*/
void Grafo::ingresarArista(str n1, str n2, int peso){
	if(n1 == n2){
		return;
	}
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);
	if(v1->estaVerticeAd(v2)){
		if(v2->estaVerticeAd(v1)){
			return;
		}else{
			throw str ("Existen dos vértices que no son adyacentes mutuamente.");
		}
	}else if(v2->estaVerticeAd(v1)){
		throw str ("Existen dos vértices que no son adyacentes mutuamente.");
	}
	v1->agregarVerticeAdyacente(v2,peso);
	v2->agregarVerticeAdyacente(v1,peso);
}

/*Devuelve true si el vértice pertenece al grafol.
*/
bool Grafo::estaVertice(str n){
	return this->vertices->esta(n);
}


/*Devuelve true si dos vértices son adyancentes.
	En caso de ser el mismo vértice se devolverá true.
*/
bool Grafo::sonAdyacentes(str n1, str n2){
	if(n1 == n2){
		return true;
	}
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);
	if(v1->estaVerticeAd(v2) && v2->estaVerticeAd(v1)){
		return true;
	}else if(!v1->estaVerticeAd(v2) && !v2->estaVerticeAd(v1)){
		return false;
	}else{
		throw str ("Los vertices no cumplen ser adyacentes ambos a la vez, OJO.");
	}
}


/*Devuelve un float con el peso que une ambos vértices.
	En caso de ser el mismo vértice se devolverá 0.
	En caso de ser dos vértices no adyacentes, se devolverá la constante INFINITY de la biblioteca math.h.
*/
float Grafo::pesoAdyacentes(str n1, str n2){
	if(n1 == n2){
		return 0;
	}
	Vertice* v1 = this->obtenerVertice(n1);
	Vertice* v2 = this->obtenerVertice(n2);

	if(this->sonAdyacentes(n1,n2)){
		if(v1->pesoVerticeAd(v2) == v2->pesoVerticeAd(v1)){
			return v1->pesoVerticeAd(v2);
		}else{
			throw str ("Los pesos no coinciden.");
		}
	}else{
		return INFINITY;
		//throw str ("Los vertices no son adyacentes.");
	}
}

Lista<str>* Grafo::obtenerVertices(){
	Lista<str>* listaStr = new Lista<str>;
	Lista<Vertice*>* lista = new Lista<Vertice*>;
	this->vertices->recorrer(lista);
	lista->iniciarCursor();
	while(lista->avanzarCursor()){
		listaStr->agregar(lista->obtenerCursor()->getNombre());
	}
	delete lista;
	return listaStr;
}

/*Devuelve una Lista de strings representando los nombres de los vértices que pertenecen al grafo. */
int Grafo::cantidadVertices(){
	return this->vertices->obtenerTamanio();
}

/*Devuelve la cantidad de vértices que posee el grafo.*/
Lista<str>* Grafo::adyacentesAlVertice(str n){
	Vertice* v = this->obtenerVertice(n);
	Lista<Vertice*>* listaDeVertices = v->verticesAd();
	Lista<str>* listaDeNombres = new Lista<str>;
	listaDeVertices->iniciarCursor();
	while(listaDeVertices->avanzarCursor()){
		listaDeNombres->agregar(listaDeVertices->obtenerCursor()->getNombre());
	}
	return listaDeNombres;
}
