
#include <iostream>

using namespace std;

#define size 8
#define size2 6

class Queue{
private:
  int queue[size];
  int front;
  int rear;
public:
  Queue(){front = -1; rear = -1;}
  int isEmpty();
  void AddQ(int data);
  int DeleteQ();
  void dfs();
};

void Queue::AddQ(int data){
 rear++;
 queue[rear] = data;
}
int Queue::isEmpty(){
 if (rear == front)
  return 1;
 return 0;
}
int Queue::DeleteQ(){
 if (isEmpty())
  return -1;
 else
 {
  front++;
  return queue[front];
 }
}
void printMatrix(int arr[][size],int sz){
  string v[size] ={ "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7"};
  cout << "********   " << "Adjacent Matrix" << "   ********" << endl;
  cout << "   " ;
  for(int i = 0; i < size; i++){
    cout << v[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < size; i++){
    cout << v[i] << " ";
    for(int j = 0; j < size; j++){
      cout << " " << arr[i][j] << " ";
    }
    cout << endl;
  }
}
void bfs(int d,Queue q,int visited[],int arr[][size],int sz){
 q.AddQ(d);
 cout << "Breadth First Search    " << "->";
 if (visited[d] == 0){
  cout << d << " ";
  visited[d] = 1;
 }
 while(!q.isEmpty()){
  int t = q.DeleteQ();
  for (int i = 0; i < size; i++){
   if (arr[t][i] == 1 && visited[i] == 0){
    q.AddQ(i);
    cout << i << " ";
    visited[i] = 1;
   }
  }
 }
 cout << endl;
}
void printMatrix(int arr[][size2],int sz){
  string v[sz] ={ "v0", "v1", "v2", "v3", "v4", "v5"};
  cout << "********   " << "Adjacent Matrix" << "   ********" << endl;
  cout << "   " ;
  for(int i = 0; i < sz; i++){
    cout << v[i] << " ";
  }
  cout << endl;
  for(int i = 0; i < sz; i++){
    cout << v[i] << " ";
    for(int j = 0; j < sz; j++){
      cout << " " << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void bfs(int d,Queue q,int visited[],int arr[][size2],int sz){
 q.AddQ(d);
 cout << "Breadth First Search    " << "->";
 if (visited[d] == 0){
  cout << d << " ";
  visited[d] = 1;
 }
 while(!q.isEmpty()){
  int t = q.DeleteQ();
  for (int i = 0; i < sz; i++){
   if (arr[t][i] == 1 && visited[i] == 0){
    q.AddQ(i);
    cout << i << " ";
    visited[i] = 1;
   }
  }
 }
 cout << endl;
}




//메인함수

int main(void)
{
  int arr[size][size] = {
   0,1,1,0,0,0,0,0,
   1,0,0,1,1,0,0,0,
   1,0,0,0,0,1,1,0,
   0,1,0,0,0,0,0,1,
   0,1,0,0,0,0,0,1,
   0,0,1,0,0,0,0,1,
   0,0,1,0,0,0,0,1,
   0,0,0,1,1,1,1,0
};

  int arr2[size2][size2] = {
    0,1,1,0,0,0,
    1,0,1,1,0,0,
    1,1,0,0,0,1,
    0,1,0,0,1,1,
    0,0,0,1,0,1,
    0,0,1,1,1,0
  };


 Queue q1,q2;
 int visited[size] = {0};
 int visited2[size2] = {0};
 printMatrix(arr,size);
 bfs(0,q1,visited,arr,size);
 cout << endl;
 printMatrix(arr2,size2);
 bfs(0,q2,visited2,arr2,size2);

 return 0;
}
