/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
Aprendí a crear una clase para después utilizarla en la composición de otra. 
*/

//Header guard
#ifndef Episodio_h
#define Episodio_h
#include <stdio.h>

#include "Video.h"

class Episodio {

private:
    string titulo;
    int temporada;
    int calificacion;

public:
    //metodo constructor default
    Episodio();
    //metodo constructor con argumentos 
    Episodio(string _titulo , int _temporada, int _calificacion);
    
    //Métodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();


    //Métodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);
    
    //otros métodos
    string str();
    

};

#endif /* Episodio_hpp */
