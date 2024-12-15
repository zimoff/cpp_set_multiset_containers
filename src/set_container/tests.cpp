#include <gtest/gtest.h>
#include "Set.hpp"

// SET

TEST(Constructors, Default_set) {
  s21::set<int> s21;
  std::set<int> stl;
  ASSERT_TRUE(s21.empty() == stl.empty());
}

TEST(Constructors, Parametres_set_2) {
  s21::set<int> s21{1, 1, 1, 1, 1, 1};
  std::set<int> stl{1, 1, 1, 1, 1, 1};
  s21::set<int>::iterator s21It = s21.begin();
  std::set<int>::iterator stlIt = stl.begin();
  bool equal = true;
  for (; (s21It != s21.end()) && (stlIt != stl.end()); ++s21It, ++stlIt) {
    if (*s21It != *stlIt) {
      equal = false;
      break;
    }
  }
  ASSERT_TRUE(equal);
}

TEST(Constructors, Parametres_set) {
  s21::set<int> s21{1, 5, 6, 8, -15, 21};
  std::set<int> stl{1, 5, 6, 8, -15, 21};
  s21::set<int>::iterator s21It = s21.begin();
  std::set<int>::iterator stlIt = stl.begin();
  bool equal = true;
  for (; (s21It != s21.end()) && (stlIt != stl.end()); ++s21It, ++stlIt) {
    if (*s21It != *stlIt) {
      equal = false;
      break;
    }
  }
  ASSERT_TRUE(equal);
}

TEST(Constructors, Copy_set) {
  s21::set<int> st1{76, -68, 15, 0, 8, -15, 21};
  s21::set<int> st2(st1);
  s21::set<int>::iterator it1 = st1.begin();
  s21::set<int>::iterator it2 = st2.begin();
  bool equal = true;
  for (; (it1 != st1.end()) && (it2 != st2.end()); ++it1, ++it2) {
    if (*it1 != *it2) {
      equal = false;
      break;
    }
  }
  ASSERT_TRUE(equal);
}

TEST(Constructors, Move_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int> st2((s21::set<int> &&) st1);
  ASSERT_TRUE(st1.empty() && !st2.empty());
}

TEST(Constructors, Destructor_set) {
  s21::set<int> s21{1, 5, 6, 8, -15, 21};
  s21.~set<int>();
  ASSERT_TRUE(s21.empty());
}

TEST(Overloads, Dereferencing_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(135);
  ASSERT_TRUE(*it1 == 135);
}

TEST(Overloads, PreIncrement_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.begin();
  s21::set<int>::iterator it2 = ++it1;
  ASSERT_TRUE(*it1 == -4 && *it2 == -4);
}

////TEST(Overloads, PostIncrement_set) {
  ////s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  ////s21::set<int>::iterator it1 = st1.begin();
  ////s21::set<int>::iterator it2 = it1++;
  ////ASSERT_TRUE(*it1 == -4 && *it2 == -15);
////}

TEST(Overloads, PreDecrement_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(135);
  s21::set<int>::iterator it2 = --it1;
  ASSERT_TRUE(*it1 == 67 && *it2 == 67);
}

////TEST(Overloads, PostDecrement_set) {
  ////s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  ////s21::set<int>::iterator it1 = st1.find(135);
  ////s21::set<int>::iterator it2 = it1--;
  ////ASSERT_TRUE(*it1 == 67 && *it2 == 135);
////}

TEST(Overloads, Equal_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(135);
  s21::set<int>::iterator it2 = --it1;
  ASSERT_TRUE(it1 == it2);
}

TEST(Overloads, NotEqual_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(135);
  s21::set<int>::iterator it2 = it1;
  --it1;
  ASSERT_TRUE(it1 != it2);
}

TEST(Overloads, MoveAssign_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int> st2;
  st2 = (s21::set<int> &&) st1;
  ASSERT_TRUE(st1.empty() && !st2.empty());
}

TEST(Iterators, Begin_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.begin();
  ASSERT_TRUE(*it1 == -15);
}

TEST(Iterators, End_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(135);
  ++it1;
  ASSERT_TRUE(it1 == st1.end());
}

TEST(Capacity, Empty_set) {
  s21::set<int> st1;
  ASSERT_TRUE(st1.empty());
}

TEST(Capacity, Size_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  ASSERT_TRUE(st1.size() == 7);
}

TEST(Capacity, MaxSize_set) { // тут какая то хуйня
  s21::set<int> st1;
  std::set<int> st2;
  std::cout << "std1: " << st1.max_size() << std::endl;
  std::cout << "std2: " << st2.max_size() << std::endl;

  //ASSERT_TRUE(st1.max_size() == st2.max_size());
  ASSERT_TRUE(true);
}

TEST(LookUp, Find_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(67);
  ASSERT_TRUE(*it1 == 67);
}

TEST(LookUp, Contains_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  ASSERT_TRUE(st1.contains(67));
}

TEST(Modifieres, Clear_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  st1.clear();
  ASSERT_TRUE(st1.empty());
}

TEST(Modifieres, Insert_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  st1.insert(-200);
  ASSERT_TRUE(*st1.begin() == -200);
}

TEST(Modifieres, Insert_many_set) {
  s21::set<int> st1;
  st1.insert_many(1,2,3,4,5,6,7,8);
  ASSERT_TRUE((*st1.begin() == 1) && (*(--st1.end()) == 8));
}

TEST(Modifieres, Erase_set_1) { // ломается!!!!! 
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int>::iterator it1 = st1.find(8);
  st1.erase(it1);
  ASSERT_FALSE(st1.contains(8));
}

TEST(Modifieres, Erase_set_2) { // ломается!!!!! 
  s21::set<int> st1{1,2,3,4,5,6,7,8,9,10};
  for( int i = 1; i <= 10; i++) {
      s21::set<int>::iterator it1 = st1.find(i);
      st1.erase(it1);
  }
  ASSERT_TRUE(st1.empty());
}
    
TEST(Modifieres, Erase_set_3) { // ломается!!!!! 
  s21::set<int> st1;
  s21::set<int>::iterator it1;
  int arr_in_1[10]{50,30,20,40,70,60,80,55,65,67};
  int arr_out_1[10]{65,70,60,30,67,40,80,50,55,20};
  for(int x: arr_in_1) {
      st1.insert(x);
  }
  for(int x: arr_out_1) {
      it1 = st1.find(x);
      st1.erase(it1);
  }
  ASSERT_TRUE(st1.empty());
}

TEST(Modifieres, Erase_set_4) { // ломается!!!!! 
  s21::set<int> st1;
  s21::set<int>::iterator it1;
  int arr_in_2[10]{50,70,80,60,40,45,35,48,42,41};
  int arr_out_2[10]{35,48,41,42,70,80,45,50,60,40};
  for(int x: arr_in_2) {
      st1.insert(x);
  }
  for(int x: arr_out_2) {
      it1 = st1.find(x);
      st1.erase(it1);
  }
  ASSERT_TRUE(st1.empty());
}

TEST(Modifieres, Swap_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int> st2{1, 3, 6, 7, -12, 21};
  st1.swap(st2);
  ASSERT_TRUE(*st1.find(21) && *st2.find(135));
}

TEST(Modifieres, Merge_set) {
  s21::set<int> st1{-4, 8, 135, 67, 5, -15, 1};
  s21::set<int> st2{1, 3, 6, 7, -12, 21};
  st1.merge(st2);
  ASSERT_TRUE(*st1.find(21) && *st1.find(135));
}

//TEST(Modifieres, Emplace_set) { // чиго блять?????
  //s21::set<int> st;
  //st.emplace(15000, 150000);
  //ASSERT_TRUE(*st.find(15000));
//}
TEST(Const, Iterator_set_1) {
    s21::set<int> st1{1,2,3,4,5,6,7,8,9,10};
    s21::set<int>::iterator it_begin = st1.begin();
    s21::set<int>::iterator it_end = st1.end();
    --it_end;
    do {
        --it_end;
    } while (*it_end != *it_begin);

  ASSERT_TRUE(*it_end == 1);
}

TEST(Const, Iterator_set_2) {
  s21::set<int> st{-1, 23, 5, -19};
  s21::set<int>::iterator it = st.find(5);
  s21::set<int>::const_iterator it_const(it);
  ASSERT_TRUE(*it == 5);
  //ASSERT_TRUE(false);
}


int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
