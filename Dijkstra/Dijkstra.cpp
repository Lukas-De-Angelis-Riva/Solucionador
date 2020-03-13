#include "Dijkstra.h"
#include "../TDA/IteradorLista.h"
#include "../TDA/Pila.h"
#define str std::string
#define ERRORDIJ -1


#include <iostream>
using namespace std;

/*Crea la estructura de Dijkstra. vInicio será el vértice partida y vFin el vértice llegada.*/
Dijkstra::Dijkstra(Grafo* g, str vIni, str vFin){
	if(g->estaVertice(vIni) && g->estaVertice(vFin)){
		this->grafo = g;
		this->partida = vIni;
		this->llegada = vFin;
		this->resultado = NULL;
	}else{
		throw str ("Algún vértice, o ambos vertices no existen en el grafo");
	}
}



/*Elimina a Dijkstra y libera toda la memoria reservada por la clase.*/
Dijkstra::~Dijkstra(){
	delete this->resultado;
}


/* Función recursiva que se ingresa en la primera posicion de una lista al nombre del nodo que se pasa por primer parámetro.
	Termina cuando el vértice recibido es nulo.
*/
void armador(NodoDij* verticeAIngresar, Lista<str>*& camino){
	if(verticeAIngresar == NULL){
		return;
	}else{
		camino->agregar(verticeAIngresar->getNombre(),1);
		return armador(verticeAIngresar->getNodoAnt(),camino);
	}
}

/* Función que devuelve una lista con el camino desde la partida hasta la llegada, siendo la partida el primer elemento y la llegada el último.*/
Lista<str>* armarResultado(NodoDij* llegada){
	Lista<str>* camino = new Lista<str>;
	armador(llegada, camino);
	return camino;
}


/* 	Crea un hash con las claves los nombres de los vértices y los elementos Nodos Dijktra.
	Llamar a la función 'liberarMemoriaHash' cuando se vaya a eliminar el hash.
*/
Hash<NodoDij*>* Dijkstra::crearHashClave_nodoDij(){
	Hash<NodoDij*>* hash = new Hash<NodoDij*>;
	Lista<str>* vertices = this->grafo->obtenerVertices();
	
	NodoDij* nodoPartida = new NodoDij(this->partida,NULL,true,0);
	hash->agregar(nodoPartida->getNombre(),nodoPartida);

	vertices->iniciarCursor();
	while(vertices->avanzarCursor()){
		str verticeActual = vertices->obtenerCursor();
		if(verticeActual != this->partida){
			NodoDij* nodo = new NodoDij(verticeActual, nodoPartida, false,
											this->grafo->pesoAdyacentes(verticeActual,this->partida));
			hash->agregar(verticeActual,nodo);
		}
	}
	delete vertices;
	return hash;
}

/* Crea e inicializa el heap de candidatos,
	poseera de clave a la distancia al vértice partida y el elemento un puntero al NodoDij almacenado en el hash. */
Heap* Dijkstra::crearHeapCandidatos(Hash<NodoDij*>* hash){
	Heap* heap = new Heap;
	Lista<NodoDij*>* vertices = new Lista<NodoDij*>;
	hash->recorrer(vertices);
	vertices->iniciarCursor();
	while(vertices->avanzarCursor()){
		NodoDij* nodoActual = vertices->obtenerCursor();
		if(nodoActual->getNombre()!= this->partida){
			heap->insertar(nodoActual->getDistancia(),nodoActual);
		}
	}
	delete vertices;
	return heap;
}

/* Recibe un nodo y devuelve una lista de los nodos que contienen a sus vértices adyacentes */
Lista<NodoDij*>* Dijkstra::obtenerNodosAdyacentes(Hash<NodoDij*>* hash, NodoDij* nodoActual){
	Lista<str>* adyacentes = this->grafo->adyacentesAlVertice(nodoActual->getNombre());
	Lista<NodoDij*>* nodosAdyacentes = new Lista<NodoDij*>;
	adyacentes->iniciarCursor();
	while(adyacentes->avanzarCursor()){
		nodosAdyacentes->agregar(hash->buscar(adyacentes->obtenerCursor()));
	}
	delete adyacentes;
	return nodosAdyacentes;
}
/* Devuelve true en caso de que la distancia actual sea mayor que la distancia para ir hasta partida y de partida a actual.
	En caso contrario devuelve false.
*/

bool Dijkstra::mejoraDis(NodoDij* llegada, NodoDij* salida){
	return llegada->getDistancia() > 
					salida->getDistancia() + this->grafo->pesoAdyacentes(llegada->getNombre(),salida->getNombre());
}
/*Actualiza el peso del nodo llegada.*/
void Dijkstra::actualizarPeso(NodoDij* llegada, NodoDij* salida){
	llegada->setDistancia(salida->getDistancia() + this->grafo->pesoAdyacentes(llegada->getNombre(),salida->getNombre()));
	return;
}

/*Actualiza el nodo anterior del nodo llegada, lo suplanda por el nodo salida.*/
void Dijkstra::actualizarNodoAnt(NodoDij* llegada, NodoDij* salida){
	llegada->setNodoAnt(salida);
	return;
}

/*Libera la memoria reservada por el método 'crearHashClave_nodoDij()'.*/
void liberarMemoriaHash(Hash<NodoDij*>* hash){
	Lista<NodoDij*>* lista = new Lista<NodoDij*>;
	hash->recorrer(lista);
	lista->iniciarCursor();
	while(lista->avanzarCursor()){
		NodoDij* nodo = lista->obtenerCursor();
		delete nodo;
	}
	delete lista;
}

/* Resuelve el problema y lo guarda en resultado.
	Precondición: se llamará solo una vez al método.
*/
void Dijkstra::resolver(){
	Hash<NodoDij*>* hash = this->crearHashClave_nodoDij();
	Heap* heap = this->crearHeapCandidatos(hash);
	NodoDij* nodoActual = heap->obtenerElementoMinimo();
	heap->removerMinimo();
	while(nodoActual->getNombre() != this->llegada){
		Lista<NodoDij*>* adyacentes = this->obtenerNodosAdyacentes(hash,nodoActual);
		adyacentes->iniciarCursor();
		while(adyacentes->avanzarCursor()){
			NodoDij* nodoAd = adyacentes->obtenerCursor();
			if((nodoAd->getVisitado() == false) && this->mejoraDis(nodoAd,nodoActual)){
				this->actualizarPeso(nodoAd,nodoActual);
				this->actualizarNodoAnt(nodoAd,nodoActual);
				heap->disminuirClave(nodoAd,nodoAd->getDistancia());
			}
		}
		delete adyacentes;
		nodoActual->setVisitadoT();
		nodoActual = heap->obtenerElementoMinimo();
		heap->removerMinimo();
	}
	this->resultado = armarResultado(nodoActual); //actual en este caso ya es la llegada.
	delete heap;
	liberarMemoriaHash(hash);
	delete hash;
}


/*Devuelve el resultado. Primero se debe llamar a resolver, de lo contrario resultado estará vacio.*/
Lista<str>* Dijkstra::getResultado(){
	return this->resultado;
}
