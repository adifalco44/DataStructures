#include <iomanip>
#include <iostream>
#include <vector>
#ifndef SSOLVER_CPP
#define SSOLVER_CPP
using namespace std;


class Board {
  protected:
    struct Cell{
      int value;
      vector <int> possVals;
    };



  public:

    Board(){
       for (int i = 0; i < 9; i++){
          for (int j = 0; j < 9; j++){
             array[i][j].value = 0;
             array[i][j].possVals.push_back(0);
          }          
       }
    }
                             
    ~Board(){}                              

    void setValue(int x, int y, int v){
       array[x][y].value = v;
    }
 
    int getValue(int x, int y){
       return array[x][y].value;
    }
  


    // Calls functions to set possVals
    void findPoss(){
       for (int i = 0; i < 9; i++){
          for (int j = 0; j < 9; j++){
              array[i][j].possVals.clear();
              if (array[i][j].value == 0){
                 vector <int> np = checkNei(i,j);         // Returns numbers that dont exist within neighborhood
                 vector <int> hp = checkHoriz(i,j);       // Returns ^^ within horixontal
                 vector <int> vp = checkVert(i,j);        // Returns ^^ within vertical
                 vector <int> ps = fixPoss(np,hp,vp);     // Returns numbers that occur in all three vectors
                 array[i][j].possVals = ps;               // Sets possVals to this vector
              }
          }
       }
    }
    // Checks row
    vector <int> checkHoriz(int i, int j){
       int tmp1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};   //If matched to existing number, set to zero
       vector <int> tmp2;                            //Same logic used in every check function
       for (int x = 0; x < 9; x++){
           if (0 != array[x][j].value){
                tmp1[array[x][j].value - 1] = 0;        
           }
       }
       for (int h = 0; h < 9; h++){                  //If non-zero, can exist
          if (tmp1[h] != 0){
             tmp2.push_back(tmp1[h]);
          }
       }  
       return tmp2;
    }

    // Checks Column
    vector <int> checkVert(int i, int j){
       int tmp1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       for (int y = 0; y < 9; y++){
           if (0 != array[i][y].value){
                tmp1[array[i][y].value - 1] = 0;
           }
       }
       vector <int> tmp2;
       for (int h = 0; h < 9; h++){
          if (tmp1[h] != 0){
             tmp2.push_back(tmp1[h]);
          }
       }
       return tmp2;
    }    

    // Checks Sub-Box
    vector <int> checkNei(int i, int j){
        int tmp [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int x,y;
	int subN = 3;	                                //number of columns/rows in mini squares on board
	int colAdjust = i - i%subN;
	int rowAdjust = j - j%subN;
	for (x=colAdjust; x < colAdjust+subN; x++){	//search through the adjusted square (subsquare)
		for(y = rowAdjust; y < rowAdjust+subN; y++){
			if(0 != array[x][y].value && (y!=j || x!=i)){
		              tmp[array[x][y].value-1] = 0;
                        }
		}
	}
        vector <int> tmp2;
        for (int e = 0; e < 9; e++){
           if (tmp[e] != 0){
              tmp2.push_back(tmp[e]);
           }
        }
        return tmp2;
     }

    // Apends possible combinations
    vector <int> fixPoss(vector <int> a, vector <int> b, vector <int> c){

       // If a number exists within vector, count1/2/3 is set to one
       int hash1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int count1 [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

       int hash2 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int count2 [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

       int hash3 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int count3 [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

       for (auto it1 = a.begin(); it1 != a.end(); it1++){
          if (*it1 == hash1[*it1-1] && count1[*it1-1] == 0){
             count1[*it1-1]++;
          }
       }

       for (auto it2 = c.begin(); it2 != c.end(); it2++){
          if (*it2 == hash2[*it2-1] && count2[*it2-1] == 0){
             count2[*it2-1]++;
          }
       }

       for (auto it3 = b.begin(); it3 != b.end(); it3++){
          if (*it3 == hash3[*it3-1] && count3[*it3-1] == 0){
             count3[*it3-1]++;
          }
       }

       //If count1/2/3 all have 1 in their count vector, pushback number
       vector <int> tmp;
       for (int f = 0; f < 9; f++){
          if (count1[f] == 1 &&  count2[f] == 1 && count3[f] == 1 ){
              tmp.push_back(f+1);
          }
       }
       return tmp;
    }

    //Solves using two solver calls
    void solve(){       
       // Attempts single elimination for every number
       for (int i = 0; i < 9; i++){
           for (int j = 0; j < 9; j++){
               if (array[i][j].value == 0 && array[i][j].value == 0){
                  single(i,j);
               }
           }
       }
       // Attempts singleton for every number
       for (int i = 0; i < 9; i++){
           for (int j = 0; j < 9; j++){
               if (array[i][j].value == 0){
                  singlton(i,j);
               }
           }
       }
    }

    // Adds element if only one possibility
    void single(int i, int j){
       // If only one option, set
       if (array[i][j].possVals.size() == 1){
            array[i][j].value = array[i][j].possVals[0];
            findPoss();
       }  
    }


    // Considers cells with multiple possibilities
    void singlton(int i,int j){
       bool boolean = false;
       // Pushes possible values of neighbors into vectors
       vector <int> nposs = nPossVals(i,j);
       vector <int> hposs = hPossVals(i,j);
       vector <int> vposs = vPossVals(i,j);
       vector <int> pposs;  // reference vector
       if (array[i][j].value == 0){
            for (auto it1 = array[i][j].possVals.begin(); it1 != array[i][j].possVals.end(); it1++){
                  boolean = false;
                  // Checks Row
                  for (auto it2 = hposs.begin(); it2 != hposs.end(); it2++){
                     if (*it1 == *it2){
                        boolean = true;
                        break;
                     }
                  }
                  if (boolean == false ){
                     pposs.push_back(*it1);
                  }
             }
             // If the value doesn't occur, and can be placed, and this is the only value in reference, set value
             if (pposs.size() == 1 && checkN(i,j,pposs[0]) && checkV(i,j,pposs[0]) && checkH(i,j,pposs[0]) ){
                 array[i][j].value = pposs[0];
                 findPoss();
             }
             for (auto it1 = array[i][j].possVals.begin(); it1 != array[i][j].possVals.end(); it1++){   
                  boolean = false;
                  // Checks Vertical
                  for (auto it3 = vposs.begin(); it3 != vposs.end(); it3++){
                     if (*it1 == *it3){
                        boolean = true;
                        break;
                     }
                  }

                  if (boolean == false ){
                     pposs.push_back(*it1);
                  }
             }
             if (pposs.size() == 1 && checkN(i,j,pposs[0]) && checkV(i,j,pposs[0]) && checkH(i,j,pposs[0]) ){
                 array[i][j].value = pposs[0];
                 findPoss();
             }


             for (auto it1 = array[i][j].possVals.begin(); it1 != array[i][j].possVals.end(); it1++){
                  boolean = false;
                  // Checks neighbors
 	          for (auto it4 = nposs.begin(); it4 != nposs.begin(); it4++){
		      if (*it1 == *it4){
		           boolean = true;
                           break;
		      }		                  
                  }
	          if (boolean == false){
		       pposs.push_back(*it1);                                          
		  }
              }
              if (pposs.size() == 1 && checkN(i,j,pposs[0]) && checkV(i,j,pposs[0]) && checkH(i,j,pposs[0]) ){
                 array[i][j].value = pposs[0];
                 findPoss();
              }
       }                 
    }    

    // Checks Horizontal
    vector <int> vPossVals(int i, int j){
       int tmp1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int tmp2 [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
       vector <int> tmp3;
       for (int y = 0; y < 9; y++){
             if (y != j && array[i][y].value == 0){
                 for (auto it = array[i][y].possVals.begin(); it != array[i][y].possVals.end(); it++){
                      // If the possVal occurs and it hasnt been added alread, then push back
                      if (*it == tmp1[*it - 1] && tmp2[*it - 1] == 0 && array[i][y].value == 0){
                         tmp2[*it - 1]++;
                         tmp3.push_back(*it);
                      }
                 }
             }
       }
       return tmp3;
    }

    // Checks Vertical
    vector <int> hPossVals(int i, int j){
       int tmp1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int tmp2 [9] =  {0, 0, 0, 0, 0, 0, 0, 0, 0};
       vector <int> tmp3;
       for (int x = 0; x < 9; x++){
             if (x != i && array[x][j].value == 0){
                 for (auto it = array[x][j].possVals.begin(); it != array[x][j].possVals.end(); it++){
                      // If the possVal occurs and it hasnt been added alread, then push back
                      if (*it == tmp1[*it - 1] && tmp2[*it - 1] == 0 && array[x][j].value == 0){
                         tmp2[*it - 1]++;
                         tmp3.push_back(*it);
                      }
                 }
             }     
       }
       return tmp3;
    }
 
    // Checks Sub-Box
    vector <int> nPossVals(int i, int j){
       int tmp1 [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
       int tmp2 [9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
       vector <int> tmp3;
       int x,y;
       int subN =3;	
       int colAdjust = i - i%subN; // sets bounds
       int rowAdjust = j - j%subN; // ^^
       for (x=colAdjust; x < colAdjust+subN; x++){	
           for(y = rowAdjust; y < rowAdjust+subN; y++){
	      if (0 == array[x][y].value && (x!=i || y != j)){
                 for (auto it = array[x][j].possVals.begin(); it != array[x][j].possVals.end(); it++){
                     // If the possVal occurs and it hasnt been added alread, then push back
                     if (*it == tmp1[*it - 1] && tmp2[*it - 1] == 0 && array[x][y].value ==0){
                           tmp2[*it - 1]++;
                           tmp3.push_back(*it);
                     }
                 }
              }

	   }
      }
      return tmp3;
    }

    // Checks Vertical PLacement
    bool checkV(int i, int j, int k){
       bool flag = true;
       for (int y = 0; y < 9; y++){
           if ((y != j && array[i][y].value == k) || (array[i][y].possVals.size() == 1 && array[i][y].possVals[0] == k)){
                flag = false;
           }
       }
       return flag;
    }

    // Checks Horizontal Placement
    bool checkH(int i, int j, int k){
       bool flag = true;
       for (int x = 0; x < 9; x++){
             if ((x != i && array[x][j].value == k) || (array[x][j].possVals.size() == 1 && array[x][j].possVals[0] == k)){
                   flag = false;
             }
       }
       return flag;
    }
 
    // Checks Sub-Box Placement
    bool checkN(int i, int j, int k){
       bool flag = true;
       int x,y;
       int subN =3;	
       int colAdjust = j - j%subN;
       int rowAdjust = i - i%subN;
       for (x=rowAdjust; x < rowAdjust+subN; x++){	
           for(y = colAdjust; y < colAdjust+subN; y++){
	      if ((k == array[x][y].value && (x!=j || y != i))  || (array[x][y].possVals.size() == 1 && array[x][y].possVals[0] == k)){
                   flag = false;
              }
	   }
      }
      return flag;
    }

    // Makes sure no cel value is zero
    bool isSolved(){
        bool count = false;
        for (int i = 0; i < 9; i++){
           for (int j = 0; j < 9; j++){
              if (array[i][j].value == 0){
                 count = true;               
              }
           }
        }
        return count;
    }

    // Prints Board
    void print(){
       for (int i = 0; i < 9; i++){
          for (int j = 0; j < 9; j++){
             cout << array[i][j].value << "(" << i << j << ")  ";
          }
          cout << endl;
       }
    }

  private:
    Cell array[9][9];     
};  




#endif
