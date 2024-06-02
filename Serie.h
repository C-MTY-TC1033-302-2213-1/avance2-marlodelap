/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
Aprendí a utilizar los conceptos de herencia para crear una clase derivada. 
Además, aprendí que los getters y setters no necesariamente se limitan a sus argumentos default, 
por ejemplo, se puede crear un getter con argumentos, y un setter con ninguno.
*/
#ifndef Serie_h
#define Serie_h
//Para herencia
#include "Video.h"
//Para composición
#include "Episodio.h"

class Serie : public Video{
    private :
    Episodio episodios[5];
    int cantidad;

    public: 

    Serie();
    Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion);

    void calculaDuracion();

    //Metodos modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();


    double calculaPromedio();
    string str();

    void agregaEpisodio(Episodio episodio);


};



#endif 