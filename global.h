#ifndef GLOBAL_H_
#define GLOBAL_H_
#include <string>

const int VALOR_PARED = -1;
const int VALOR_ENTRADA = 0;
const int VALOR_PASILLO = 1;
const int VALOR_SALIDA = 2;
const int VALOR_RUTA = 3;

const std::string DIJKSTRA = "Dijkstra";
const std::string BreadthFirstSearch = "BFS";
const std::string DepthFirstSearch = "DFS";
const std::string A_ESTRELLA = "A*";

const int METODO_DIJKSTRA = 0;
const int METODO_BFS = 1;
const int METODO_DFS = 2;
const int METODO_A_ESTRELLA = 3;

#endif /* GLOBAL_H_ */
