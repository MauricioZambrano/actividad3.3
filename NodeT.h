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
        int getKey(){ return key; }
        void setKey(int key);
        string getIp() {return ip;}
        void setIp(string ip);
        NodeT *getLeft() { return left;}
        void setLeft(NodeT *left);
        NodeT* getRight() { return right;}
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

NodeT::NodeT(int key, string ip){
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->ip = ip;
}

NodeT::NodeT(int key, NodeT *left, NodeT *right){
    this->key = key;
    this->left = left;
    this->right = right;
}

void NodeT::setKey(int key){
    this->key = key;
}

void NodeT::setLeft(NodeT *left){
    this->left = left;
}

void NodeT::setRight(NodeT *right){
    this->right = right;
}

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

// Complejidad: O(n)
bool NodeT::operator>(string ip){
    return ipToLong(this->ip) > ipToLong(ip);
}

ostream& operator<<(ostream& os, NodeT node){
    os << node.ip << " " << node.key << " accesos";
    return os;
}