#include "DFS.h"

DFS::DFS(Grafo * grafo, std::string inicio, std::string fin){

	this->grafo = grafo;
	this->inicio = inicio;
	this->fin = fin;
	this->solucion = NULL;
}


void DFS::resolver(){

		Hash<NodoDFS*>* hash = this->crearHashDeNodos();
		Pila<NodoDFS*> * pila = new Pila<NodoDFS*>;
		NodoDFS* actual = hash->buscar(this->inicio);
		while(actual->obtenerVertice() != this->fin){
			actual->fueVisitado();
			Lista<NodoDFS*>* adyacentes = this->obtenerNodosAdyacentes(hash,actual);
			adyacentes->iniciarCursor();
			while(adyacentes->avanzarCursor()){
				NodoDFS* adyacente = adyacentes->obtenerCursor();
				if((adyacente->obtenerVistado() == false)){
					adyacente->cambiarAnterior(actual);
					pila->apilar(adyacente);
				}
			}
			actual = pila->desapilar();
			delete adyacentes;
		}
		this->solucion = armarResultado(actual); //actual en este caso ya es la llegada.
		liberarHash(hash);
		delete hash;
		delete pila;
}

Hash<NodoDFS*>* DFS::crearHashDeNodos(){

		Hash<NodoDFS*>* hash = new Hash<NodoDFS*>;
		Lista<std::string>* vertices = this->grafo->obtenerVertices();

		vertices->iniciarCursor();
		while(vertices->avanzarCursor()){
			std::string verticeActual = vertices->obtenerCursor();
			NodoDFS* nodo = new NodoDFS(verticeActual,false, NULL);
			hash->agregar(verticeActual,nodo);

		}
		delete vertices;
		return hash;

}

Lista<NodoDFS*>* DFS::obtenerNodosAdyacentes(Hash<NodoDFS*>* hash, NodoDFS* actual){

		Lista<std::string>* adyacentes = this->grafo->adyacentesAlVertice(actual->obtenerVertice());
		Lista<NodoDFS*>* nodosAdyacentes = new Lista<NodoDFS*>;
		adyacentes->iniciarCursor();
		while(adyacentes->avanzarCursor()){
			nodosAdyacentes->agregar(hash->buscar(adyacentes->obtenerCursor()));
		}
		delete adyacentes;
		return nodosAdyacentes;

}

Lista<std::string> * DFS::armarResultado(NodoDFS* fin){

	Lista<std::string> * ruta = new Lista<std::string>;
	Pila<std::string> * pila = new Pila<std::string>;

	NodoDFS* actual = fin;
	while(actual != NULL){
		pila->apilar(actual->obtenerVertice());
		actual = actual->obtenerAnterior();
	}
	while(!pila->estaVacia()){

		ruta->agregar(pila->desapilar());
	}
	delete pila;
	return ruta;
}

void DFS::liberarHash(Hash<NodoDFS*>* hash){

		Lista<NodoDFS*>* lista = new Lista<NodoDFS*>;
		hash->recorrer(lista);
		lista->iniciarCursor();
		while(lista->avanzarCursor()){
			NodoDFS* nodo = lista->obtenerCursor();
			delete nodo;
		}
		delete lista;
}


Lista<std::string> * DFS::obtenerResultado(){

	return this->solucion;
}

DFS::~DFS(){

	delete this->solucion;
}
