/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Clase NodeT implementada en Actividad 3.4
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 25 de octubre del 2020
 */

class NodeT{
    public:
        NodeT(int key, string ip);
        NodeT(int key, NodeT *left, NodeT *right);  // No se va a requerir
        int getKey(){ return key; } //Descripción: Función que regresa el valor de key
        void setKey(int key);
        string getIp() {return ip;} //Descripción: Función que regresa el valor de left
        void setIp(string ip);
        NodeT *getLeft() { return left;} //Descripción: Función que regresa el valor de left
        void setLeft(NodeT *left);
        NodeT* getRight() { return right;} //Descripción: Función que regresa el valor de right
        void setRight(NodeT *right);
        bool operator>(string);
        friend ostream& operator<<(ostream &os, NodeT node);
    private:
        int key;
        string ip;
        NodeT *left;
        NodeT *right;
        long ipToLong(string);
};

//Constructor
NodeT::NodeT(int key, string ip){
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->ip = ip;
}

//Constructor
NodeT::NodeT(int key, NodeT *left, NodeT *right){
    this->key = key;
    this->left = left;
    this->right = right;
}

//Descripción: Función para modificar el valor de key
//Complejidad: O(1)
void NodeT::setKey(int key){
    this->key = key;
}

//Descripción: Función para modificar el valor de left
//Complejidad: O(1)
void NodeT::setLeft(NodeT *left){
    this->left = left;
}

//Descripción: Función para modificar el valor de right
//Complejidad: O(1)
void NodeT::setRight(NodeT *right){
    this->right = right;
}

//Descripción: Función para modificar el valor de ip
//Complejidad: O(1)
void NodeT::setIp(string ip){
    this->ip = ip;
}

// Convierte la dirección ip (string) a long para facilitar la comparación entre los datos
// Complejidad: O(n)
long NodeT::ipToLong(string ip){
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

// Descripción: Función que modifica el operador > en la comparación de IPs con el objetivo de compararlos como longs
// Complejidad: O(n)
bool NodeT::operator>(string ip){
    return ipToLong(this->ip) > ipToLong(ip);
}

// Descripción: Función que modifica el operador << para automaticamente desplegar la información requerida.
// Complejidad: O(1)
ostream& operator<<(ostream& os, NodeT node){
    os << node.ip << " " << node.key << " accesos";
    return os;
}
