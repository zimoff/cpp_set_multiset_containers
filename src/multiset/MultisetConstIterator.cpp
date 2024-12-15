using namespace s21;
template <typename T>
class multiset<T>::MultisetConstIterator {

    private:
        friend class multiset;
        const Node* node = nullptr;
        const Node* end = nullptr;

    public:
        MultisetConstIterator(){};
        MultisetConstIterator(const Node* node): node{node}{}
        MultisetConstIterator(const iterator it){
            
            node = it.node;
            end = it.end;

        }
        ~MultisetConstIterator() = default;

        const_reference operator*() ;
        const_iterator operator++();
        const_iterator operator--();
        bool operator==(const multiset<value_type>::const_iterator& another_it);
        bool operator!=(const multiset<value_type>::const_iterator& another_it);
};

template <typename T>
const T& multiset<T>::const_iterator::operator*() {

    return node->key;

}

template <typename T>
bool multiset<T>::const_iterator::operator!=(const multiset<value_type>::const_iterator& another_it) {

    return node != another_it.node;

}

template <typename T>
bool multiset<T>::const_iterator::operator==(const multiset<value_type>::const_iterator& another_it) {

    return node == another_it.node;
}

template <typename T>
typename multiset<T>::const_iterator multiset<T>::const_iterator::operator++() {

    const Node* tmp = iteratorUp_(node);
    if(tmp == node) {
        end = tmp;
        node = nullptr;
    } else
        node = tmp;

    return const_iterator(node);
}

template <typename T>
typename multiset<T>::const_iterator multiset<T>::const_iterator::operator--() {

    if(end) {
        node = end;
        end = nullptr;
    } else
        node = iteratorDown_(node);

    return const_iterator(this->node);
}
