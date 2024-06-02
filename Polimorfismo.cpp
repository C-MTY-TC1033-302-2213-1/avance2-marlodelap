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

#include "Polimorfismo.h"

#include <typeinfo>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Video.h"
#include <stdio.h>
using namespace std;
//Constructor default - vacio
Polimorfismo :: Polimorfismo(){ 
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    //Inicializar cantidad de Videos
    cantidad = 0;
}

void Polimorfismo::leerArchivo(string nombre){
    //todas las declaraciones se hacen abajo del encabezado estandar c++ ITESM
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7]; //row - arreglo de 7 elementos de strings, para almacenar los datos de la linea del archivo ya separados
    string line, word; // line - almacena la linea leida, y word la palabra que se saca de line
    int cantidadPeliculas = 0; // Contadores de peliculas y series, inicialmente son 0
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in); // Abrir archivo de entrada

    while (getline(entrada, line)){ // Lee una linea del archivo y la almacena en line
        stringstream s(line); // usado para separar las palabras split()
        iR = 0; // Cada vez que inicia una nueva linea inicializar iR = 0

        //Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while(getline(s,word,',')){
            row[iR++] = word; // añade word al arreglo row e incrementa iR p/la proxima palabra
        }

        //Determinar si la linea es P-Pelicula, S-Serie, E-Episocio
        if(row[0] == "P"){
            // Se crea un apuntador usando el operador new y el constructor con parametros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas] -> str() << endl;
            cantidadPeliculas++; //inc la cantidad de peliculas
        }
        else if(row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //cout << "Serie" << arrPtrSeries[cantidadSeries] -> str() << endl;
            cantidadSeries++;
        }
        else if(row[0] == "E"){
            // Calcular a que Serie le pertenece el episodio?
            index = stoi(row[1]) - 500;
            // Se agrega el episodio usando el metodo agregaEpisodio
            // Se crea el apuntador y se convierte a objeto usando el operador de indireccion
            arrPtrSeries[index] -> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            // cout << "Episodio" << arrPtrSeries[index] -> str() << endl;
        }
    }

    // fuera del ciclo
    // ya se termino de leer todo el archivo ahora se guardan los 
    // todos los apuntadores de Pelicula y Serie en el arrPtrVideo
    // copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificacionPromedio
    // ya que tiene todos los episodios

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio(); // calcula la calificacion de la Serie
        arrPtrSeries[index] -> setCalificacion(promedio); // cambia la calificacion de la Serie
        // añade el calcular la duracion de la serie
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
     }

     // copiar todos los apuntadores del arreglo de Peliculas al arre3glo de apuntadores de Video
     for(int index = 0; index < cantidadPeliculas; index++){
         arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
     }
    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
     - se da el POLIMORFISMO - SUPER SUPER SUPER !!,
     se ejecuta el metodo str() que corresponde al tipo del apuntador almacenado,
     no el correspondiente al tipo del arreglo
    */
   
   //----------------------------------------------------------------
   //COMENTARIZAR ANTES DE ENTREGAR
   //for(int index = 0; index < cantidad; index++){
  //  cout << index << " " << arrPtrVideos[index]->str() << endl;
   //}
   //----------------------------------------------------------------

   entrada.close(); // cerrar el archivo
}

void Polimorfismo::setPtrVideo(int index, Video *video){
    // validar que el índice al que se quiere acceder exista dentro del arreglo. 
    // Es decir, que esté entre 0 y la cantidad de elementos en el arreglo.
    if (index >= 0 && index < cantidad) {
        arrPtrVideos[index] = video;
    } 
}
void Polimorfismo::setCantidadVideos(int _cantidad){
    if (_cantidad <= MAX_VIDEOS && _cantidad >= 0){
        cantidad = _cantidad; 
    }
   
}

Video* Polimorfismo::getPtrVideo(int index){
    if (index >= 0 && index < cantidad) {
        return arrPtrVideos[index];
    } else { 
        return nullptr ;
    }
}

int Polimorfismo::getCantidad(){
    return cantidad;

}

void Polimorfismo::reporteInventario(){
    //Declaración e inicialización de contadores
    int contadorPeliculas = 0;
    int contadorSeries = 0;

    //Recorres todo el arreglo de ptr con un for 
    for (int index = 0; index<cantidad;index++){
        cout << arrPtrVideos[index] -> str() << endl;
        // * indirección (pointer) ---> objeto
        if (typeid(*arrPtrVideos[index])== typeid(Pelicula)){
            contadorPeliculas++;
        } else if (typeid(*arrPtrVideos[index])== typeid(Serie)){
            contadorSeries++;
        }
    }
    cout << "Peliculas = " << contadorPeliculas << endl;
    cout << "Series = " << contadorSeries << endl;


}
void Polimorfismo::reporteCalificacion(double _calificacion){
//if typeid(*arrPtrVideos[index])== typeid(Pelicula);
int total;
total = 0;

for (int index = 0; index<cantidad;index++){
    
    if (arrPtrVideos[index]->getCalificacion() == _calificacion){
        cout << arrPtrVideos[index] -> str() << endl;
        total++;
    }

}
cout<< "Total = "<< total<<endl;
}
void Polimorfismo::reporteGenero(string _genero){
int total;
total = 0;

for (int index = 0; index<cantidad;index++){
    
    if (arrPtrVideos[index]->getGenero() == _genero){
        cout << arrPtrVideos[index] -> str() << endl;
        total++;
    }

}
cout<< "Total = "<< total<<endl;
}
void Polimorfismo::reportePeliculas(){
    int total;
    total = 0;
    for (int index = 0; index<cantidad;index++){
            if (typeid(*arrPtrVideos[index])== typeid(Pelicula)){
                cout << arrPtrVideos[index] -> str() << endl;
                total++;
            }
            
    }
    if (total == 0){
        cout<< "No peliculas" << endl;
    } else{
        cout<< "Total Peliculas = " << total <<endl;
    }
    

}

void Polimorfismo::reporteSeries(){
    int totalSeries;
    totalSeries = 0;
    for (int index = 0; index<cantidad;index++){
            if (typeid(*arrPtrVideos[index])== typeid(Serie)){
                cout << arrPtrVideos[index] -> str() << endl;
                totalSeries++;
            }
    }
    if (totalSeries == 0){
        cout<< "No series" << endl;
    } else{
        cout<< "Total Series = "<< totalSeries <<endl;
    }
}