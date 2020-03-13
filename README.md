Solucionador de Laberintos
=============================
 


 ![Laberinto](https://github.com/Lukas-De-Angelis-Riva/Solucionador/blob/master/Laberintote.bmp) | ![Solucion](https://github.com/Lukas-De-Angelis-Riva/Solucionador/blob/master/SOLUCIONLaberintote.bmp) 
:-------------------------:|:-------------------------:
Input           |  Output

Formato
----------

Recibe una imagen BMP de 16 bits que representa el laberinto, este cumple las siguientes precondiciones:

* Solo hay una entrada y una salida.
* La entrada se encuentra en el borde superior y la salida en el borde inferior.
* El borde del laberinto es pared, salvo la entrada y salida.
* Las paredes son pixeles negros, mientras que la entrada, salida y pasillos son blancos.


Métodos de resolución
---------------------

El programa permite resolver el laberinto utilizando los siguientes métodos:
* Dijkstra ✓
* Depth First Search [WIP]
* Breadth First Search [WIP]
* A* [WIP]


Compilación y Ejecución
-----------------------

Compilar con Eclipse IDE en una carpeta source y ejecutar con el siguiente comando:

`./SolucionadorDeLaberintos "Método" "Laberinto.bmp"`
