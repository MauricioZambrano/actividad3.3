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
        bool search(int data);
        void remove(int data);
        void printPre();
        void printIn();
        void printPos();
        void printLevelByLevel();
        int size();
        int height();
        void visit(int option);
        void ancestors(int data);
        int whatlevelamI(int data);
    private:
        NodeT *root;
        void preOrden(NodeT *r);
        void inOrden(NodeT *r);
        void postOrden(NodeT *r);
        void levelByLevel(NodeT *r);
        void destruye(NodeT *r);
        int howManyChildren(NodeT *r);
        int succ(NodeT *r);
        int pred(NodeT *r);
        int count(NodeT *r);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destruye(root);
}

void BST::destruye(NodeT *r){
    if(r != nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

int BST::succ(NodeT *r){
    NodeT *curr = r->getRight();
    while(curr->getLeft() != nullptr){
        curr = curr->getLeft();
    }
    return curr->getData();
}

int BST::pred(NodeT *r){
    NodeT *curr = r->getLeft();
    while (curr->getRight() != nullptr ){
        curr = curr->getRight();
    }
    return curr->getData();
}

void BST::add(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr){        //Llegar hasta nullptr a donde se quiere agregar
        if (curr->getData() == data ){  //Si ya existe ese dato te sales (no se pueden repetir datos)
            return;         //Como break pero se sale de la función
        }
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();       //Se va a lugar a donde se tiene que agregar
    }
    if (father == nullptr){
        root = new NodeT(data);
    }
    else{
        (father->getData() > data) ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
        // if(father->getData() > data){
        //     father->setLeft(new NodeT(data));
        // }
        // else{
        //     father->setRight(new NodeT(data));
        // }
    }
}

bool BST::search(int data){
    NodeT *curr = root;
    while (curr != nullptr){
        if(curr->getData() == data)
            return true;

        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        // if(curr->getData() > data)
        //     curr = curr->getLeft();

        // else
        //     curr = curr->getRight();

    }
    return false;
}

int BST::howManyChildren(NodeT *r){
    int count = 0;
    if (r->getLeft() != nullptr){
        count++;
    }
    if(r->getRight() != nullptr){
        count++;
    }
    return count;
}

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;

    while(curr != nullptr && curr->getData() != data){  //Avanza padre y curr para buscar elemento
        father = curr;                                  //Tiene que ser en este orden                          
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if(curr == nullptr){
        return;         //No esta el elemento salte
    }
    int cantHijos = howManyChildren(curr);

    switch(cantHijos){
        case 0:             //Curr = 0 hijos
            if(father == nullptr){          //Si es el único dato en el BST
                root = nullptr;
            }
            else{
                if(father->getData() > data){   //Determina cual de los dos desligar
                    father->setLeft(nullptr);
                }
                else{
                    father->setRight(nullptr);
                }
            }
            delete curr;
            break;
        case 1:     //Curr tiene un hijo
            if(father == nullptr){          //Quieren borrar el root
                if(curr ->getLeft() != nullptr){    //El único hijo de curr esta  a la izq
                    root = curr->getLeft();
                }
                else{
                    root = curr->getRight();
                }
            }
            else{
                if(father->getData() > data){   //Quiero borrar al hijo izq de padre
                    if(curr->getLeft() != nullptr ){    //El único hijo de curr esta a la izq
                        father->setLeft(curr->getLeft());   //Transladar los nodos a father
                    }
                    else{                               //El único hijo de curr esta a la derecha
                        father->setLeft(curr->getRight());
                    }
                }
                else{       //Quiero borrar al hijo derecho del padre
                    if(curr->getLeft() != nullptr){     //Único hijo de curr esta a la izq
                        father->setRight(curr->getLeft());
                    }
                    else{                               //Único hijo de curr esta a la derecha
                        father->setRight(curr->getRight());
                    }
                }
            }
            delete curr;
            break;
        case 2:
            int succesor = succ(curr);
            remove(succesor);
            curr->setData(succesor);            //Nuevo data del curr es sucessor
            break;
    }
}

//Itera por el arbol en pre orden
//Complejidad: O(n)
void BST::preOrden(NodeT *r){       //Tiene que ser privado porque usuario no tiene acceso a nodos
    if (r != nullptr){
        cout << r->getData() << " ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}

//Llama a printOrden
//Complejidad: O(n)
void BST::printPre(){
    preOrden(root);
    cout << endl;
}

//Itera por el arbol en In Order
//Complejidad: O(n)
void BST::inOrden(NodeT *r){
    if(r != nullptr){
        inOrden(r->getLeft());
        cout << r->getData() << " ";
        inOrden(r->getRight());
    }
}

//Llama a inOrden
//Complejidad: O(n)
void BST::printIn(){
    inOrden(root);
    cout << endl;
}

//Itera por el arbol en post orden
//Complejidad: O(n)
void BST::postOrden(NodeT *r){
    if(r != nullptr){
        postOrden(r->getLeft());
        postOrden(r->getRight());
        cout << r->getData() << " ";
    }
}

//Llama a postOrden
//Complejidad: O(n)
void BST::printPos(){
    postOrden(root);
    cout << endl;
}

//Itera por el arbol a base de nivel
//Complejidad: O(n)
void BST::levelByLevel(NodeT *r){ 
    
    queue<NodeT*> datos;

    if(r != nullptr)
        datos.push(root);

    
    while(!datos.empty()){
        NodeT *curr = datos.front();
        cout << datos.front()->getData() << " ";
        
        if(curr->getLeft() != nullptr){
            datos.push(curr->getLeft());
        }
        if(curr->getRight() != nullptr){
            datos.push(curr->getRight());
        }

        datos.pop();
    }
}

//Llama a Level by Level
//Complejidad: O(n)
void BST::printLevelByLevel(){
    levelByLevel(root);
    cout << endl;
}

//Complejidad: O(n)
int BST::count(NodeT *r){
    if(r == nullptr){
        return 0;
    }
    return 1 + count(r->getLeft()) + count(r->getRight());
}

//Complejidad: O(n)
int BST::size(){
    return count(root);
}

//Una función que recibe un valor del switch como parametro para ver como iterar por el arbol
//Complejidad: O(n)
void BST::visit(int option) {
    switch(option){
        case 1:     //Preorder
            cout << "Pre Order: " << endl;
            printPre();
            break;
        case 2:     //Inorder
            cout << "In Order: " << endl;
            printIn();
            break;
        case 3:     //Postorder
            cout << "Post Order:" << endl;
            printPos();
            break;
        case 4:     //Level by Level
            cout << "Level by Level: " << endl;
            printLevelByLevel();            //ESTE FALTA
            break;
    }

}

//Desplegará los ancestros de un dato
//Complejidad: O(n)
void BST::ancestors(int data){
    stack<int> anc;

    NodeT *curr = root;

    bool flag = false;

    if(curr == nullptr){
        cout << "arbol esta vacío" << endl;
        return;
    }

    if(curr->getData() == data){
        cout << "Ancestros: " << endl;
        cout << "Dato es la raiz" << endl;
        return;
    }
    else if(!search(data)){
        cout << "El dato no existe" << endl;
        return;
    }

    while(curr != nullptr && curr->getData() != data){
        anc.push(curr->getData());
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    cout << "Ancestros: " << endl;
    while(!anc.empty()){
        cout << anc.top() << " ";
        anc.pop();
    }
    cout << endl;
}

//Regresará un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST
//Complejidad: O(n)
int BST::whatlevelamI(int data){
    int counter = 1;
    NodeT *curr = root;
    bool flag = false;


    while(curr != nullptr){
        if(curr->getData() == data){    //Si si esta el dato regresa la cuenta
            return counter;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        counter++;
       
    }

    return -1;      //No existe el dato
}

//Regresará la altura del BST
//Complejidad: O(n)
int BST::height(){
    NodeT *curr = root;
    if(curr == nullptr){
        return 0;
    }

    int right = count(curr->getRight());
    int left = count(curr->getLeft());
    return right > left ? right : left;
}