//Subclase Perro, relacion de herencia con Animal 
#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal{
    private:
        int pasear;
    public:
        Perro();
        Perro(int,string,int);
        string getPasear();
        void setPasear(int);
};

Perro::Perro(){ //Constructor, iniciliza valor de puntaje
    puntaje = 0;
}
Perro::Perro(int _pasear,string _nombre,int _puntaje){ //Contructor con atributos de herencia
    pasear = _pasear;
    nombre = _nombre;
    puntaje = 0;
}
string Perro::getPasear(){ //Método de cariño diferente para objeto tipo Perro
    string mensajePasear;
    if (pasear == 1){ //De acuerdo a la variable respuestaCarino, si es objeto tipo Perro, se le asginan 25 puntos
        mensajePasear = "\n Sacaste a pasear a tu perro \n +25 puntos"; 
    }
    return mensajePasear;
}

void Perro::setPasear(int _pasear){
    pasear = _pasear;
}

#endif
