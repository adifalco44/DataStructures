#include <iomanip>
#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


//template<typename T> class LinkedList;

template<typename T>
class Node {
//  friend class List<T>;
  public:
    Node(const T &);    
    const T getValue();
  private:
    T value;
    Node<T> *next;
};

template<typename T>
Node<T>::Node(const T &val)  :value(val),next(nullptr) {}

template<typename T>
T Node<T>::getValue(){
   return value;
}

template<typename T>
class List {
  public:
     List();
     ~List();
     void pushFront(const T &);
//     void newNode(const T &);
     void print();
     bool empty();
//     Node<T> *newNode(const T &);

   private:
     Node<T> *head;
     Node<T> newNode(const T &);
};

// Contructor
template<typename T>
List<T>::List(){
   head = nullptr;
}

// Deconstructor
template<typename T>
List<T>::~List(){
   if (!empty()){
       Node<T> *curr= head;
       while ( curr != nullptr ){
          Node<T> *next = curr->next;
          delete curr;
          curr = next;
      }   
   } 
}


// Appends List
template<typename T>
void List<T>::pushFront(const T &val){
   Node<T> *n = newNode(val);
   if (empty()){
      head = n;
   }else{
      Node<T> *nn = head;
      while (nn->next != nullptr) nn = nn->next;
      nn->next = n;
   }
   n->next = nullptr;
}

template<typename T>
bool List<T>::empty() { return (head == nullptr); }

// Helper
void List<T>::newNode(const T &val){
   return new Node<T>(val);
}


template<typename T>
void List<T>::print(){
   *n = newNode();                     ^
   Node<T>* curr = head;
   while ( curr->next != nullptr ){
      Node<T>* next = curr->next;
      cout << curr->getValue;
      curr = next;
   }
   cout << endl;
}

int main(){
  string str1, str2;
  while (cin >> str1 >> str2){
    List<char> list1,list2,list3;
    list1.print();
    list2.print();
  }
}
