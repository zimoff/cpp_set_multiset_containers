using namespace s21;
template <typename T>
class set<T>::SetIterator {

    private:
        friend class set;
        const Node* node = nullptr;
        const Node* end = nullptr;

    public:
        SetIterator(){};
        SetIterator(const Node* node): node{node}{
        }
        ~SetIterator() = default;

        const_reference operator*() ;
        iterator operator++();
        iterator operator--();
        bool operator==(const set<value_type>::iterator& another_it);
        bool operator!=(const set<value_type>::iterator& another_it);
};

template <typename T>
const T& set<T>::iterator::operator*() {

    return node->key;

}

template <typename T>
bool set<T>::iterator::operator!=(const set<value_type>::iterator& another_it) {

    return node != another_it.node;

}

template <typename T>
bool set<T>::iterator::operator==(const set<value_type>::iterator& another_it) {

    return node == another_it.node;

}

template <typename T>
typename set<T>::iterator set<T>::iterator::operator++() {

    const Node* tmp = iteratorUp_(node);
    if(tmp == node) {
        end = tmp;
        node = nullptr;
    } else
        node = tmp;

    return iterator(node);
}

template <typename T>
typename set<T>::iterator set<T>::iterator::operator--() {

    if(end) {
        node = end;
        end = nullptr;
    } else
        node = iteratorDown_(node);

    return iterator(this->node);
}
