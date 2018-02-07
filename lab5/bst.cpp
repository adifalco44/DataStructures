// Author: Anthony Di Falco
// Analyzes an in-order listing of a binary tree
// and determines whether or not it is a binary
// search tree

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Tree {
 public:
   // Constructor
   Tree(){
      count = 0;
//      trees.push_back(0);
   }
   // Deconstructors
   ~Tree(){}
   // sets size limit of vector
   void setCount(int c){
      count = c;
   }
   // Pushes value to back of tree
   void append(int a){
      trees.push_back(a);
   }
   // checks tree's BST-ness
   bool checkTree(){
      // Assumes BST until fault is found
      bool flag = true;
      for (int i = 0; i < count; i++){
         // If within scope, check left subtree
         if (2*i+1 < count){
            if (trees[2*i+1] > trees[i] && trees[i] != -1){
               flag = false;
            }
         }
         // If within scope, check right subtree
         if (2*i+2 < count){
            if (trees[2*i+2] <= trees[i] && trees[2*i+2] != -1){
               flag = false;
            }
         }
      }
      // Returns results
      return flag;
   }
   // Prints results with help of counter and flag
   void print(int j, bool b){
      if (b){
         cout <<  "Tree " << j << " is a BST" << endl;
      }else{
         cout << "Tree " << j << " is not a BST" << endl;
      }
   }

 private:
   // Sets Limits
   int count;
   // Tree values in-order
   vector <int> trees;
};

// driver
int main(){
  // initializations
  int number,tmp2;
  bool flag;
  int counter = 1;
  // runs while input present
  while (cin >> number){
      // initializations
      Tree tree;
      tree.setCount(number);
      // appends tree according to specified set size
      for (int i = 0; i < number; i++){
         tmp2 = 0;
         cin >> tmp2;
         tree.append(tmp2);
      }
      // Returns input based on check
      flag = tree.checkTree();   
      tree.print(counter,flag);
      // iterates for output
      counter++;
  }
  return 0;
}
