/*
 * Programación de estructuras de datos y algoritmos fundamentales
 * Clase BST implementada en Actividad 3.4
 * 
 * Equipo 13
 * 
 * Fernando Doddoli Lankenau - A00827038
 * Mauricio Eugenio Zambrano Díaz - A00827055
 * Cristóbal Alberto Escamilla Sada - A00827074
 * 
 * 25 de octubre del 2020
 */

#include "NodeT.h"

class BST{
    public:
        BST();
        ~BST();
        void add(int, string);

    private:
        NodeT *root;
        void destruye(NodeT*);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destruye(root);
}

void BST::add(int key, string ip){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr){        //Llegar hasta nullptr a donde se quiere agregar
        father = curr;
        if(curr->getKey() > key){
            curr = curr->getLeft();
        }
        else if(curr->getKey() < key){
            curr = curr->getRight();
        }
        else{
            curr = (*curr > ip) ?  curr->getLeft() : curr->getRight(); //Compare Ip with long instead of strings
        }
    }
    if (father == nullptr){
        root = new NodeT(key, ip);
    }
    else{
        (father->getKey() > key) ? father->setLeft(new NodeT(key, ip)) : father->setRight(new NodeT(key, ip));
    }
}

// Borra todos los nodos del árbol
// Complejidad: O(n) 
void BST::destruye(NodeT *r){
    if(r != nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}