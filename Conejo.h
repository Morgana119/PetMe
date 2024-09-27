//Subclase Conejo, relacion de herencia con Animal 
#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"

class Conejo : public Animal{
    public:
        Conejo();
        Conejo(string,int);
        string getLimpieza();
        void setLimpieza(int);
};

Conejo::Conejo(){ //Constructor, iniciliza valor de puntaje
    puntaje = 0;
}
Conejo::Conejo(string _nombre,int _puntaje){ //Contructor con atributos de herencia
    nombre = _nombre;
    puntaje = 0;
}
string Conejo::getLimpieza(){ //Método de limpieza diferente para objeto tipo Conejo
    string mensajeLimpieza;
    if (limpieza == 4){ //De acuerdo a la variable respuestaCuidados == 4
        mensajeLimpieza = "\n Limpiaste a tu conejo \n +20 puntos"; //Solo si es objeto tipo Conejo se le dan 20 puntos
    }
    return mensajeLimpieza;
}

void Conejo::setLimpieza(int _limpieza){
    limpieza = _limpieza;
}

#endif
