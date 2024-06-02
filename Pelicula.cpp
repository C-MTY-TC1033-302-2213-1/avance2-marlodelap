/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
*/
#include "Pelicula.h"
 using namespace std;

 //metodo constructor default
    Pelicula::Pelicula():Video(){
        oscares = 100;
    };
    //metodo constructor con argumentos 
    Pelicula::Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):
    Video( _id,  _titulo,  _duracion,  _genero,  _calificacion){
        oscares = _oscares;
    };
    
    //Métodos de acceso
    int Pelicula::getOscares(){
        return oscares;
    }

    //Métodos modificadores
    void Pelicula::setOscares(int _oscares){
        oscares = _oscares;
    }
    
    //Otros métodos
    string Pelicula::str(){
        return  id +
        " " + titulo + 
        " " + std::to_string(duracion) + 
        " " + genero +
        " " + std::to_string(calificacion)+
        " " + std::to_string(oscares);
    }