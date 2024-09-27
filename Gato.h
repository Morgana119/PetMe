//Subclase Gato, relacion de herencia con Animal 
#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal{
    private:
        int acariciar;

    public:
        Gato();
        Gato(int,string,int);
        string getAcariciar();
        void setAcariciar(int);
};

Gato::Gato(){ //Constructor, iniciliza valor de puntaje
    puntaje = 0;
} 
Gato::Gato(int _acariciar,string _nombre,int _puntaje){ //Contructor con atributos de herencia
    acariciar = _acariciar;
    nombre = _nombre;
    puntaje = 0;
}
string Gato::getAcariciar(){ //Método de cariño diferente para objeto tipo Gato
    string mensajeAcariciar;
    if (acariciar == 2){ //De acuerdo a la variable respuestaCarino, si es objeto tipo Gato, se le asginan 25 puntos
        mensajeAcariciar = "\n Acariciaste a tu gato \n +25 puntos";
    }
    return mensajeAcariciar;
}

void Gato::setAcariciar(int _acariciar){
    acariciar = _acariciar;
}

#endif
