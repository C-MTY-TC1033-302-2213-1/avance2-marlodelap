/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
*/
#include "Serie.h"


Serie::Serie():Video(){
    //Se inicializa cantidad
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
	cantidad = 0;
}

void Serie::calculaDuracion(){
    int contador = 0;
	for (int index = 0; index < cantidad; index++) {
		contador += episodios[index].getTemporada();
	}
	duracion = contador;
}

//Metodos modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    if (posicion < cantidad && posicion >=0){
        episodios[posicion] = episodio;
    }

}
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

//Métodos de acceso
Episodio Serie::getEpisodio(int posicion){
    // Crea un objeto del tipo Episodio y lo inicializa con el constructor Default.
    Episodio epiDefault ;
    // Validar que exista el episodio solicitado
    if (posicion < cantidad && posicion >=0){
        return episodios[posicion];
    }
    // Si no existe retorna un episodio Default
    return epiDefault;
}

int Serie::getCantidad(){
 return cantidad; 
}


double Serie::calculaPromedio(){
 double acum = 0;
  
 for (int index = 0;  index<cantidad;index++){
    acum = acum + episodios[index].getCalificacion();
 }

 if (cantidad > 0){
    return acum/cantidad;
 }else {
    return 0;
 }
}

string Serie::str(){
    //
    calculaDuracion();
    string resultado=(id + ' ' + titulo + ' ' + to_string(duracion) + ' ' + 
    genero + ' ' + to_string(calculaPromedio()) + ' ' + to_string(cantidad) + "\n");
    if (cantidad > 0){
        for (int index = 0; index < cantidad; index++){
            resultado += episodios[index].str() + '\n';
    }
    return resultado;
    }
    else {
        return resultado;
    }


}

// Agregga un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if (cantidad<5){
        episodios[cantidad++]= episodio;

    }
}
