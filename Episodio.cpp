/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
*/

#include "Episodio.h"

//Constructores
Episodio::Episodio(){
    titulo = "Titulo provisional";
    temporada = 000;
    calificacion = 000;
}
Episodio::Episodio(string _titulo,
      int _temporada,
      int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
    
}
// Metodos modificadores (set)
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}

void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}


//Metodos de acceso (get)
string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

int Episodio::getCalificacion(){
    return calificacion;
}

//Otros metodos
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}