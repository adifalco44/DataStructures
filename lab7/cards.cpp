/* This program ranks players cards
using standard insertion sort. 
Author: Anthony Di Falco
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

// Used for every iteration
struct Hands{
    vector <int> value;
    vector <string> name;
    vector <string> rank;
};

int main(){
   // Initializations
   int numHands;
   cin >> numHands;
   // Runs until -1 input
   while (numHands > 0){
    Hands tmp1;
    // Parses input
    for (int i = 0; i < numHands; i++){
        string name,tmpvalue,rank;
        int value;
        // Pushes Back Name
        cin >> name;
        tmp1.name.push_back(name);
        // Pushes Back Values
        cin >> tmpvalue;
        // Converts Face Cards to Ints
        if (tmpvalue == "A"){
            value = 14;
        }else if (tmpvalue == "J"){
            value = 11;
        }else if (tmpvalue == "Q"){
            value = 12;
        }else if (tmpvalue == "K"){
            value = 13;
        }else{
            value = stoi(tmpvalue);
        }
        tmp1.value.push_back(value);
        // Pushes Back Ranks
        cin >> rank;
        tmp1.rank.push_back(rank);
    }
    int i,j,tmpvalue;
    string tmpname;
    string tmprank;
    // Standard Insertion Sort
    for (i = 0; i < tmp1.value.size(); i++){
        j = i;
        while (j > 0 && tmp1.value[j] < tmp1.value[j-1]){
            // Swaps Values
            tmpvalue = tmp1.value[j];
            tmp1.value[j] = tmp1.value[j-1];
            tmp1.value[j-1] = tmpvalue;
            // Swaps Names
            tmpname = tmp1.name[j];
            tmp1.name[j] = tmp1.name[j-1];
            tmp1.name[j-1] = tmpname;
            // Swaps Ranks
            tmprank = tmp1.rank[j];
            tmp1.rank[j] = tmp1.rank[j-1];
            tmp1.rank[j-1] = tmprank;
            j--;
        }
    }
    // Checks for Equal Values
    for (int x = 0; x < tmp1.value.size() - 1; x++){
        if (tmp1.value[x] == tmp1.value[x+1]){
            if (tmp1.rank[x] > tmp1.rank[x+1]){
                // Swaps Values 
                tmpvalue = tmp1.value[x];
                tmp1.value[x] = tmp1.value[x+1];
                tmp1.value[x+1] = tmpvalue;
                // Swaps Names
                tmpname = tmp1.name[x];
                tmp1.name[x] = tmp1.name[x+1];
                tmp1.name[x+1] = tmpname;
                // Swaps Ranks
                tmprank = tmp1.rank[x];
                tmp1.rank[x] = tmp1.rank[x+1];
                tmp1.rank[x+1] = tmprank;    
            }
        }
    }
    // Prints
    for (int x = tmp1.value.size() - 1; x >= 0; x--){
        if (x != 0){
            cout << tmp1.name[x] << ", ";
        }else{
            cout << tmp1.name[x] << endl;
        }
    }
    // For Next Iteration
    cin >> numHands;
  }
  return 0;
}
