#pragma once
#include <iostream>
#include <vector>
#include <limits>
//using namespace std;

namespace s21 {
    template <typename T>
    class multiset {

        // list member types
          using value_type = T;
          using reference = T&;
          using const_reference = const T&;
          using size_type = size_t;
          //using difference_type = ptrdiff_t;



        private:
            struct Node;
            Node* root = nullptr;
            size_type multiset_size = 0;
            Node* end_ = nullptr;

            //for specification
            Node* insert_(value_type num, Node* node, bool color = true);
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
            class MultisetIterator;
            class MultisetConstIterator;
            using iterator = MultisetIterator;
            using const_iterator = MultisetConstIterator;

            multiset() = default;

            multiset(std::initializer_list<value_type> const &items) {

                for(const_reference x:items) {
                    insert(x);
                }

            }

            multiset(const multiset& other) {
                iterator it_other_begin = other.begin();
                iterator it_other_end = other.end();

                for(;it_other_begin != it_other_end; ++it_other_begin) {
                    insert(*it_other_begin);
                }
            }

            multiset(multiset&& move) {

                root = move.root;
                move.root = nullptr;
                multiset_size = move.multiset_size;
                move.multiset_size = 0;
                end_ = move.end_;
                move.end_ = nullptr;
            };

            multiset& operator= (multiset&& move) {

                if(&move == this)
                    return *this;

                clear();

                root = move.root;
                move.root = nullptr;
                multiset_size = move.multiset_size;
                end_ = move.end_;
                move.end_ = nullptr;
                move.multiset_size = 0;

                return *this;

            }


            ~multiset(){
                clear();
            };


            iterator begin() const;
            iterator end() const;

            //---------------specification---------------------

            //modifers >>
            void clear(); //clears the contents
            iterator insert(const_reference key); 

            void erase(iterator pos); //erases element at pos
            void swap(multiset& other); //swaps the contents
            void merge(multiset& other); //splices nodes from another container

            //lookup >>
            iterator find(const_reference key); //finds element with specific key
            bool contains(const_reference key);  //checks if the container contains element with specific key
                                                   //
            size_type count(const_reference key);  //returns the number of elements matching specific key

            std::pair<iterator,iterator> equal_range(const_reference key);  //returns range of elements matching a specific key

            iterator lower_bound(const_reference key);  //returns an iterator to the first element not less than the given key
                                                         
            iterator upper_bound(const_reference key); //returns an iterator to the first element greater than the given key
            
            //capacity >>
            
            bool empty();
            size_type size();// not set for delete // size_t >> size_type
            size_type max_size(); // size_t >> size_type
            template<typename ... Args>
            std::vector<std::pair<iterator, bool>>  insert_many(Args&&... args);

            //debug
            void showRoot();
            void setColor(value_type key, bool color);
            void nodeInfo(Node* node);
            void showTree(int mode);

    };
} // namespace s21

#include "MultisetIterator.cpp"
#include "MultisetConstIterator.cpp"
#include "Node.cpp"
#include "multiset_.cpp"
#include "multiset.cpp"
#include "debug.cpp"
