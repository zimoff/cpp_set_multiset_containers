using namespace s21;

template <typename T>
template <typename ... Args>
std::vector<std::pair<typename multiset<T>::iterator, bool>>  multiset<T>::insert_many(Args&&... args) {

    std::vector<std::pair<iterator, bool>> res;
    for(auto x: {args...}) {

        if (!std::is_same<decltype(x), value_type>::value)
        throw std::out_of_range("wrong type of value");

        res.push_back(std::pair<iterator, bool> (insert(x), true));
    }

    return res;
}

template <typename T>
typename std::pair<typename multiset<T>::iterator, typename multiset<T>::iterator> multiset<T>::equal_range(const_reference key) { //returns range of elements matching a specific key
                                                                                                                                            
    std::pair<iterator,iterator> res;                                                                    

    res.first = lower_bound(key);
    res.second = upper_bound(key);

    return res;

}
template <typename T>
typename multiset<T>::iterator multiset<T>::upper_bound(const_reference key) { //returns an iterator to the first element greater than the given key

    const Node* node = root;
    if(root->key <= key) {
        Node* max = maxNode_(root);

        while(node->key <= key && node->key != max->key) {
            node = iteratorUp_(node);
        }
    } else {
        Node* min = minNode_(root);

        while(node->key > key && node->key != min->key) {
            node = iteratorDown_(node);
        }
        node = ((node == min) && (min->key == key)) ? iteratorUp_(node) : node;
    }

    return iterator(node);

}
template <typename T>
typename multiset<T>::iterator multiset<T>::lower_bound(const_reference key) {

    if(root->key == key)
        return iterator(root);

    const Node* node = root;

    if(root->key  > key) {

        Node* min = minNode_(root);

        while(node->key >= key && node->key != min->key) {
            node = iteratorDown_(node);
        }

        if(node->key < key)
            node = iteratorUp_(node);
        
    } else {

        Node* max = maxNode_(root);

        while(node->key != key && node->key != max->key) {
            node = iteratorUp_(node);
        }

    }

    return iterator(node);
}//returns an iterator to the first element not less than the given key
                                             
template <typename T>
size_t multiset<T>::count(const_reference key) { 

    const Node* node = find_(key, root);
    const Node* tmp = node;
    Node* first = minNode_(root);
    Node* last = maxNode_(root);

    size_t res = 0;


    if(node) {
        res++;

        do {
            node = iteratorDown_(node);
            if(node->key == key)
                res++;

        } while(node->key == key && node != first);
        do  {
            tmp = iteratorUp_(tmp);
            if(tmp->key == key)
                res++;
        } while(tmp->key == key && tmp != last);


    } 

    return res;


} //returns the number of elements matching specific key
template <typename T>
size_t multiset<T>::max_size() {

    std::allocator<Node> tmp;
    return tmp.max_size();
    //return static_cast<size_t>(std::numeric_limits<size_t>::max())/sizeof(multiset<T>::Node)/2;

}
template <typename T>
void multiset<T>::merge(multiset<value_type>& other) {

    typename multiset<value_type>::iterator b = other.begin();
    typename multiset<value_type>::iterator e = other.end();

    for(;b != e; ++b) {
        insert(*b);
    }

    other.clear();

    return;

}
template <typename T>
void multiset<T>::swap(multiset<value_type>& other) {

    std::swap(root,other.root);
    std::swap(end_,other.end_);
    std::swap(multiset_size, other.multiset_size);

    return;
}

template <typename T>
void multiset<T>::clear() {

    clear_(root);
    delete root;
    root = nullptr;
    multiset_size = 0;
    return;
}
template <typename T>
typename multiset<T>::iterator multiset<T>::begin() const {

    iterator it(minNode_(root));
    return it;

}

template <typename T>
typename multiset<T>::iterator multiset<T>::end() const {

    iterator it;
    it.end = maxNode_(root);
    return it;

}

template <typename T>
size_t multiset<T>::size() {

    return multiset_size;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::insert(const_reference key) {


    if(!root) {
        root = new Node(key, true);
        multiset_size++;
        return iterator(root);
    ;
    }

    Node* tmp = insert_(key, root, false);
    iterator res(tmp);
    getHigh_(root);


    return res;
}

template <typename T>
bool multiset<T>::contains(const_reference key) {

    if(find_(key, root))
        return true;

    return false;
}


template <typename T>
bool multiset<T>::empty() {


    if((multiset_size == 0) && (root == nullptr))
        return true;

    return false;
}

template <typename T>
typename multiset<T>::iterator multiset<T>::find(const_reference key) {

    return iterator(find_(key, root));
}


template <typename T>
void multiset<T>::erase(multiset::iterator pos) {

    Node* node = const_cast<Node*>(pos.node);

    if(!node) {
        return;
    }

    Node* tmp = nullptr;

    do {
        if(node->right && node->left) {
            tmp = minNode_(node->right);
            std::swap(node->key, tmp->key);
            node = tmp;
        } 

        if(!node->right && !node->left) {
            if(!node->color) {
                unbindNode_(node);
                delete node;
                multiset_size--;
            } else {
                unbindNode_(node);
                delete node;
                multiset_size--;
                do {
                    getHigh_(root);
                    tmp = checkHighBalance_(root);
                    deleteRebalance_(tmp);
                    getHigh_(root);
                } while(tmp);
            }

            node = root;
            break;
        } 

        if((node->right != nullptr) ^ (node->left != nullptr)) {
            if(node->right) {
                std::swap(node->key, node->right->key);
                delete node->right;
                node->right = nullptr;
                multiset_size--;
            } else {
                std::swap(node->key, node->left->key);
                delete node->left;
                node->left = nullptr;
                multiset_size--;
            }

            node = root;

        } 

    } while(node != root);


    return ;
}
