using namespace s21;
template <typename T>
template <typename ... Args>
std::vector<std::pair<typename set<T>::iterator, bool>>  set<T>::insert_many(Args&&... args) {

    std::vector<std::pair<iterator, bool>> res;
    for(auto x: {args...}) {

        if (!std::is_same<decltype(x), value_type>::value)
        throw std::out_of_range("wrong type of value");

        res.push_back(insert(x));
    }

    return res;
}
template <typename T>
size_t set<T>::max_size() {

    std::allocator<Node> tmp;
    return tmp.max_size();

}
template <typename T>
void set<T>::merge(set<value_type>& other) {

    typename set<value_type>::iterator b = other.begin();
    typename set<value_type>::iterator e = other.end();

    for(;b != e; ++b) {
        insert(*b);
    }

    other.clear();

    return;

}
template <typename T>
void set<T>::swap(set<value_type>& other) {

    std::swap(root,other.root);
    std::swap(end_,other.end_);
    std::swap(set_size, other.set_size);

    return;
}

template <typename T>
void set<T>::clear() {

    clear_(root);
    delete root;
    root = nullptr;
    set_size = 0;
    return;
}
template <typename T>
typename set<T>::iterator set<T>::begin() const {

    iterator it(minNode_(root));
    return it;

}

template <typename T>
typename set<T>::iterator set<T>::end() const {

    iterator it;
    it.end = maxNode_(root);
    return it;

}

template <typename T>
size_t set<T>::size() {

    return set_size;
}

template <typename T>
std::pair< typename set<T>::iterator,bool > set<T>::insert(const_reference key) {


    std::pair<iterator, bool> res;

    if(!root) {
        root = new Node(key, true);
        set_size++;
        res.first = iterator(root);
        res.second = true;
        return res;
    }

    std::pair<Node*, bool> tmp = insert_(key, root, false);
    res.first = iterator(tmp.first);


    if(tmp.second) {
        res.second = true;
        //getHigh_(root);
    } else {
        res.second = false;
    }

    return res;
}

template <typename T>
bool set<T>::contains(const_reference key) {

    if(find_(key, root))
        return true;

    return false;
}


template <typename T>
bool set<T>::empty() {

    if((set_size == 0) && (root == nullptr))
        return true;

    return false;
}

template <typename T>
typename set<T>::iterator set<T>::find(const_reference key) {

    return iterator(find_(key, root));

}


template <typename T>
void set<T>::erase(set::iterator pos) {

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
                set_size--;
            } else {
                unbindNode_(node);
                delete node;
                set_size--;
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
                set_size--;
            } else {
                std::swap(node->key, node->left->key);
                delete node->left;
                node->left = nullptr;
                set_size--;
            }

            node = root;

        } 

    } while(node != root);

    return ;
}
