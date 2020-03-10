#include "Dijkstra.h"
#include "../IteradorLista.h"
#include "../Pila.h"
#define str std::string
#define ERRORDIJ -1

typedef struct nodoDij{
	str vertice;
	float distancia;
	bool visitado;
	struct nodoDij * nodoAnterior;
}nodoDij_t;

Dijkstra::Dijkstra(Grafo* g, str v_ini, str v_fin){
	if(g->estaVertice(v_ini) && g->estaVertice(v_fin)){
		this->grafo = g;
		this->partida = v_ini;
		this->llegada = v_fin;
		this->resultado = NULL;
	}else{
		throw str ("Algún vértice, o ambos vertices no existen en el grafo");
	}
}
Dijkstra::~Dijkstra(){
	delete this->resultado;
}

int proximoAVisitar(Lista<nodoDij_t*>* nodos){
	int posProx = 1;
	nodoDij_t* actual = nodos->obtener(posProx);
	int i = 1;

	nodos->iniciarCursor();
	while(nodos->avanzarCursor()){
		if(!(nodos->obtenerCursor()->visitado)){
			if(actual->visitado){
				posProx = i;
				actual = nodos->obtenerCursor();
			}else if(nodos->obtenerCursor()->distancia < actual->distancia){
				posProx = i;
				actual = nodos->obtenerCursor();
			}
		}
		i++;
	}
	if(nodos->obtener(posProx)->visitado){
		return ERRORDIJ;
	}
	return posProx;
}
void actualizarPeso(nodoDij_t* nodoPartida, nodoDij_t* nodoLlegada, Grafo* g){
	if(nodoLlegada->distancia > nodoPartida->distancia + g->pesoAdyacentes(nodoPartida->vertice,nodoLlegada->vertice)){
		nodoLlegada->distancia = nodoPartida->distancia + g->pesoAdyacentes(nodoPartida->vertice,nodoLlegada->vertice); 	
		nodoLlegada->nodoAnterior = nodoPartida;
	}
}


void armador(nodoDij_t* verticeAIngresar, Lista<str>*& camino, nodoDij_t* partida){
	if(verticeAIngresar->vertice == partida->vertice){
		camino->agregar(partida->vertice);
		return;
	}else{
		camino->agregar(verticeAIngresar->vertice);
		return armador(verticeAIngresar->nodoAnterior,camino,partida);
	}
}
Lista<str>* armarResultado(nodoDij_t* llegada, nodoDij_t* partida){
	Lista<str>* camino = new Lista<str>;
	armador(llegada, camino, partida);
	return camino;
}

void darVueltaLista(Lista<str>* lista){
	Pila<str> pila;
	while(!lista->estaVacia()){
		pila.apilar(lista->obtener(1));
		lista->remover(1);
	}
	while(!pila.estaVacia()){
		lista->agregar(pila.desapilar());
	}
}

void Dijkstra::resolver(){
	Lista<str>* vertices = this->grafo->obtenerVertices();
	Lista<nodoDij_t*> nodos;
	nodoDij_t* partida = new nodoDij_t;
	partida->vertice = this->partida;
	partida->distancia = 0;
	partida->visitado = true;
	vertices->iniciarCursor();
	while(vertices->avanzarCursor()){
		str verticeActual = vertices->obtenerCursor();
		if(!(verticeActual == this->partida)){
			nodoDij_t* nodo = new nodoDij_t;
			nodo->vertice = verticeActual;
			nodo->distancia = this->grafo->pesoAdyacentes(verticeActual,this->partida);
			nodo->visitado = false;
			nodo->nodoAnterior = partida;
			nodos.agregar(nodo);
		}
	}
	nodos.agregar(partida);
	int posProx = proximoAVisitar(&nodos);
	if(posProx == ERRORDIJ){
			throw str ("Ocurrió un error, no existen vertices a visitar");
	}
	nodoDij_t* actual = nodos.obtener(posProx);
	while(actual->vertice != this->llegada){
		actual->visitado = true;
		IteradorLista<nodoDij_t*> iterador(&nodos);
		iterador.iniciarCursor();
		while(iterador.avanzarCursor()){
			if(!(iterador.obtenerCursor()->visitado)){
				actualizarPeso(actual, iterador.obtenerCursor(), this->grafo);

			}
		}
		posProx = proximoAVisitar(&nodos);
		if(posProx == ERRORDIJ){
			throw str ("Ocurrió un error, se recorrieron todos los vertices, se visitaron pero ninguno era la llegada");
		}
		actual = nodos.obtener(posProx);
	}
	this->resultado = armarResultado(actual,partida); //actual en este caso ya es la llegada.
	darVueltaLista(this->resultado);
	nodos.iniciarCursor();
	while(nodos.avanzarCursor()){
		delete nodos.obtenerCursor();
	}

	delete vertices;
}

Lista<str>* Dijkstra::getResultado(){
	return this->resultado;
}
