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
        void print();

    private:
        NodeT *root;
        void destruye(NodeT*);
        void printFive(NodeT*, int&);
        void inordenConv(NodeT*, int&);
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
            curr = (*curr > ip) ?  curr->getRight() : curr->getLeft(); //Compare Ip with long instead of strings
        }
    }
    if (father == nullptr){
        root = new NodeT(key, ip);
    }
    else{
        if(father->getKey() == key)
            (*father > ip) ? father->setRight(new NodeT(key, ip)) : father->setLeft(new NodeT(key, ip));
        else
            (father->getKey() > key) ? father->setLeft(new NodeT(key, ip)) : father->setRight(new NodeT(key, ip));
    }
    
}

void BST::print(){
    int cont = 1;
    cout << "Cinco direcciones IP con la mayor cantidad de accesos:" << endl << endl;
    inordenConv(root, cont);
}

void BST::printFive(NodeT *r, int &cont){
    if(cont <= 5)
        cout << cont << '.' << *r << endl;
}

void BST::inordenConv(NodeT *r, int &cont){
    if(r != nullptr){
        inordenConv(r->getRight(), cont);
        printFive(r, cont);
        cont++;
        inordenConv(r->getLeft(), cont);
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