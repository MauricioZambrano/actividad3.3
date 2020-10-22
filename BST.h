// Mauricio Eugenio Zambrano Díaz
// A000827055
// Actividad 3.4

#include <queue>
#include <stack>
#include "nodeT.h"

class BST{
    public:
        BST();
        ~BST();
        void add(int data);
        // bool search(int data);
        // void remove(int data);
        // void printPre();
        // void printIn();
        // void printPos();
        // void printLevelByLevel();
        // int size();
        // int height();
        // void visit(int option);
        // void ancestors(int data);
        // int whatlevelamI(int data);
    private:
        NodeT *root;
        // void preOrden(NodeT *r);
        // void inOrden(NodeT *r);
        // void postOrden(NodeT *r);
        // void levelByLevel(NodeT *r);
        // void destruye(NodeT *r);
        // int howManyChildren(NodeT *r);
        // int succ(NodeT *r);
        // int pred(NodeT *r);
        // int count(NodeT *r);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destruye(root);
}

void BST::add(int &key, string ip){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr){        //Llegar hasta nullptr a donde se quiere agregar
        if (curr->getIp() == ip ){  //Si ya existe ese dato te sales (no se pueden repetir datos)
            return;         //Como break pero se sale de la función
        }
        father = curr;
        curr = (curr->getKey() > key) ? curr->getLeft() : curr->getRight();       //Se va a lugar a donde se tiene que agregar
    }
    if (father == nullptr){
        root = new NodeT(key, ip);
    }
    else{
        (father->getKey() > key) ? father->setLeft(new NodeT(key, ip)) : father->setRight(new NodeT(key, ip));
    }
}
