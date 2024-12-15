using namespace s21;
template <typename T>
void multiset<T>::clear_(Node* node) {

    if(node) {
        clear_(node->left);
        clear_(node->right);
        delete node->left;
        delete node->right;
        node->left = nullptr;
        node->right = nullptr;
    } 

    return;
}
template <typename T>
typename multiset<T>::Node* multiset<T>::maxNode_(Node* node) {

    if(!node)
        return nullptr;

    Node* tmp = node;
    while(tmp->right) {
        tmp = tmp->right;
    }

    return tmp;
}
template <typename T>
typename multiset<T>::Node* multiset<T>::minNode_(Node* node) {

    if(!node)
        return nullptr;

    Node* tmp = node;
    while(tmp->left) {
        tmp = tmp->left;
    }

    return tmp;
}

template <typename T>
typename multiset<T>::Node* multiset<T>::unbindNode_(Node* node) {

    if(node->parent) {
        if(isRightChild_(node))
            node->parent->right = nullptr;
        else
            node->parent->left = nullptr;
    } else 
        root = nullptr;

    return node;
}

template <typename T>
typename multiset<T>::Node const* multiset<T>::iteratorDown_(const Node* node) {
    const Node* tmp = nullptr;


    if(node->left)
        tmp = maxNode_(node->left);
    else {

        if(isRightChild_(node)) {
            tmp = node->parent;
        } else {
            tmp = node;
            while((tmp->parent) && !isRightChild_(tmp)) {
                tmp = tmp->parent;
            }
            if(tmp->parent) {
                tmp = tmp->parent;
            } else { 
                tmp = node;
            }
        }

    }

    return tmp;
        
}

template <typename T>
typename multiset<T>::Node const* multiset<T>::iteratorUp_(const Node* node) {
    const Node* tmp = nullptr;


    if(node->right)
        tmp = minNode_(node->right);
    else {

        if(isRightChild_(node)) {
            tmp = node;
            while((tmp->parent) && isRightChild_(tmp)) {
                tmp = tmp->parent;
            }
            if(tmp->parent) {
                tmp = tmp->parent;
            } else { 
                tmp = node;
            }

        } else {
            tmp = node->parent;
        }

    }

    return tmp;
        
}



template <typename T>
typename multiset<T>::Node* multiset<T>::checkHighBalance_(Node* node) {

    if(!node)
        return nullptr;

    if(node->blackBalance != 0) {
        return node;
    }

    Node* tmp_left = checkHighBalance_(node->left);
    Node* tmp_right = checkHighBalance_(node->right);


    int tmp_high_left = (tmp_left) ? tmp_left->highBlack : 0;
    int tmp_high_right = (tmp_right) ? tmp_right->highBlack : 0;

    return (tmp_high_left > tmp_high_right) ? tmp_left : tmp_right;
}
template <typename T>
bool multiset<T>::isBlackOrNull_(Node* node) {

    if(node)
        return node->color;
    else
        return true;
}

template <typename T>
void multiset<T>::deleteRebalance_(Node* node) {
    if(!node) {
        return;
    };


    Node* child = (node->right) ? node->right : node->left;

    if(!child->color) { // if brother red
        
        child->color = true;
        node->color = false;
        if(isRightChild_(child))
            leftRotation_(node);
        else
            rightRotation_(node);
    } else {   // if brother balck
        
        
        if(isBlackOrNull_(child->right) && isBlackOrNull_(child->left)) { //if all children balck
            
            child->color = false;
            node->color = true;
        } else {
            if(isRightChild_(child)) {

                if(isBlackOrNull_(child->right)) { //if right children black 
                    child->left->color = true;
                    child->color = false;
                    rightRotation_(child);
                    child = child->parent;
                } 
                child->color = child->parent->color;
                child->parent->color = true;
                child->right->color = true;
                leftRotation_(child->parent);

            } else {

                if(isBlackOrNull_(child->left)) { //if right children balck 
                    child->right->color = true;
                    child->color = false;
                    leftRotation_(child);
                    child = child->parent;

                } 
                child->color = child->parent->color;
                child->parent->color = true;
                child->left->color = true;
                rightRotation_(child->parent);

            }

        }


    }

    return;
}




template <typename T>
typename multiset<T>::Node* multiset<T>::find_(const_reference num, Node* node) {

    if(!node) {
        return nullptr;
    }
    if(node->key == num)
        return node;

    //if(node->key < num) {

        //if(node->right) {
            //return find_(num, node->right);
        //}else
            //return nullptr;

    //}else {
        //if(node->left) {
            //return find_(num, node->left);
        //}else
            //return nullptr;
    //}
    
    Node* tmp = nullptr;


    if(node->key < num) {
        if(node->right) 
            tmp = find_(num, node->right);
    }else {
        if(node->left) 
            tmp = find_(num, node->left);
    }

    return tmp;
}


template<typename T>
int multiset<T>::getHigh_(Node* node) {


    if(!node)
        return 0;

    int left = getHigh_(node->left);

    int right = getHigh_(node->right);
    
    if(left > right)
        node->highBlack = (!node->color || !node->parent) ? left : left + 1;
    else
        node->highBlack = (!node->color || !node->parent) ? right : right + 1;

    node->blackBalance = right - left;

    return node->highBlack;

}

template <typename T>
void multiset<T>::insertRebalance_(Node* node) {

    if(node->parent->color) {
        return;
    }

    Node* uncle = nullptr;


    uncle = whoIsUncle_(node->parent);


    if(uncle && !uncle->color) {
        recolorNode_(uncle);
        recolorNode_(node->parent);
        recolorNode_(uncle->parent);
    } else {
        if(isRightChild_(node) ^ isRightChild_(node->parent)) {
            triangleBalance_(node);

        } else { 
            lineBalance_(node);
        }
    }

    if(!root->color)
        root->color = true;



    if((node != root) && node->parent->parent && (node->parent->parent != root))
        insertRebalance_(node->parent->parent);
    else 
        return;
}

template <typename T>
void multiset<T>::triangleBalance_(Node* node) {

    if(isRightChild_(node)) {
        leftRotation_(node->parent);
        recolorNode_(node->parent); //nodeRecolor grand
        recolorNode_(node); //nodeRecolor parent

        rightRotation_(node->parent);
    } else {
        rightRotation_(node->parent);
        recolorNode_(node->parent); //nodeRecolor grand
        recolorNode_(node); //nodeRecolor parent

        leftRotation_(node->parent);
    }

    return;
}

template <typename T>
void multiset<T>::lineBalance_(Node* node) {

    recolorNode_(node->parent->parent); //nodeRecolor grand
    recolorNode_(node->parent); //nodeRecolor parent

    if(isRightChild_(node->parent))
        leftRotation_(node->parent->parent);
    else
        rightRotation_(node->parent->parent);

    return;
}
template <typename T>
bool multiset<T>::isRightChild_(const Node* node) {

        if(node == node->parent->right)
            return true;
        else 
            return false;
}
template <typename T>
typename multiset<T>::Node* multiset<T>::whoIsUncle_(Node* node) {

    Node* uncle = nullptr;

    if(node == node->parent->left) {
        uncle = (node->parent->right) ? node->parent->right : nullptr;
    } else {
        uncle = (node->parent->left) ? node->parent->left : nullptr;
    }

    return uncle;

}
template <typename T>
void multiset<T>::recolorNode_(Node* node) {

    if(node) 
        node->color = (node->color) ? false : true;

    return;

}

template <typename T>
typename multiset<T>::Node* multiset<T>::insert_(value_type num, Node* node, bool color) {

    Node* tmp = nullptr;

    if(node->key < num) {
        if(node->right)
            //return insert_(num, node->right, color);
            tmp = insert_(num, node->right, color);
        else {
            node->right = new Node(num, color);
            tmp = node->right;
            node->right->parent = node;
            multiset_size++;
            insertRebalance_(node->right);
            getHigh_(root);
            //return tmp;
        }

    }else {

        if(node->left)
            tmp = insert_(num, node->left, color);
        else {
            node->left = new Node(num, color);
            tmp = node->left;
            node->left->parent = node;
            multiset_size++;
            insertRebalance_(node->left);
            getHigh_(root);
            //return tmp;
        }
    }

    return tmp;

}

template <typename T>
void multiset<T>::leftRotation_(Node* rotateNode) {


    if(!rotateNode)
        return;

    // check j
    Node* tmp = nullptr;
    if(rotateNode->right->left) {
        tmp = rotateNode->right->left;
    }

    // check "is rotate node is root"
    if(rotateNode->parent) {
        // check side of rotateNode by parent
        if(rotateNode->parent->right == rotateNode)
            // multiset new parent
            rotateNode->parent->right = rotateNode->right;
        else
            rotateNode->parent->left = rotateNode->right;

        rotateNode->right->parent = rotateNode->parent;
    } else {
        rotateNode->right->parent = nullptr;
        root = rotateNode->right;
    }


    // rotating
    rotateNode->right->left = rotateNode;
    rotateNode->parent = rotateNode->right;

    if(tmp) {
        tmp->parent = rotateNode;
        rotateNode->right = tmp;
    } else 
        rotateNode->right = nullptr;

    return;

}

template <typename T>
void multiset<T>::rightRotation_(Node* rotateNode) {

    if(!rotateNode)
        return;

    // check j
    Node* tmp = nullptr;
    if((rotateNode->left) && (rotateNode->left->right)) {
        tmp = rotateNode->left->right;
    }

    // check "is rotate node is root"
    if(rotateNode->parent) {
        // check side of rotateNode by parent
        if(rotateNode->parent->left == rotateNode)
            // set new parent
            rotateNode->parent->left = rotateNode->left;
        else
            rotateNode->parent->right = rotateNode->left;

        rotateNode->left->parent = rotateNode->parent;
    } else {
        rotateNode->left->parent = nullptr;
        root = rotateNode->left;
    }

    
    // rotating
    rotateNode->left->right = rotateNode;
    rotateNode->parent = rotateNode->left;

    if(tmp) {
        tmp->parent = rotateNode;
        rotateNode->left = tmp;
    } else 
        rotateNode->left = nullptr;

    return;

}
