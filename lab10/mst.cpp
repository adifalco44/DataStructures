#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct nei{
   char neighbor;
   int distance;
};


struct Graph{
    char host;
    vector <nei> neighbors;
};

char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int main(){ 
    // Initializations
   int paths;
   int graphcount = 1;
   string tmp;
   vector <Graph> graph;
   string line;
   while (cin >> paths){
        // Parses input
        int count1 = 0;
	int count2 = 0;
	int graph[paths][paths];

	// Reads in to graph
	for (int i = 0; i < paths; i++){
	    getline(cin,line);
	    cout << line << endl;
	    stringstream iss;
	    iss << line;
	    while(iss){
		   cout << tmp;
		   cout << endl;
	    }
	}

	// Checks Paths	
	bool flag = false;
	vector <char> nodes_hit;
	while (!flag){
	    // Finds smallest edge
	    int min = graph[0][0];
	    for (int i = 0; i < paths; i++){
		for (int j = 0; j < paths; j++){
		     if (graph[i][j] < min){
			  // Makes sure

			  min = graph[i][j];
		     }
		}
	    }	    


	    // If every node has been hit
	    if (nodes_hit.size() == paths){
		flag = true;
	    }
	}

  }
  return 0;
}




/*
        for (int i = 0; i<paths; i++){
	    nei tmpnei;
	    int tmp;
	    int count2 = 0;
	    Graph tmpgraph;
            tmpgraph.host = alphabet[count1];
	    getline(cin,line);
	    cout << line << endl;
	    stringstream iss;
	    iss << line;
	    while(iss){
		cout << tmp;
		cout << endl;
		if (tmp[i] != ' '){
		    
		    if (stoi(tmp[i]) != -1){
			tmpnei.distance = stoi(tmp[i]);
			cout << tmpnei.distance;
			tmpnei.neighbor = alphabet[count2];
			tmpgraph.neighbors.push_back(tmpnei);
		    }
		    count2++;			
		}
	    }
	    graph.push_back(tmpgraph);
	    count1++;
	} 
*/
