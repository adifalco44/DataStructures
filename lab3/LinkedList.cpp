// Author: Anthony Di Falco
// LinkedList.cpp
// This is a linked list that enables users to add with precision
// past that capable by double longs (or is it floats?).
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

template <typename T>
class List {
 protected:
   // Creates node to be referenced
   struct Node {
      T data;
      Node *next;

   };
   // Used in functions for reference
   typedef Node * iterator;
   Node *head;
   size_t length;
 public:
   List() : head(nullptr), length(0) {}          // constructor
   iterator front() { return head;  };           // finds front value
   List(const List<T> &);                        // non-default
   List<T>& operator=(List<T>);                  // helper        
   ~List();                                      // deconstructor
   size_t size() const { return length;}         // get function
   void insert (iterator it, const T &data);     // appends list w/ push_back
   T& at(const size_t i);                        // get function
   void swap(List<T> &);                         // swaps values
   void erase (iterator it);                     // helps deconstructor
   void push_back(const T &data);                // appends list
   List<T> addNumberList(List<T> &);             // calculates sum

};

// Deconstructor
template <typename T>
List<T>::~List() {
   Node *next = nullptr;
   // Deletes until empty
   for (Node *curr = head; curr != nullptr; curr = next) {
      next = curr->next;
      delete curr;
   }
}


// Constructor
template <typename T>
List<T>::List(const List<T> &list) : head(nullptr), length(0) {
   for (Node *curr = list.head; curr != nullptr; curr = curr->next){
      push_back(curr->data);
   }
}

//Overloads operator to be used in later functions
template <typename T>
List<T> & List<T>::operator=(List<T> list){
   swap(list);
   return *this;
}

// Get function
template <typename T>
T& List<T>::at(const size_t i){
   Node *node = head;
   size_t n = 0;;
   // Finds Last node  
   while (n < i && node != nullptr){
      node = node->next;
      n++;
   }
   // Displays last node
   if(node){
      return node->data;
   }else{
      cout << "Error" << endl;
   }
   
}

// Inserts val at front
template <typename T>
void List<T>::insert(iterator it, const T &data) {
   // Creates new null ptr if last element
   if (head == nullptr && it == nullptr){
      head = new Node{data,nullptr};
   // Appends normally
   }else{
      Node *node = new Node{data,head};
      head = node;
   }
   length++;
}


// Pushes to back
template <typename T>
void List<T>::push_back(const T& data) {
  // Creates new null ptr if last element
  if (head == nullptr){
     head = new Node{data,nullptr};
  // Appends normally
  }else{
     Node *curr = head;
     Node *tail = head;
     // While not null
     while (curr) {
        tail = curr;
        curr = curr->next;
     }
     // Appends with null at last
     tail->next = new Node{data,nullptr};
  }
  // Updates for reference
  length++;
}

// Swaps node data
template <typename T>
void List<T>::swap(List<T> &list){
  std::swap(head, list.head);
  std::swap(length, list.length);
}

// Used when deconstructor isn't found
template <typename T>
void List<T>::erase(iterator it){
  // If at the head node, delete it
  if (head == it){
     head = head->next;
     delete it;
  // Iterate thru to next, then delete previous
  }else{
     Node *node = head;
     while(node != nullptr && node->next != it){
         node = node->next;
     }     
     node->next = it->next;
     delete it;
  }
  // Update length of list
  length--;
}

// Summation Function
template <typename T>
List<T> List<T>::addNumberList(List<T> &one){
   // Initializations
   List <T> sumList;
   int tmpSum, carry = 0;
   // Iterates thru list one by one
   for (int i =one.size() - 1; i >= 0; i--){
      // Grabs front of list
      auto head = sumList.front();
      // Sums like columns
      tmpSum = at(i) + one.at(i) + carry;
      carry = 0;
      // Ensures carry occurs
      if (tmpSum > 9){
         tmpSum = tmpSum % 10;
         carry = 1;
         sumList.insert(head,tmpSum);
      // Runs when no carry
      }else{
         sumList.insert(head,tmpSum);
      }
   }
   // Appends list if carry ecxeeds length
   if (carry == 1){
      sumList.insert(head,carry);
   }
   return(sumList);
}

int main(int arc, char * argv[]){
   // Three Lists to be Used
   List<int> list1;
   List<int> list2;
   List<int> sumList;
   // tmp's
   int tmp;
   string line;
   // Runs until no input is found
   while (getline(cin,line)){
      istringstream iss(line);
      string num1,num2;
      // Runs until last pair is found
      while (iss >> num1 >> num2){
         // Grabs length of strings
         int length1 = num1.length();
         int length2 = num1.length();;
         int maxlength = 0;
         // Sets length  of greater string
         if (length1 > length2){
            maxlength = length1;  
         }else{
            maxlength = length2;
         }
         int zeros = 0;
         // Creates first list
         for (int i = maxlength - 1; i >= 0; i--){
             auto head1 = list1.front();
             // If the second number is larger
             if (i >= length1){
                zeros = length2 - length1;
                i = length1;
             // Transforms into ints & append
             }else{
                stringstream str;
                string text;
                str << num1[i];
                str >> tmp;
                list1.insert(head1,tmp);
                while (zeros > 0){
                    auto head1 = list1.front();
                    list1.insert(head1,0);
                    zeros--;
                }
             }
         }
         zeros = 0;
         // Createss second list
         for (int i = maxlength - 1; i >= 0; i--){
             auto head2 = list2.front();
             // If the first number is larger
             if (i >= length2){
                zeros = length1 - length2;
                i = length2;
             // Transforms into ints & append
             }else{
                stringstream str;
                string text;
                str << num2[i];
                str >> tmp;
                list2.insert(head2,tmp);
                while (zeros > 0){
                    auto head2 = list2.front();
                    list2.insert(head2,0);
                    zeros--;
                }
             }
         }
      }
      // Adds and displays new list
      sumList = list2.addNumberList(list1);
      for (size_t i = 0; i < sumList.size(); i++){
         cout << sumList.at(i);
      } 
      cout << endl;
      // Deletes lists
      auto tmp = list1.front();
      for (auto it = list1.front(); it != nullptr; it = tmp){
          tmp = it->next;
          list2.erase(it);
      }
      tmp = list2.front();
      for (auto it = list2.front(); it != nullptr; it = tmp){
          tmp = it->next;
          list2.erase(it);
      }
      tmp = sumList.front();      
      for (auto it = sumList.front(); it != nullptr; it = tmp){
          tmp = it->next;
          sumList.erase(it);
      }
   }
}
