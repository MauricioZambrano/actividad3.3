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

    private:
        NodeT *root;
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destruye(root);
}

void BST::add(int key, long ip){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr){        //Llegar hasta nullptr a donde se quiere agregar
        if (curr->getIp() == ip ){  //Si ya existe ese dato te sales (no se pueden repetir datos)
            return;         //Como break pero se sale de la función
        }
        father = curr;
        if(curr->getKey() > key){
            curr = curr->getLeft();
        }
        else if(curr->getKey() < key){
            curr = curr->getRight()
        }
        else{
            curr = (curr->getIp() > ip) ?  curr->getLeft() : curr->getRight(); //Compare Ip with long instead of strings
        }
    }
    if (father == nullptr){
        root = new NodeT(key, ip);
    }
    else{
        (father->getKey() > key) ? father->setLeft(new NodeT(key, ip)) : father->setRight(new NodeT(key, ip));
    }
}