#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 6
using namespace std;


int minKey(int key[], int visited[]);
void primMST(int weight[MAX][MAX]);
void printMST(int parent[], int graph[MAX][MAX]);

int main(void){
int weight[MAX][MAX] = {
  {100, 6, 1, 5, 100, 100},
  {6, 100, 4, 100, 3, 100},
  {1, 4, 100, 5, 6, 5},
  {5, 100, 5, 100, 100, 2},
  {100, 3, 6, 100, 100, 6},
  {100, 100, 5, 2, 6, 100},
};
primMST(weight);

}

int minKey(int key[], int visited[]){
    int min = INT8_MAX;
    int min_index;
    for(int i = 0; i < MAX; i++){
        //cout << " " <<key[i];
        if(visited[i] == 0 && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    //cout <<endl;
    return min_index;
}

void primMST(int weight[MAX][MAX]){
    int parent[MAX];
    int key[MAX];
    int visited[MAX];
    for(int i = 0; i < MAX; i++){
        key[i] = INT8_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int cnt = 0; cnt < MAX-1; cnt++){
        int u = minKey(key,visited);
        visited[u] = 1;
        for(int v = 0; v < MAX; v++) {
            if(weight[u][v]&&visited[v] == false && weight[u][v] < key[v]){
                parent[v] = u;
                key[v] = weight[u][v];
            }
        }
    }
    printMST(parent,weight);

}




void printMST(int parent[], int weight[MAX][MAX]){

    int minCost = 0;
    char target[MAX] = {'A','B','C','D','E','F'};
    cout << "MST : ";
    for(int i = 1; i < MAX; i++){
        minCost += weight[i][parent[i]];
        cout << "(" << target[parent[i]] << "-" << target[i] << ")";
        if(i != MAX-1){
            cout << "->";
        }
    }
    cout << endl;
    cout << "Weight :" << minCost << endl;
}

