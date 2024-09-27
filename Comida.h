//Subclase Comida, relación de tipo agregación con Animal
#ifndef COMIDA_H
#define COMIDA_H

#include<iostream>
using namespace std;

class Comida{
    private:
        int tipoComida;
        int cantidadComida;

    public:
        Comida();
        Comida(int,int);

        string getTipoC();
        void setTipoC(int);
        string getCantidadC();
        void setCantidadC(int);
};

Comida::Comida(){} 
Comida::Comida(int _tipoComida,int _cantidadComida){
    tipoComida = _tipoComida;
    cantidadComida = _cantidadComida;
}

string Comida::getTipoC(){ //De acuerdo a la variable respuestaCuidados == 1 (Darle de comer)
    string mensajeTipo;
    if (tipoComida == 1){ //De acuerdo a la variable respuestaComida
        mensajeTipo = "\n +12 puntos"; //Croquetas de res/salmón / zanahoria = 12 puntos
    }
    else if (tipoComida == 2){ //De acuerdo a la variable respuestaComida
        mensajeTipo = "\n +10 puntos"; //Croquetas de pollo/atún / lechuga = 10 puntos
    }
    else{ //De acuerdo a la variable respuestaComida
        mensajeTipo = "\n +5 puntos"; //Premios = 5 puntos
    }
    return mensajeTipo;
}

void Comida::setTipoC(int _tipoComida){
    tipoComida = _tipoComida;
}

string Comida::getCantidadC(){ //De acuerdo a la variable respuestaCantComida es el mensaje que se regresa
    string mensajeCant;
    if (cantidadComida == 1){ //Media porción
        mensajeCant = " Media porción +5 puntos"; 
    }
    else if (cantidadComida == 2){ //Una porción
        mensajeCant = " Una porción +10 puntos";
    }
    else{ //Dos porciones
        mensajeCant = " Dos porciones +15 puntos";
    }
    return mensajeCant;
}

void Comida::setCantidadC(int _cantidadComida){
    cantidadComida = _cantidadComida;
}

#endif
