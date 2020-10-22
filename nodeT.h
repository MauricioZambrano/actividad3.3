class NodeT{
    public:
        NodeT(int key);
        NodeT(int key, NodeT *left, NodeT *right);  //No se va a requerir
        int getData(){ return data; }
        void setData(int key);
        string getIp() {return ip;}
        void setIp(string ip);
        NodeT *getLeft() { return left;}
        void setLeft(NodeT *left);
        NodeT* getRight() { return right;}
        void setRight(NodeT *right);
    private:
        int key;
        string ip;
        NodeT *left;
        NodeT *right;
};

NodeT::NodeT(int key){
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->string = "";
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