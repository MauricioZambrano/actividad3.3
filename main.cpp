/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Actividad 3.4 - Actividad integral de BST
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 25 de octubre del 2020
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "BST.h"

// Carga los registros del archivo .txt a una BST almacenando objetos de tipo Registro
// Complejidad: O(n)
void cargaRegistros(BST &lista){
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    
    int key;
    string anterior;
    
    ifstream archivo("bitacoraOrdenada.txt");
    
    //First Run, hacemos anterior = direcciónIP
    archivo >> mes >> dia >> hora;
    getline(archivo, direccionIP,':');
    getline(archivo, razon);
    anterior = direccionIP;
    
    // Entramos al while para poder seguir comparando el anterior con la siguiente direcciónIP
    while(archivo >> mes >> dia >> hora){
        getline(archivo, direccionIP,':');
        getline(archivo, razon);
        if(direccionIP == anterior){
            key++;
        }else{
            lista.add(key,direccionIP);
            anterior = direccionIP; //anterior es ahora la current direcciónIP
            key = 0;
        }
    }
    
    archivo.close();  
}

int main(){
    BST lista;
    cargaRegistros(lista);
    
    
    return 0;
}

