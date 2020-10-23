#include <iostream>
using namespace std;
#include "BST.h"


// Carga los registros del archivo .txt a una BST almacenando objetos de tipo Registro
// Complejidad: O(n)
void cargaRegistros(BST &lista){
    
}

// Convierte la dirección ip (string) a long para facilitar la comparación entre los datos
// Complejidad: O(n)
long ipToLong(string ip){
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
    
	return datoFinal;
}

int main(){
    BST lista;
    cargaRegistros(lista);

    cout << ipToLong("234.5.67.88") << endl;
    
    
    return 0;
}
