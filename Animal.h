//Superclase Animal, clase principal
#ifndef ANIMAL_H
#define ANIMAL_H

#include "Comida.h"
#include "Agua.h"
#include <vector> //Librería para usar vectores

class Animal{
    protected:
        string nombre;
        Comida alimento;
        Agua hidratacion;
        int carino;
        int limpieza;
        int puntaje; 
        vector<string> acciones; //Tipo de varible vector

    public:
        Animal();
        Animal(string,Comida,Agua,int,int,int);

        string getNombre();
        void setNombre(string); 

        Comida getAlimento();
        void setAlimento(Comida);

        Agua getHidratacion();
        void setHidratacion(Agua);

        string getCarino();
        void setCarino(int);

        string getLimpieza();
        void setLimpieza(int);

        void calcularPuntaje(int);
        int infoPuntaje();

        void agregarResumen(string);
        vector<string> imprimirResumen();
};

Animal::Animal(){ //Constructor, iniciliza valor de puntaje
    puntaje = 0;
} 
Animal::Animal(string _nombre,Comida _alimento,Agua _hidratacion,int _carino,int _limpieza, int _puntaje){ //Constructor, con todos los atributos
    nombre = _nombre;
    alimento = _alimento;
    hidratacion = _hidratacion;
    carino = _carino;
    limpieza = _limpieza;
    puntaje = _puntaje;
}

string Animal::getNombre(){
    return nombre;
}

void Animal::setNombre(string _nombre){
    nombre = _nombre;
}

Comida Animal::getAlimento(){
    return alimento;
}

void Animal::setAlimento(Comida _comida){
    alimento = _comida;
}

Agua Animal::getHidratacion(){
    return hidratacion;
}

void Animal::setHidratacion(Agua _hidratacion){
    hidratacion = _hidratacion;
}

string Animal::getCarino(){ //Mensaje que regresa de acuerdo a la variable respuestaCarino
    string mensajeCarino;
    if (carino == 1){
        mensajeCarino = "\n Consentiste a tu mascota \n +15 puntos"; //Si la variable respuestaCarino == 1, solo cuando es objeto Gato o Conejo
    }
    else{
        mensajeCarino = "\n Acariciaste a tu mascota \n +20 puntos"; //Si la variable respuestaCarino == 2, solo cuando es objeto Perro o Conejo
    }
    return mensajeCarino;
}

void Animal::setCarino(int _carino){
    carino = _carino;
}

string Animal::getLimpieza(){ //Cuando la variable respuestaCuidados == 4, para Perro y Gato
    string mensajeLimpieza;
    if (limpieza == 4){
        mensajeLimpieza = "\n Limpiaste a tu mascota \n +15 puntos";
    }
    return mensajeLimpieza;
}

void Animal::setLimpieza(int _limpieza){
    limpieza = _limpieza;
}

void Animal::calcularPuntaje(int _puntaje){
    puntaje += _puntaje;
}

int Animal::infoPuntaje(){
    return puntaje;
}

void Animal::agregarResumen(string _acciones){
    acciones.push_back(_acciones);
}

vector<string> Animal::imprimirResumen(){
    return acciones;
}

#endif
