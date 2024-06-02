/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
Aprendí a crear clases derivadas usando el concepto de herencia para obtener los 
atributos y métodos de una clase base. 
*/

#ifndef Pelicula_h
#define Pelicula_h
#include <stdio.h>

#include "Video.h"


class Pelicula : public Video {

private:
    
    int oscares;

public:
    //metodo constructor default
    Pelicula();
    //metodo constructor con argumentos 
    Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);
    
    //Métodos de acceso
    int getOscares();

    //Métodos modificadores
    void setOscares(int _oscares);
    
    //Otros métodos
    string str();
    

};

#endif /* Pelicula_hpp */
