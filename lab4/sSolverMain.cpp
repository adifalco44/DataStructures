#include "sSolver.cpp"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;

int main(){
   cout << "Welcome, to exit, name your file 'q' \n"; 
   Board sudoku;
   string filename = "   ";
   while (filename !="q"){
      cout << "enter filename: " << endl;
      cin >> filename;
      int count = 0;
      int count1 = 0;
      string a;
      fstream filestr;
      filestr.open(filename);
      if (filestr.is_open()){
         cout << "Opening " << filename << " . . . .  \n";
         while (filestr >> a){
            for (auto it = a.begin(); it != a.end(); it++){
               if (*it != ' '){               
                  int a = *it - 48;
                  cout << *it << "(" << count%9 << "," << count1 << ") ";
                  sudoku.setValue(count1,count%9,a); 
                  count++;      
               }
            }
            count1++;
            cout << endl;
         }
         filestr.close();  
         while (sudoku.isSolved()){
            sudoku.findPoss();
            sudoku.solve();
         }
         cout << "Solution: \n";
         sudoku.print();
      }else{
         cout << "Invalid file" << endl;
     }
  }
  return 0;
}



