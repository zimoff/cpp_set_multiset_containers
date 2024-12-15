#pragma once
#include <type_traits>  // find args... type
#include <iostream>
#include <limits>
#include <vector>
//using namespace std;

namespace s21 {
    template <typename T>
    class set {

        // list member types
          using value_type = T; //3 
          using reference = T&; //2 done
          using const_reference = const T&; //1 done
          using size_type = size_t; //4
          //using difference_type = ptrdiff_t;



        private:
            struct Node;
            Node* root = nullptr;
            size_type set_size = 0;
            Node* end_ = nullptr;

            //for specification
            std::pair<Node*,bool> insert_(value_type num, Node* node, bool color);
            Node* find_(const value_type& num, Node* node);

            //for algorithm
            int getHigh_(Node* node); // calculate high for all tree, return max high

            Node* whoIsUncle_(Node* node); // return uncle node
            static bool isRightChild_(const Node* node);
            static bool isBlackOrNull_(Node* node);

            Node* unbindNode_(Node* node);
            void recolorNode_(Node* node);
            
            static Node* maxNode_(Node* node);
            static Node* minNode_(Node* node);

            void deleteRebalance_(Node* node); // balance for wrong high
            void insertRebalance_(Node* node); // balance for double red node

            void lineBalance_(Node* node);
            void triangleBalance_(Node* node);
            Node* checkHighBalance_(Node* node); //return node with wrong balance

            void rightRotation_(Node* rotateNode);
            void leftRotation_(Node* rotateNode);

            static const Node* iteratorUp_(const Node* node);
            static const Node* iteratorDown_(const Node* node);

            void clear_(Node* node);

            //debug
            void showTree_(Node* node, int mode);

        public:
            class SetIterator;
            class SetConstIterator;
            using iterator = SetIterator;
            using const_iterator = SetConstIterator;

            set() = default;

            set(std::initializer_list<value_type> const &items) {

                for(const_reference x:items) {
                    insert(x);
                }

            }

            set(const set& other) {
                iterator it_other_begin = other.begin();
                iterator it_other_end = other.end();

                for(;it_other_begin != it_other_end; ++it_other_begin) {
                    insert(*it_other_begin);
                }
            }

            set(set&& move) {

                root = move.root;
                move.root = nullptr;
                set_size = move.set_size;
                move.set_size = 0;
                end_ = move.end_;
                move.end_ = nullptr;
            };

            set& operator= (set&& move) {

                if(&move == this)
                    return *this;

                clear();

                root = move.root;
                move.root = nullptr;
                set_size = move.set_size;
                end_ = move.end_;
                move.end_ = nullptr;
                move.set_size = 0;

                return *this;

            }


            ~set(){
                clear();
            };


            iterator begin() const;
            iterator end() const;

            //---------------specification---------------------

            //modifers >>
            
            void clear(); //clears the contents

            std::pair<iterator, bool> insert(const value_type& key);
                            //inserts node and returns iterator to where the element is in the container 
                            //and bool denoting whether the insertion took place

            void erase(iterator pos); //erases element at pos

            void swap(set& other); //swaps the contents
            void merge(set& other); //splices nodes from another container

            //lookup >>
            
            iterator find(const value_type& key); //finds element with specific key

            bool contains(const value_type& key);  //checks if the container contains element with specific key



            //capacity >>
            
            bool empty();
            size_type size();// not set for delete // size_t >> size_type
            size_type max_size(); // size_t >> size_type


            template <typename ... Args>
            std::vector<std::pair<iterator, bool>> insert_many(Args&&... args);

            //debug
            void showRoot();
            void setColor(value_type key, bool color);
            void nodeInfo(Node* node);
            void showTree(int mode);

    };
} // namespace s21

#include "SetIterator.cpp"
#include "SetConstIterator.cpp"
#include "Node.cpp"
#include "Set_.cpp"
#include "Set.cpp"
#include "Set_debug.cpp"
