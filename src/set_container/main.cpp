#include <iostream>
#include <set>
#include "Set.hpp"


using namespace std;
//using namespace s21;

int main() {

    cout << "hello!" << endl;

    //s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
    //s21::set<int> st1{1,2,3,4,5,6,7};
    //std::set<int> set_std;
    //s21::set<int> st1;
    //s21::set<int> st2;
    //cout << "######### before st1 ################################" << endl;
    
    //std::vector<std::pair<s21::set<int>::SetIterator, bool>> res_vec = st1.insert_many(1, 1, 2, 3);
    ////st1.showTree(0);
    //cout << "######### after st2 ################################" << endl;
    ////st1.showTree(0);
    //cout << "######### vector ################################" << endl;
    ////std::pair<s21::set<int>::SetIterator,bool> insert_pair;
    ////std::pair<std::set<int>::iterator,bool> insert_pair_std;
    //for(auto& x: res_vec) {

        ////insert_pair = st1.insert(x); 
        //cout << *x.first << "res: " << x.second << endl;
    //}
    
    //s21::set<int>::SetIterator it_begin = st1.begin();
    //cout << "begin: " << *it_begin << endl;

    s21::set<int> st1{1,2,3,4,5,6,7,8,9,10};
    s21::set<int>::SetIterator it_begin = st1.begin();
    s21::set<int>::SetIterator it_end = st1.end();

    cout << "######### erase ################################" << endl;
    --it_end;
    //for( int i = 1; i <= 10; i++) {
    for( ; *it_end != *it_begin; --it_end) {
        cout << "num: " << *it_end << endl;
    }
    --it_end;
    cout << "last num: " << *it_end << endl;
    
    //cout << "######### empty test ################################" << endl;
    //st1.showTree(0);
    

    cout << "######### empty test ################################" << endl;
    cout << "st1 size " << st1.size() << endl;
    cout << "=====================" << endl;
    cout << "st1 empty " << st1.empty() << endl;
    

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
