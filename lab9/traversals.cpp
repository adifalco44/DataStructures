#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Graph{
    char host;
    vector<char> nei;
};

int update(vector <Graph> &);
bool checkHost(vector <Graph>,char hst);
int findHost(vector <Graph>,char hst);
bool isPath(char,char,vector<Graph>);

int main(){ 
    // Initializations
   int paths;
   int graphcount = 1;
   string tmp;
   vector <Graph> graph;
   graph.clear();
   while (cin >> paths){
        // Parses input
        for (int i = 0; i<paths; i++){
            getline(cin,tmp);
            if (tmp == ""){
                getline(cin,tmp);
            }
            Graph tmp1;
            if (i==0){
                tmp1.host = tmp[0];
                tmp1.nei.push_back(tmp[2]);
                graph.push_back(tmp1);
            }else{
                if(checkHost(graph,tmp[0])==false){
                    tmp1.host = tmp[0];
                    tmp1.nei.push_back(tmp[2]);
                    graph.push_back(tmp1);
                }else{
                    int location = findHost(graph,tmp[0]);
                    graph[location].nei.push_back(tmp[2]);
                }
            }    
        }
        for (int i = 0; i < graph.size(); i++){
            for (int j = 0; j < graph[i].nei.size(); j++){
                if (checkHost(graph,graph[i].nei[j])){
                    int location = findHost(graph,graph[i].nei[j]);
                    for (int k = 0; k < graph[location].nei.size(); k++){ 
                        graph[i].nei.push_back(graph[location].nei[k]);
                    }
                }
            }
        }
        cin >> paths;
        vector <char> check1;
        vector <char> check2;
        for (int i = 0; i < paths; i++){
            getline(cin,tmp);
            if (tmp == ""){
                getline(cin,tmp);
            }
            check1.push_back(tmp[0]);
            check2.push_back(tmp[2]);
        }
        for (int j = 0; j < check1.size(); j++){
            if (isPath(check1[j],check2[j],graph)){
                cout << "In Graph " << graphcount << " there is a path from " << check1[j] << " to " << check2[j] << endl;
            }else{
                cout << "In Graph " << graphcount << " there is no path from " << check1[j] << " to " << check2[j] << endl;
            }
        }
        cout << endl;
        for (int i = 0; i < graph.size(); i++){
            graph[i].nei.clear();
        }
        graph.clear();
        check1.clear();
        check2.clear();
        graphcount++;
  }
  return 0;
}

int update(vector <Graph> &graph){
    cout << "updating .." << endl;
    for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph[i].nei.size(); j++){
//            cout << "updatting .." << endl;
            if (checkHost(graph,graph[i].nei[j])){
//                cout << "updatting .." << endl;
                int location = findHost(graph,graph[i].nei[j]);
                for (int k = 0; k < graph[location].nei.size(); k++){ 
//                    cout << "updatting .." << endl;
                    graph[i].nei.push_back(graph[location].nei[k]);
                }
            }
        }
    }
    return 0;
}




bool checkHost(vector <Graph> graph, char hst){
    bool flag = false;
    for (int i = 0; i < graph.size(); i++){
        if (graph[i].host == hst){
            flag = true;
        }
    }
    return flag;
}

int findHost(vector <Graph> graph,char hst){
    int location;
    for (int i = 0; i < graph.size(); i++){
        if (graph[i].host == hst){
            location = i;
        }
    }
    return location;
}

bool isPath(char a, char b, vector <Graph> graph){
    bool flag = false;
    if (checkHost(graph,a)){
        int location = findHost(graph,a);
        for (int i = 0; i < graph[location].nei.size(); i++){
            if (graph[location].nei[i]==b){
                flag = true;
            }
        }
    }
    return flag;
}


