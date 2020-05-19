#include <iostream>
#define N 8
using namespace std;

class MaxHeap{
private:
  int *heap;
  int currentSize;
  const int MaxSize;
public:
  int* getcurrentSize() {return &currentSize;}
  MaxHeap(int sz);
  ~MaxHeap();
  bool isFull(int *currentSize);
  bool isEmpty(int *currentSize);
  void insertHeap(int item, int *currentSize);
  int deleteHeap(int *currentSize);
  void displayHeap(int *currentSize);
  void searchHeap(int item);
};

MaxHeap::MaxHeap(int sz):MaxSize(sz){
  currentSize = 0;
  heap = new int[MaxSize+1];
}

MaxHeap::~MaxHeap(){
  currentSize = 0;
  delete[] heap;
}

bool MaxHeap::isFull(int *currentSize){
  if(*currentSize == MaxSize){
    return true;
  }else{
    return false;
  }
}

bool MaxHeap::isEmpty(int *currentSize){
  if(*currentSize == 0){
    return true;
  }else{
    return false;
  }
}

void MaxHeap::insertHeap(int item, int *currentSize){
  if(isFull(currentSize)){
    cout << "Heap is full" << endl;
  }else{
    int i = ++(*currentSize);
    while((i!=1)&&(item < heap[i/2])){
      heap[i] = heap[i/2];
      i = i/2;
    }
    heap[i] = item;
  }
}


int MaxHeap::deleteHeap(int *currentSize){
  if(isEmpty(currentSize)){
    cout << "Heap is Empty" << endl;
  }else{
    int parent, child;
    int item, temp;
    item = heap[1];
    temp = heap[(*currentSize)--];
    parent = 1;
    child = 2;

    while(child <= *currentSize){
      if((child < *currentSize)&&(heap[child] > heap[child+1])){
        child++;
      }
      if(temp <= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child = child * 2;

    }
    heap[parent] = temp;
    return item;
  }
}

void MaxHeap::displayHeap(int *currentSize){
  if(isEmpty(currentSize)){
    cout << "Heap is Empty!" << endl;
  }else{
    for(int i = 1; i < *currentSize+1; i++){
      cout << heap[i] << " ";
    }
    cout << endl;
  }
}

void MaxHeap::searchHeap(int item){
  int check = 0;
  for(int i = 1; i < MaxSize; i++){
    if(heap[i] == item){
      cout << heap[i] << "is founded" << i << endl;
      check = 1;
    }
  }
  if(check == 0){
    cout << item << "is not founded" << endl;
  }
}

int main(void){
  MaxHeap m1(N);
  int number;
  int deleteNum;
  while(number!=5){
    cout << "Command : (1.insert 2.delete 3.display 4.search 5.quit)  : " << " ";
    cin >> number;
    switch(number){
      case 1:
      int target;
      cout << "Enter number to insert : " << " ";
      cin >> target;
      m1.insertHeap(target,m1.getcurrentSize());
      break;

      case 2:
      deleteNum = m1.deleteHeap(m1.getcurrentSize());
      cout << deleteNum << endl;
      break;

      case 3:
      m1.displayHeap(m1.getcurrentSize());
      break;

      case4:
      int target2;
      cout << "Enter number to search : " << " ";
      cin >> target2;
      m1.searchHeap(target2);
      break;
    }
  }
  m1.~MaxHeap();

}
