// Carga los registros del archivo .txt a una BST almacenando objetos de tipo Registro
// Complejidad: O(n)
void cargaRegistros(BST &lista){
    string mes;
    int dia;
    string hora;
    string direccionIP;
    string razon;
    
    int key;
    long anterior;
    
    ifstream archivo("bitacoraOrdenada.txt");
    
    //First Run, hacemos anterior = direcciónIP
    archivo >> mes >> dia >> hora;
    getline(archivo, direccionIP,":");
    getline(archivo, razon);
    direccionIP = ipToLong(direccionIP);
    anterior = direccionIP;
    
    // Entramos al while para poder seguir comparando el anterior con la siguiente direcciónIP
    while(archivo >> mes >> dia >> hora){
        getline(archivo, direccionIP,":");
        getline(archivo, razon);
        direccionIP = ipToLong(direccionIP);
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
    
    
    return 0;
}

