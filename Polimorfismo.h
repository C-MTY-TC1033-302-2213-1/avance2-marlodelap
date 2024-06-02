/*
Nombre: Marco Antonio López de la Puente 
Matricula: A01285789
Carrera: ITC
Fecha: 30 de mayo 2024

- ¿Qué aprendí en el desarrollo de la clase Polimorfismo?
En la clase polimorfismo aprendí la aplicación de los siguientes conceptos de código: 
Polimorfismo runtime: A través de las funciones virtuales se puede crear una jerarquía de métodos.
Polimorfirmo compile: Se crearon nuevos métodos que tomaban diferentes atributos, creando así overriding. 
Pointers: Para obtener la dirección de memoria de los objetos referenciados y poder distribuir un arreglo multitipo. 

*/

#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

const int MAX_VIDEOS = 100;

class Polimorfismo {

private:
   Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;
    
public:
    //metodo constructor default
    Polimorfismo();
    //metodo leerArchivo
    void leerArchivo(string _nombre);

    void setPtrVideo(int index, Video *video);
    void setCantidadVideos(int _cantidad);

    Video *getPtrVideo(int index);
    int getCantidad();

    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
    
};

#endif