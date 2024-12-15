using namespace s21;
template <typename T>
struct set<T>::Node {

        value_type key;
        Node* left = nullptr;
        Node* right = nullptr; 
        Node* parent = nullptr;

        bool color = true; //true - black / red - false
                           
        int blackBalance = 0;

        int highBlack = 0;

        Node() = default;
        Node(value_type key_val): key {key_val} {};
        Node(value_type key_val, bool color): key {key_val} , color{color} {};

        ~Node() = default;

};
