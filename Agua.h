//Subclase Agua, relación de tipo agregación con Animal
#ifndef AGUA_H
#define AGUA_H

class Agua{
    private:
        int tipoAgua;
        int cantidadAgua;

    public:
        Agua();
        Agua(int,int);

        string getTipoA();
        void setTipoA(int);
        string getCantidadA();
        void setCantidadA(int);
};

Agua::Agua(){} 
Agua::Agua(int _tipoAgua,int _cantidadAgua){
    tipoAgua = _tipoAgua;
    cantidadAgua = _cantidadAgua;
}

string Agua::getTipoA(){ //De acuerdo a la varibale respuestaCuidados == 2 (Darle agua)
    string mensajeTipo;
    if (tipoAgua == 1){
        mensajeTipo = "\n Agua +10 puntos";
    }
    return mensajeTipo;
}

void Agua::setTipoA(int _tipoAgua){
    tipoAgua = _tipoAgua;
}

string Agua::getCantidadA(){ //De acuerdo a la variable respuestaCantAgua
    string mensajeCant;
    if (cantidadAgua == 1){ //Media porción
        mensajeCant = " Media porción +5 puntos"; 
    }
    else if (cantidadAgua == 2){ //Una porción
        mensajeCant = " Una porción +10 puntos";
    }
    else{ //Dos porciones
        mensajeCant = " Dos porciones +15 puntos";
    }
    return mensajeCant;
}

void Agua::setCantidadA(int _cantidadAgua){
    cantidadAgua = _cantidadAgua;
}

#endif
