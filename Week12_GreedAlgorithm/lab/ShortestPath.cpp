#include<iostream>
#include<stdio.h>
using namespace std;
//#define INFINITY 999
#define max 7

class Graph{
private:
   int cost[max][max];
   int found[max];
   int distance[max];
public:
   Graph(int data[max][max]){
      for(int i = 0; i < max; i++){
         for(int j = 0; j < max; j++){
            cost[i][j] = data[i][j];
         }
      }
    }
   void printGraph(){
      cout << "***** Adjacency Matrix *****"<< endl;
      cout << "\t";
      for(int i = 0; i < max; i++){
         cout << i << "\t";
      }
      cout << endl;

      for(int j = 0; j < max; j++){
         cout << j << "\t";
         for(int k = 0; k < max; k++){
            cout << cost[j][k] << "\t";
            }
            cout << endl;
         }
         cout << endl;
      }
   int choose(int distance[],int found[]){
   int minnode;
   int min = 1000; //INFINITY;
   for(int i = 0; i < max; i++){
      if(distance[i] < min && !found[i]){
         min = distance[i];
         minnode = i;
         }
      }
   return minnode;
   }
   void shortestPath(int v){
   int  u;
   for(int i = 0; i < max; i++){
      found[i] = 0;
      distance[i] = cost[v][i];
   }
   found[v] = 1;
   distance[v] = 0;
   print_distance(max,0);
   cout << endl;
   for(int  i = 0; i < max-1 ; i++){
      u = choose(distance,found);
      found[u] = 1;
      print_distance(max,u);
      cout << endl;
      for(int w = 0; w < max; w++){
         if(!found[w]){
            if(distance[u] + cost[u][w] < distance[w]){
               distance[w] = distance[u] + cost[u][w];
            }
         }
      }
   }
}
void print_distance(int n, int s){
	if (s == 0){
      cout << "\nStart from Vertex " << s << " : ";
   }else{
      cout << "\nSelected Node : " << s << " ";
   }cout << "Distance->	";
	for (int i = 0; i < n; i++){
      cout << distance[i] << " ";
   }
   
}


};





int main() {
   
   int cost[7][7] = {
{999, 999, 40, 999, 999, 30, 15},
{999, 999, 17, 19, 10, 999, 999},
{40, 17, 999, 22, 999, 999, 20},
{999, 19, 22, 999, 999, 999, 999},
{999, 10, 999, 15, 999, 14,30},
{30, 999, 999, 999, 14, 999,12},
{15,999,20,999,30,12,999}
};


   Graph g1(cost);

   g1.printGraph();
   cout << "***** Shortest Path *****" << endl;
   g1.shortestPath(0);
   cout << endl;


}





