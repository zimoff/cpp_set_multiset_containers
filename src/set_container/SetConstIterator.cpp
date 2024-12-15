using namespace s21;
template <typename T>
class set<T>::SetConstIterator {

    private:
        friend class set;
        const Node* node = nullptr;
        const Node* end = nullptr;

    public:
        SetConstIterator(){};
        SetConstIterator(const Node* node): node{node}{}
        SetConstIterator(const iterator it){
            
            node = it.node;
            end = it.end;

        }
        ~SetConstIterator() = default;

        const_reference operator*() ;
        const_iterator operator++();
        const_iterator operator--();
        bool operator==(const set<value_type>::const_iterator& another_it);
        bool operator!=(const set<value_type>::const_iterator& another_it);
};

template <typename T>
const T& set<T>::const_iterator::operator*() {

    return node->key;

}

template <typename T>
bool set<T>::const_iterator::operator!=(const set<value_type>::const_iterator& another_it) {

    return node != another_it.node;
}

template <typename T>
bool set<T>::const_iterator::operator==(const set<value_type>::const_iterator& another_it) {

    return node == another_it.node;

}

template <typename T>
typename set<T>::const_iterator set<T>::const_iterator::operator++() {

    const Node* tmp = iteratorUp_(node);
    if(tmp == node) {
        end = tmp;
        node = nullptr;
    } else
        node = tmp;

    return const_iterator(node);
}

template <typename T>
typename set<T>::const_iterator set<T>::const_iterator::operator--() {

    if(end) {
        node = end;
        end = nullptr;
    } else
        node = iteratorDown_(node);

    return const_iterator(this->node);
}
