#include <iostream>
#include <set>
#include "multiset.hpp"


using namespace std;
//using namespace s21;

int main() {

    cout << "hello!" << endl;

    

    //s21::multiset<int> st1{-4, 8, 135, 67, 5, -15, 1};
    //s21::multiset<int> st1{1,1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,7,7,7,7,7};
    //s21::multiset<int>::MultisetIterator it_insert;
    
    s21::multiset<int> st1{-4, 8, 135, 67, 5, -15, 1};
    cout << "######### find ################################" << endl;
    s21::multiset<int>::MultisetIterator it1 = st1.find(135);
    //s21::multiset<int> st1{1,2,3,4,4,4,5,6};
    //std::multiset<int> st2{1,2,3,4,4,4,5,6};
    //s21::multiset<char> char_s21{'a','b','c','d'};
    //std::multiset<char> char_std{'a','b','c','d'};
    //std::vector<std::pair<s21::multiset<int>::MultisetIterator, bool>> res_vec = st1.insert_many(1, 1, 2, 3);
    //cout << "######### vector ################################" << endl;

    //for (auto x: res_vec) {
        //cout << *x.first << "| " << x.second << endl;
    //}

    cout << "######### set ################################" << endl;
    st1.showTree(1);

    cout << "######### find ################################" << endl;
    cout << "find " << *it1 <<  endl;


    //std::pair<s21::multiset<int>::MultisetIterator, s21::multiset<int>::MultisetIterator> eq_s21 = st1.equal_range(7);
    //std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> eq_std = st2.equal_range(7);
    //std::pair<s21::multiset<char>::MultisetIterator, s21::multiset<char>::MultisetIterator> eq_s21 = char_s21.equal_range('e');
    //std::pair<std::multiset<char>::iterator, std::multiset<char>::iterator> eq_std = char_std.equal_range('e');
    //cout << "eq_range_std first: " << *eq_std.first << endl;
    //cout << "eq_range_std second: " << *eq_std.second << endl;
    //--eq_std.first;
    //cout << "eq_range_std first: " << *eq_std.first<< endl;
    //cout << "#########################################" << endl;

    //cout << "eq_range_s21 first: " << *eq_s21.first << endl;
    //cout << "eq_range_s21 second: " << *eq_s21.second << endl;
    //cout << "#########################################" << endl;

    //s21::multiset<int>::MultisetIterator it_upper_21 = st1.upper_bound(6);
    //std::multiset<int>::iterator it_upper_std = st2.upper_bound(6);
    //cout << "bound_std: " << *it_upper_std << endl;
    //cout << "bound_s21: " << *it_upper_21 << endl;

    return 0;

}

    //int arr_in_1[10]{50,30,20,40,70,60,80,55,65,67};
    //int arr_in_2[10]{50,70,80,60,40,45,35,48,42,41};
    //int arr_out_1[10]{65,70,60,30,67,40,80,50,55,20};
    //int arr_out_2[10]{35,48,41,42,70,80,45,50,60,40};
     

    // right side test
    //cout << " ################# >>> del 65 <<<" << endl;
    //tmp = tree.find(65);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 70 <<<" << endl;
    //tmp = tree.find(70);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 60 <<<" << endl;
    //tmp = tree.find(60);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 30 <<<" << endl;
    //tmp = tree.find(30);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 67 <<<" << endl;
    //tmp = tree.find(67);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 40 <<<" << endl;
    //tmp = tree.find(40);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 80 <<<" << endl;
    //tmp = tree.find(80);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 50 <<<" << endl;
    //tmp = tree.find(50);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 50 <<<" << endl;
    //tmp = tree.find(50);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 55 <<<" << endl;
    //tmp = tree.find(55);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    //cout << " ################# >>> del 55 <<<" << endl;
    //tmp = tree.find(20);
    //tree.deleteInner(tmp);
    ////tree.getHighBlack();

    // left side test
    //cout << "#################################################" << endl;
    //cout << ">>> del 35 <<<" << endl;
    //tmp = tree.search(35);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();


    //cout << ">>> del 48 <<<" << endl;
    //tmp = tree.search(48);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << ">>> del 41 <<<" << endl;
    //tmp = tree.search(41);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << ">>> del 42 <<<" << endl;
    //tmp = tree.search(42);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << ">>> del 70 <<<" << endl;
    //tmp = tree.search(70);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 80 <<<" << endl;
    //tmp = tree.search(80);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 45 <<<" << endl;
    //tmp = tree.search(45);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 50 <<<" << endl;
    //tmp = tree.search(50);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 60 <<<" << endl;
    //tmp = tree.search(60);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();

    //cout << " ################# >>> del 40 <<<" << endl;
    //tmp = tree.search(40);
    //tree.deleteInner(tmp);
    //tree.getHighBlack();
    ////left side test fin


    //tree.insertNode(70, false);
    //tree.insertNode(65, false);

    // rotate with all childs
    //tree.insertNode(50);

    //tree.insertNode(30);
    //tree.insertNode(20);
    //tree.insertNode(40);

    //tree.insertNode(70);
    //tree.insertNode(60);
    //tree.insertNode(80);

    //tree.insertNode(85);
    //tree.insertNode(75);

    //tree.insertNode(55);
    //tree.insertNode(65);
    //tree.insertNode(67);

    // rotate right
    //tree.insertNode(15);
    //tree.insertNode(21);
    //tree.insertNode(10);
    
    // rotate left
    //tree.insertNode(90);
    //tree.insertNode(75);
    //tree.insertNode(95);
    //
    // rotate root right
    //tree.insertNode(50);
    //tree.insertNode(40);
    //tree.insertNode(30);

    // rotate root left 
    //tree.insertNode(50);
    //tree.insertNode(60);
    //tree.insertNode(70);

    // double ratate right
    //tree.insertNode(50);
    //tree.insertNode(60);
    //tree.insertNode(55);

    // double ratate left 
    //tree.insertNode(50);
    //tree.insertNode(40);
    //tree.insertNode(45);
