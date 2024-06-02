/*
- Nombre: Marco Antonio López de la Puente 
- Matricula: A01285789
- Carrera: ITC
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
Aprendí a utilizar la declaración de atributos Protected, que permiten solo a clases friend
acceder a las mismas.
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

class Video {

    protected: 

        string id, titulo, genero;
        int duracion;
        double calificacion;

    public: 

        //Constructor default 
        Video();
        //Constructor parametros
        Video(string _id, string _titulo, int _duracion, string _genero, double _calificacion);

        //Metodos de acceso, retornan un valor del atributo
        string getId();
        string getTitulo();
        int getDuracion();
        string getGenero();
        double getCalificacion();


        //Modifican un valor del atributo
        
        void setId(string _id);
        void setTitulo(string _titulo);
        void setDuracion(int _duracion);
        void setGenero(string _genero);
        void setCalificacion(double _calificacion);

        //Metodos 
        virtual string str();

};



#endif /* Video_hpp */