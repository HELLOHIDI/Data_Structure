// Prim's Algorithm in C++

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999
#define V 6


void printgraph(int G[][V]){
    string target[V] = {"V1","V2","V3","V4","V5","V6"};
    cout << "****   Weighted Graph  ****" << endl;
    for(int i = 0; i < V; i++){
        cout << target[i] << " ";
        for(int j = 0; j < V; j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int G[V][V] = {
  {100, 6, 1, 5, 100, 100},
  {6, 100, 4, 100, 3, 100},
  {1, 4, 100, 5, 6, 5},
  {5, 100, 5, 100, 100, 2},
  {100, 3, 6, 100, 100, 6},
  {100, 100, 5, 2, 6, 100},
};
int main() {
  string target[V] = {"V1","V2","V3","V4","V5","V6"};
  int total = 0;
  int no_edge;  
  int selected[V];
  printgraph(G);
  memset(selected, false, sizeof(selected));
  no_edge = 0;

 

  selected[0] = true;

  int x;
  int y;  


  cout << "**** Minimal Spanning Tree test1 ****" << endl;
  while (no_edge < V - 1) {
    

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << target[x] << " - " << target[y];
    total +=  G[x][y];
    cout << endl;
    selected[y] = true;
    no_edge++;
    
  }
  cout << "Total = " << total;

  return 0;
}