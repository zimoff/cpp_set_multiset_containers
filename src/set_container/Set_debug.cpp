#define COLOR(X, Y) std::cout << "\x1B[31m" << X << Y << "\033[0m";
template <typename T> 
void set<T>::showRoot() {

    if(root) { 
        std::cout << "root: " << root << std::endl;

        if(root->right)
            std::cout << "root right: " << root->right << std::endl;
        else
            std::cout << "root right null" << root->right << std::endl;

        if(root->left)
            std::cout << "root left: " << root->left << std::endl;
        else 
            std::cout << "root left null" << root->left << std::endl;
    }
    else
        std::cout << "root is NULL: " << std::endl;

}

template <typename T>
void set<T>::showTree_(Node* node, int mode) {

    if(!node) {
        std::cout << "node is null | showTree_|" << std::endl;
        return;
    }

    if(mode == 1)
        nodeInfo(node);

    if(node->left != nullptr) {
        showTree_(node->left, mode);
    }

    if(mode == 0)
        nodeInfo(node);

    if(node->right != nullptr) {
        showTree_(node->right, mode);
    }

    if(mode == 2)
        nodeInfo(node);

    return;
}

template <typename T>
void set<T>::showTree(int mode) {
    if(root)
        showTree_(root, mode);
    else 
        std::cout << "root is null | there is no tree!!!" << std::endl;
}

template <typename T>
void set<T>::setColor(T key, bool color) {

    std::cout << "color key: " << key << std::endl;
    Node* node = searchInner(key,root);


    if(node) {
        std::cout << "node color: " << node->color << std::endl;
        std::cout << "node key: " << *node->key << std::endl;
        node->color = color;
    }else
        std::cout << "node color is null" << std::endl;



    return;
}

template <typename T>
void set<T>::nodeInfo(Node* node) {

    if(!node) {
        std::cout << "node is null" << std::endl;
        return;
    }

    if(node->left)
        std::cout << "left: " << node->left->key << " | ";
    else 
        std::cout << "left null" << " | ";


    if(node->key) {
        if(node->color)
            std::cout << "key: " << node->key << " #";
        else
            COLOR("key: ", node->key);

    }else 
        std::cout << "key null  ";



    if(node->parent)
        std::cout << " parent: " << node->parent->key << " |";
    else
        std::cout << "  ROOT   " << " |";


    if(node->right)
        std::cout << "right: " << node->right->key;
    else 
        std::cout << "right null";

    std::cout << "        balck high: " << node->highBlack << "  ";
    std::cout << "|balance: " << node->blackBalance << " | color: " << node->color << std::endl;


    std::cout << std::endl;

    return;
}
