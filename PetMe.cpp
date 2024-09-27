// ---------------------------------------------------------------------------------------------------------------- //
/* Archivo que contiene el main para que se ejecute el programa.                                                    */
/* Se crean los objetos para seleccionar la mascota, se imprimen los menus de opciones de las acciones a realizar   */
/* de manera ciclicla (se salen del bucle cuando se haya terminado el tiempo, se llegue al puntaje o se seleccione  */
/* la opción de salir), se mandan a llamar los métodos de las clases, se inicializa el temporizador, se asgina el   */
/* puntaje, se imprime el puntaje final obtenido y el resumen de las acciones realizadas.                           */
// ---------------------------------------------------------------------------------------------------------------- //

#include<iostream>
using namespace std;

#include <chrono> //Librería del temporizador
#include <vector> //Librería para usar vectores

#include "Perro.h"
#include "Gato.h"
#include "Conejo.h"

int main(){
    int seleccionMascota,respuestaCuidados,respuestaComida,respuestaCantComida,respuestaCantAgua,respuestaCarino;
    string nombre;
    vector<string> acciones;
    cout << "\nBienvenid@! \n Selecciona tu mascota y empieza a cuidarla, recuerda que tienes un tiempo limitado y debes conseguir 500 puntos. \n";

//Crea los objetos
    Perro perro1;
    Gato gato1;
    Conejo conejo1;

//Temporizador
    auto start = chrono::system_clock::now();
    auto end = chrono::system_clock::now();
    chrono::duration<float, milli> duration = end - start;
    start = chrono::system_clock::now();
    
    do{ //Bucle para escoger la mascota (perro/gato/conejo)
        cout<<"\n 1. Perro \n 2. Gato \n 3. Conejo \n\n¿Qué mascota te gustaría tener? (Selecciona una opción del 1 - 3): ";
        cin>>seleccionMascota;
        switch(seleccionMascota){
            case 1:{
                cout << "Nombre: "; cin >> nombre;
                perro1.setNombre(nombre);
                cout << "El nombre de tu perro es: " << perro1.getNombre() << endl;
                break;
            }
            case 2:{
                cout << "Nombre: "; cin >> nombre;
                gato1.setNombre(nombre);
                cout << "El nombre de tu gato es: " << gato1.getNombre() << endl;
                break;
            }
            case 3:{
                cout << "Nombre: "; cin >> nombre;
                conejo1.setNombre(nombre);
                cout << "El nombre de tu conejo es: " << conejo1.getNombre() << endl;
                break;
            }
            default:
                cout << "\nOpción inválida. Por favor, elija entre 1 - 3." << endl;
        }
    } while (seleccionMascota < 1 || seleccionMascota > 3); //Se repite hasta que se escoja una opción válida
    
    do{ //Bucle principal, se da el menu de opciones de cuidados, se cicla hasta que se acabe el tiempo o se llegue al puntaje
        cout << "-----------------------------------------------------------" << endl;
        cout << "\nPara cuidar a tu mascota escoge una opción (Selecciona una opción del 1 - 6). \n\n 1. Darle de comer \n 2. Darle agua \n 3. Darle cariño \n 4. Limpiarlo \n 5. Revisar puntaje \n 6. Salir \n\n¿Qué te gustaría hacer?: ";
        cin >> respuestaCuidados; 
        switch(respuestaCuidados){
            case 1:{ //Darle de comer
                cout << "-----------------------------------------------------------" << endl;
                if (seleccionMascota == 1){ //Si es perro, menú de opciones
                    cout << "\nEstas son las opciones de comida para tu mascota. \n\n 1. Croquetas de res \n 2. Croquetas de pollo \n 3. Premio \n\n Selecciona una opción del 1 - 3: "; 
                    cin >> respuestaComida;
                }
                else if(seleccionMascota == 2){ //Si es gato, menú de opciones
                    cout << "\nEstas son las opciones de comida para tu mascota. \n\n 1. Croquetas de salmón \n 2. Croquetas de atún \n 3. Premio \n\n Selecciona una opción del 1 - 3: "; 
                    cin >> respuestaComida;
                }
                else{ //Si es conejo, menú de opciones
                    cout << "\nEstas son las opciones de comida para tu mascota. \n\n 1. Zanahoria \n 2. Lechuga  \n 3. Premio \n\n Selecciona una opción del 1 - 3: "; 
                    cin >> respuestaComida;
                }
                switch(respuestaComida){
                    case 1:{ //Croquetas de res/salmón/zanahoria
                        Comida comida1;
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "\nEstas son las opciones de porciones (Selecciona una opción del 1 - 3). \n\n 1. Media porción \n 2. Una porción \n 3. Dos porciones \n\n ¿Qué porción le quieres dar?: ";
                        cin >> respuestaCantComida;
                        switch(respuestaCantComida){
                            case 1:{ //Media porción
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer media porción de croquetas de res a "<< nombre << endl;
                                    perro1.calcularPuntaje(17);
                                    perro1.agregarResumen("Le diste de comer media porción de croquetas de res"); //Mensajes del resumen que se imprimirá al final
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer media porción de croquetas de salmón a "<< nombre << endl;
                                    gato1.calcularPuntaje(17);
                                    gato1.agregarResumen("Le diste de comer media porción de croquetas de salmón");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer media porción de zanahoria a "<< nombre << endl;
                                    conejo1.calcularPuntaje(17);
                                    conejo1.agregarResumen("Le diste de comer media porción de zanahoria");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            case 2:{ //Una porción
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer una porción de croquetas de res a "<< nombre << endl;
                                    perro1.calcularPuntaje(22);
                                    perro1.agregarResumen("Le diste de comer una porción de croquetas de res");
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer una porción de croquetas de salmón a "<< nombre << endl;
                                    gato1.calcularPuntaje(22);
                                    gato1.agregarResumen("Le diste de comer una porción de croquetas de salmón");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer una porción de zanahoria a "<< nombre << endl;
                                    conejo1.calcularPuntaje(22);
                                    conejo1.agregarResumen("Le diste de comer una porción de zanahoria");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            case 3:{ //Dos porciones
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer dos porciones de croquetas de res a "<< nombre << endl;
                                    perro1.calcularPuntaje(27);
                                    perro1.agregarResumen("Le diste de comer dos porciones de croquetas de res");
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer dos porciones de croquetas de salmón a "<< nombre << endl;
                                    gato1.calcularPuntaje(27);
                                    gato1.agregarResumen("Le diste de comer dos porciones de croquetas de salmón");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer dos porciones de zanahoria a "<< nombre << endl;
                                    conejo1.calcularPuntaje(27);
                                    gato1.agregarResumen("Le diste de comer dos porciones de zanahoria");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            default:
                                cout << "-----------------------------------------------------------" << endl;
                                cout << "\nOpción inválida. Por favor, elija entre 1 - 3." << endl;
                        }
                        break;
                    }
                    case 2:{ //Croquetas de pollo/atún/lechuga
                        Comida comida1;
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "\nEstas son las opciones de porciones (Selecciona una opción del 1 - 3). \n\n 1. Media porción \n 2. Una porción \n 3. Dos porciones \n\n ¿Qué porción le quieres dar?: ";
                        cin >> respuestaCantComida;
                        switch(respuestaCantComida){
                            case 1:{ //Media porción
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer media porción de croquetas de pollo a "<< nombre << endl;
                                    perro1.calcularPuntaje(15);
                                    perro1.agregarResumen("Le diste de comer media porción de croquetas de pollo");
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer media porción de croquetas de atún a "<< nombre << endl;
                                    gato1.calcularPuntaje(15);
                                    gato1.agregarResumen("Le diste de comer media porción de croquetas de atún");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer media porción de lechuga a "<< nombre << endl;
                                    conejo1.calcularPuntaje(15);
                                    conejo1.agregarResumen("Le diste de comer media porción de lechuga");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            case 2:{ //Una porción
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer una porción de croquetas de pollo a "<< nombre << endl;
                                    perro1.calcularPuntaje(20);
                                    perro1.agregarResumen("Le diste de comer una porción de croquetas de pollo");
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer una porción de croquetas de atún a "<< nombre << endl;
                                    gato1.calcularPuntaje(20);
                                    gato1.agregarResumen("Le diste de comer una porción de croquetas de atún");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer una porción de lechuga a "<< nombre << endl;
                                    conejo1.calcularPuntaje(20);
                                    conejo1.agregarResumen("Le diste de comer una porción de lechuga");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            case 3:{ //Dos porciones
                                comida1.setTipoC(respuestaComida);
                                comida1.setCantidadC(respuestaCantComida);
                                if (seleccionMascota == 1){ //Perro
                                    cout << "\nLe diste de comer dos porciones de croquetas de pollo a "<< nombre << endl;
                                    perro1.calcularPuntaje(25);
                                    perro1.agregarResumen("Le diste de comer dos porciones de croquetas de pollo");
                                }
                                else if (seleccionMascota == 2){ //Gato
                                    cout << "\nLe diste de comer dos porciones de croquetas de atún a "<< nombre << endl;
                                    gato1.calcularPuntaje(25);
                                    gato1.agregarResumen("Le diste de comer dos porciones de croquetas de atún");
                                }
                                else{ //Conejo
                                    cout << "\nLe diste de comer dos porciones de lechuga a "<< nombre << endl;
                                    conejo1.calcularPuntaje(25);
                                    conejo1.agregarResumen("Le diste de comer dos porciones de lechuga");
                                }
                                cout << comida1.getTipoC() << endl;
                                cout << comida1.getCantidadC() << endl;
                                break;
                            }
                            default:
                                cout << "-----------------------------------------------------------" << endl;
                                cout << "\nOpción inválida. Por favor, elija entre 1 - 3." << endl;
                                break;
                        }
                        break;
                    }
                    case 3:{ //Premio
                        Comida comida1;
                        comida1.setTipoC(respuestaComida);
                        if (seleccionMascota == 1){
                            perro1.calcularPuntaje(5);
                            perro1.agregarResumen("Le diste de comer un premio");
                        }
                        else if (seleccionMascota == 2){
                            gato1.calcularPuntaje(5);
                            gato1.agregarResumen("Le diste de comer un premio");
                        }
                        else{
                            conejo1.calcularPuntaje(5);
                            conejo1.agregarResumen("Le diste de comer un premio");
                        }
                        cout << "\nLe diste de comer un premio a "<< nombre << endl;
                        cout << comida1.getTipoC() << endl;
                        break;
                    }
                    default:
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "\nOpción inválida. Por favor, elija entre 1 - 3." << endl;
                    break;
                }    
                break;
            }    
            case 2:{ //Darle agua
                Agua agua1;
                cout << "-----------------------------------------------------------" << endl;
                cout << "\nEstas son las opciones de porciones (Selecciona una opción del 1 - 3). \n\n 1. Media porción \n 2. Una porción \n 3. Dos porciones \n\n ¿Qué porción le quieres dar?: ";
                cin >> respuestaCantAgua;
                switch(respuestaCantAgua){
                    case 1:{ //Media porción
                        agua1.setTipoA(1);
                        agua1.setCantidadA(respuestaCantAgua);
                        cout << "\nLe diste de tomar media porción de agua a "<< nombre << endl;
                        cout << agua1.getTipoA() << endl;
                        cout << agua1.getCantidadA() << endl;
                        if (seleccionMascota == 1){
                            perro1.calcularPuntaje(15);
                            perro1.agregarResumen("Le diste de tomar media porción de agua");
                        }
                        else if (seleccionMascota == 2){
                            gato1.calcularPuntaje(15);
                            gato1.agregarResumen("Le diste de tomar media porción de agua");
                        }
                        else{
                            conejo1.calcularPuntaje(15);
                            conejo1.agregarResumen("Le diste de tomar media porción de agua");
                        }
                        break;
                    }
                    case 2:{ //Una porción
                        agua1.setTipoA(1);
                        agua1.setCantidadA(respuestaCantAgua);
                        cout << "\nLe diste de tomar una porción de agua a "<< nombre << endl;
                        cout << agua1.getTipoA() << endl;
                        cout << agua1.getCantidadA() << endl;
                        if (seleccionMascota == 1){
                            perro1.calcularPuntaje(20);
                            perro1.agregarResumen("Le diste de tomar una porción de agua");
                        }
                        else if (seleccionMascota == 2){
                            gato1.calcularPuntaje(20);
                            gato1.agregarResumen("Le diste de tomar una porción de agua");
                        }
                        else{
                            conejo1.calcularPuntaje(20);
                            conejo1.agregarResumen("Le diste de tomar una porción de agua");
                        }
                        break;
                    }
                    case 3:{ //Dos porciones
                        agua1.setTipoA(1);
                        agua1.setCantidadA(respuestaCantAgua);
                        cout << "\nLe diste de tomar dos porciones de agua a "<< nombre << endl;
                        cout << agua1.getTipoA() << endl;
                        cout << agua1.getCantidadA() << endl;
                        if (seleccionMascota == 1){
                            perro1.calcularPuntaje(25);
                            perro1.agregarResumen("Le diste de tomar dos porciones de agua");
                        }
                        else if (seleccionMascota == 2){
                            gato1.calcularPuntaje(25);
                            gato1.agregarResumen("Le diste de tomar dos porciones de agua");
                        }
                        else{
                            conejo1.calcularPuntaje(25);
                            conejo1.agregarResumen("Le diste de tomar dos porciones de agua");
                        }
                        break;
                    }
                    default:
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "\nOpción inválida. Por favor, elija entre 1 - 3." << endl;
                }
                break;
            }
            case 3:{ //Darle cariño
                cout << "-----------------------------------------------------------" << endl;
                if (seleccionMascota == 1){ //Si es perro, menú de opciones
                    cout << "\nEstas son las opciones de cariño para tu mascota (Selecciona una opción del 1 - 2). \n\n 1. Pasear \n 2. Acariciar \n\n Selecciona una opción del 1 - 2: "; 
                    cin >> respuestaCarino;
                }
                else if(seleccionMascota == 2){ //Si es gato, menú de opciones
                    cout << "\nEstas son las opciones de cariño para tu mascota (Selecciona una opción del 1 - 2). \n\n 1. Consentir \n 2. Acariciar \n\n Selecciona una opción del 1 - 2: "; 
                    cin >> respuestaCarino;
                }
                else{ //Si es conejo, menú de opciones
                    cout << "\nEstas son las opciones de cariño para tu mascota (Selecciona una opción del 1 - 2). \n\n 1. Consentir \n 2. Acariciar \n\n Selecciona una opción del 1 - 2: "; 
                    cin >> respuestaCarino;
                }
                switch (respuestaCarino){
                    case 1:{ //Pasear/consentir
                        if (seleccionMascota == 1){ //Pasear solo para perro, método exclusivo de ese objeto
                            perro1.setPasear(respuestaCarino);
                            cout << perro1.getPasear() << endl;
                            perro1.calcularPuntaje(25);
                            perro1.agregarResumen("Sacaste a pasear a tu mascota");
                        }
                        else if (seleccionMascota == 2){ //Consentir gato
                            gato1.setCarino(respuestaCarino);
                            cout << gato1.getCarino() << endl;
                            gato1.calcularPuntaje(15);
                            gato1.agregarResumen("Consentiste a tu mascota");
                        }
                        else{ //Consentir conejo
                            conejo1.setCarino(respuestaCarino);
                            cout << conejo1.getCarino() << endl;
                            conejo1.calcularPuntaje(15);
                            conejo1.agregarResumen("Consentiste a tu mascota");
                        }
                        break;
                    }
                    case 2:{ //Acariciar 
                        if (seleccionMascota == 2){ //Solo si es gato, puntaje exclusivo de ese objeto
                            gato1.setAcariciar(respuestaCarino);
                            cout << gato1.getAcariciar() << endl;
                            gato1.calcularPuntaje(25);
                            gato1.agregarResumen("Acariciaste a tu mascota");
                        }
                        else if (seleccionMascota == 1){ //Si es perro
                            perro1.setCarino(respuestaCarino);
                            cout << perro1.getCarino() << endl;
                            perro1.calcularPuntaje(20);
                            perro1.agregarResumen("Acariciaste a tu mascota");
                        }
                        else{ //Si es conejo
                            conejo1.setCarino(respuestaCarino);
                            cout << conejo1.getCarino() << endl;
                            conejo1.calcularPuntaje(20);
                            conejo1.agregarResumen("Acariciaste a tu mascota");
                        }
                        break;
                    }
                }
                break;
            }
            case 4:{ //Limpiarlo
                if (seleccionMascota == 3){ //Solo si es conejo, puntaje exclusivo de ese objeto
                    conejo1.setLimpieza(respuestaCuidados);
                    cout << conejo1.getLimpieza() << endl;
                    conejo1.calcularPuntaje(20);
                    conejo1.agregarResumen("Limpiaste a tu mascota");
                }
                else if (seleccionMascota == 1){ //Si es perro
                    perro1.setLimpieza(respuestaCuidados);
                    cout << perro1.getLimpieza() << endl;
                    perro1.calcularPuntaje(15);
                    perro1.agregarResumen("Limpiaste a tu mascota");
                } 
                else{ //Si es gato
                    gato1.setLimpieza(respuestaCuidados);
                    cout << gato1.getLimpieza() << endl;
                    gato1.calcularPuntaje(15);
                    gato1.agregarResumen("Limpiaste a tu mascota");
                }
                break;
            }
            case 5:{ //Revisar puntaje
                if (seleccionMascota == 1){
                    cout << "\nTienes " << perro1.infoPuntaje() << " puntos" << endl;                
                }
                else if (seleccionMascota == 2){
                    cout << "\nTienes " << gato1.infoPuntaje() << " puntos" << endl;                
                }
                else{
                    cout << "\nTienes " << conejo1.infoPuntaje() << " puntos" << endl;                
                }
                break;
            }
            case 6:{ //Salir del bucle principal
                cout << "\n Hasta luego!" << endl;
                break;
            }
            default:
                cout << "-----------------------------------------------------------" << endl;
                cout << "\nOpción inválida. Por favor, elija entre 1 - 6." << endl;
            }

            //Cuando se acaba el bucle, dependiendo de si alanzo el puntaje o no es el mensaje final
            end = chrono::system_clock::now();
            duration = end - start;
            if (perro1.infoPuntaje() >= 300) { //Perro
                cout << "-----------------------------------------------------------" << endl;                    
                cout << "\nLo has logrado! Tu puntaje es: " << perro1.infoPuntaje() << endl;
                break;  // Salir del bucle si se alcanza el puntaje deseado
            }
            else if (gato1.infoPuntaje() >= 300) { //Gato
                cout << "-----------------------------------------------------------" << endl;
                cout << "\nLo has logrado! Tu puntaje es: " << gato1.infoPuntaje() << endl;
                break;
            }
            else if (conejo1.infoPuntaje() >= 300) { //Conejo
                cout << "-----------------------------------------------------------" << endl;
                cout << "\nLo has logrado! Tu puntaje es: " << conejo1.infoPuntaje() << endl;
                break;
            }
            else if (duration.count() >= 60000) {
                cout << "-----------------------------------------------------------" << endl;
                cout << "\nEl tiempo se ha terminado. No obtuviste los 300 puntos" << endl;
                if (seleccionMascota == 1){
                    cout << "\nTu puntaje fue de: " << perro1.infoPuntaje() << endl;
                }
                else if (seleccionMascota == 2){
                    cout << "\nTu puntaje fue de: " << gato1.infoPuntaje() << endl;
                }
                else{
                    cout << "\nTu puntaje fue de: " << conejo1.infoPuntaje() << endl;
                } 
                break;
            } 
            if (respuestaCuidados == 6){ //Para poder salir del programa en cuanto el usuario seleccione la opción salir
                break;
            }    
        } while (duration.count() < 60000 && (perro1.infoPuntaje() < 300 && gato1.infoPuntaje() < 300 && conejo1.infoPuntaje() < 300)); //Establece que se muestre el menu hasta que se acabe el tiempo y se tenga menor puntaje del establecido

        //Imprimir el resumen
        if (seleccionMascota == 1){
            vector<string> acciones = perro1.imprimirResumen();
            cout << "\nEstas son las acciones que realizaste: " << endl;
            for (string i: acciones){
            cout << "- " << i << endl;
            } 
        }
        else if (seleccionMascota == 2){
            vector<string> acciones = gato1.imprimirResumen();
            cout << "\nEstas son las acciones que realizaste: " << endl;
            for (string i: acciones){
            cout << "- " << i << endl;
            } 
        }
        else{
            vector<string> acciones = conejo1.imprimirResumen();
            cout << "\nEstas son las acciones que realizaste: " << endl;
            for (string i: acciones){
            cout << "- " << i << endl;
            } 
        }

    getchar(); //Aunque se acabe el programa, la consola sigue abierta para que no se cierre tan rápido
    return 0;
}
