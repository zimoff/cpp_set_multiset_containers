//#include "Inner_test.hpp"
#include <iostream>
#include <set>

int main() {
    //std::set<std::string> myset;
    std::set<int> myset;


    //std::set<std::string>::iterator it_b = myset.begin();
    //std::cout << "iterator begin: " << *it_b << std::endl;

    for(int i = 1; i <= 10; i++) {
        myset.insert(i);
    }

    std::set<int>::iterator it = myset.end();
    std::cout << "iterator: " << *(--it) << std::endl;


    //std::set<std::string>::iterator it_e = myset.end();
    //std::cout << "iterator end: " << *it_e << std::endl;

    //for(std::set<int>::iterator i = myset.begin(); i != myset.end(); i++) {
        //std::cout << "i: " << *i << std::endl;
    //}

    //it_b++;
    //std::cout << "iterator 10 after: " << *it_b << std::endl;
    //std::cout << "iterator end contain: " << *it_e << std::endl;


    return 0;
}
