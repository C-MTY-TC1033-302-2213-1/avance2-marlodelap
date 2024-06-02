/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Video.h"

//Constructor default 
Video::Video(){

    id = "0000";
    titulo = "The Office";
    duracion = 1000;
    genero = "Comedia";
    calificacion = 3.14159535897932384623795;

};
//Constructor parametros

Video::Video(string _id, string _titulo, int _duracion, string _genero, double _calificacion){

    id = _id;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;

};

//Metodos de acceso, retornan un valor del atributo
string Video::getId(){
return id;
};

string Video::getTitulo(){
return titulo;
};
int Video::getDuracion(){
return duracion;
};
string Video::getGenero(){
return genero;
};
double Video::getCalificacion(){
return calificacion;
};


//Modifican un valor del atributo

void Video::setId(string _id){
id = _id;
};
void Video::setTitulo(string _titulo){
titulo = _titulo;
};
void Video::setDuracion(int _duracion){
duracion = _duracion;
};
void Video::setGenero(string _genero){
genero = _genero;
};
void Video::setCalificacion(double _calificacion){
calificacion = _calificacion;
};

//Metodos 
 string Video::str(){
     return id +
        " " + titulo + 
        " " + std::to_string(duracion) + 
        " " + genero +
        " " + std::to_string(calificacion);
};