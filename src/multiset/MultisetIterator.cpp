using namespace s21;
template <typename T>
class multiset<T>::MultisetIterator {

    private:
        friend class multiset;
        const Node* node = nullptr;
        const Node* end = nullptr;

    public:
        MultisetIterator(){};
        MultisetIterator(const Node* node): node{node}{
        }
        ~MultisetIterator() = default;

        const_reference operator*() ;
        iterator operator++();
        iterator operator--();
        bool operator==(const multiset<value_type>::iterator & another_it);
        bool operator!=(const multiset<value_type>::iterator & another_it);
};

template <typename T>
const T& multiset<T>::iterator::operator*() {

    return node->key;

}

template <typename T>
bool multiset<T>::iterator::operator!=(const multiset<value_type>::iterator& another_it) {

    return node != another_it.node;

}

template <typename T>
bool multiset<T>::iterator::operator==(const multiset<value_type>::iterator& another_it) {

    return node == another_it.node;

}

template <typename T>
typename multiset<T>::iterator multiset<T>::iterator::operator++() {

    const Node* tmp = iteratorUp_(node);
    if(tmp == node) {
        end = tmp;
        node = nullptr;
    } else
        node = tmp;

    return iterator(node);
}

template <typename T>
typename multiset<T>::iterator multiset<T>::iterator::operator--() {

    if(end) {
        node = end;
        end = nullptr;
    } else
        node = iteratorDown_(node);

    return iterator(this->node);
}
