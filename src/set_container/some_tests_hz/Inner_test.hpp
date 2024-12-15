#include <iostream>

using namespace std;

template <typename T>
class Myclass {


    private:
        struct Node {
            int num = 21;

            Node(int n): num{n} {};
        };

        Node inNode(42);

    public:
        T nums = 0;
        Myclass() = default;
        ~Myclass() = default;




        void print() {
            cout << "Myclass print" << endl;
        };

};
