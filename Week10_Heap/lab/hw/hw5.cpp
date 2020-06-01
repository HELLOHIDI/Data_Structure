/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW5
* Description : HEAP을 활용하여 다양한 함수를 테스트
* Algorithm : 함수들을 테스트 하는 것임으로 각각 함수 설명에서 알고리즘 개별적 설명 진행
* Variables:
클래스: MaxHeap
함수 :
  int* getcurrentSize() {return &currentSize;}
  int* getHeap() {return heap;}
  void setcurrentSize(int length) {currentSize = length;}
  MaxHeap(int sz,int* data, int length);
  ~MaxHeap();
  void isFull(int *currentSize);
  void isEmpty(int *currentSize);
  void insertHeap(int item, int *currentSize);
  int deleteHeap(int *currentSize);
  void displayHeap(int *currentSize);
  void searchHeap(int item);
  void leveltest(int *currentSize);
  void MakeHeap(int* heap, int* currentSize);
  void HeapSort(int* heap, int* currentSize);
  void adjust(int* heap, int i, int length);
*************************************************************************/
#include <iostream>
#include <algorithm>
#define N 11
using namespace std;

/****************************************************************************
class : MaxHeap
description : int형의 currentSize값과 int배열인 heap 그리고 int 상수인 MaxSize를 묶은 class이다.

variables : int *heap : heap배열
            int currentSize : 현재 heap의 크기
            const int MaxSize : heap의 최대 크기
function : (함수에 대한 설명은 개별적으로 자세히) 
  int* getcurrentSize() {return &currentSize;}
  int* getHeap() {return heap;}
  void setcurrentSize(int length) {currentSize = length;}
  MaxHeap(int sz,int* data, int length);
  ~MaxHeap();
  void isFull(int *currentSize);
  void isEmpty(int *currentSize);
  void insertHeap(int item, int *currentSize);
  int deleteHeap(int *currentSize);
  void displayHeap(int *currentSize);
  void searchHeap(int item);
  void leveltest(int *currentSize);
  void MakeHeap(int* heap, int* currentSize);
  void HeapSort(int* heap, int* currentSize);
  void adjust(int* heap, int i, int length);

****************************************************************************/
class MaxHeap{
private:
  int *heap;
  int currentSize;
  const int MaxSize;
public:
  int* getcurrentSize() {return &currentSize;}
  int* getHeap() {return heap;}
  void setcurrentSize(int length) {currentSize = length;}
  MaxHeap(int sz,int* data, int length);
  ~MaxHeap();
  void isFull(int *currentSize);
  void isEmpty(int *currentSize);
  void insertHeap(int item, int *currentSize);
  int deleteHeap(int *currentSize);
  void displayHeap(int *currentSize);
  void searchHeap(int item);
  void leveltest(int *currentSize);
  void MakeHeap(int* heap, int* currentSize);
  void HeapSort(int* heap, int* currentSize);
  void adjust(int* heap, int i, int length);
};


/****************************************************************************
function : MaxHeap::MaxHeap(int sz,int* data, int length):MaxSize(sz)
description : 생성자함수
variables : currentSize = 현재 배열의 크기
            heap = heap배열 생성
****************************************************************************/
MaxHeap::MaxHeap(int sz,int* data, int length):MaxSize(sz){
  currentSize = length;
  heap = new int[MaxSize+1];
  for(int i = 0; i < length; i++){
    heap[i+1] = data[i];
  }
}

/****************************************************************************
function : ~MaxHeap()
description : 소멸자함수
****************************************************************************/
MaxHeap::~MaxHeap(){
  currentSize = 0;
  delete[] heap;
}

/****************************************************************************
function : void MaxHeap::isFull(int *currentSize)
description : 힙이 가득 차 있는지 확인해주는 함수이다.
algorithm : 1) 만약 현재 크기가 힙의 전체 크기와 같다면 "Heap is Full"을 출력한다
            2) 아니라면 "Heap is not full"을 출력한다
****************************************************************************/
void MaxHeap::isFull(int *currentSize){
  if(*currentSize == MaxSize){
    cout << "Heap is Full" << endl;
  }else{
    cout << "Heap is not Full" << endl;
  }
}

/****************************************************************************
function : void MaxHeap::isEmpty(int *currentSize)
description : 힙이 비어 있는지 확인해주는 함수이다.
algorithm : 1) 만약 현재 크기가 0이면 "Heap is Empty"을 출력한다
            2) 아니라면 "Heap is not Empty"을 출력한다
****************************************************************************/
void MaxHeap::isEmpty(int *currentSize){
  if(*currentSize == 0){
    cout << "Heap is Empty" << endl;
  }else{
    cout << "Heap is not Empty" << endl;
  }
}

/****************************************************************************
function : void List::insertHeap(int item, int *currentSize)
description : 힙에 원소를추가하는 함수이다. 
algorithm : 1) 만약 힙이 가득차 있다면 "Heap is full"을 출력해준다
            2) 아니라면 힙의 현재 크기를 늘려준다.
            3) 현재크기가 1이 아니고  item이 heap[i/2](child)값보다 크면
            4) heap[i]값을 heap[i/2]로 값을
            5) i = i/2로 해준다
            6) while문이 끝나면 정해준 위치에 원소를 지정해준다
            7) 바뀐 힙을 출력해준다
variables : int item = 삽입해줄 원소
            int *currentSize = 현재 힙의 원소 개수
****************************************************************************/
void MaxHeap::insertHeap(int item, int *currentSize){
  if(*currentSize == MaxSize){
    cout << "Heap is full" << endl;
  }else{
    int i = ++(*currentSize);
    while((i!=1)&&(item > heap[i/2])){
      heap[i] = heap[i/2];
      i = i/2;
    }
    heap[i] = item;
    displayHeap(currentSize);
  }
}

/****************************************************************************
function : int MaxHeap::deleteHeap(int *currentSize)
description : 힙에 가장 큰 값의 원소를 삭제하는 함수이다.
algorithm : 1) 만약 힙이 비어있으면 "Heap is Empty"를 출력해준다
            2) 아니라면 첫째로 currentSize의 값을 줄여서 현재 힙의 원소의 개수를 줄여준다
            3) 그리고 parent와 child값을 통해서 temp의 위치를 찾기위해 while문을 돌린다
            4) 삭제된 후의 힙을 출력해준다
variables : int parent : 임시적인 부모 노드
            int child : 임시적인 자녀 노드
****************************************************************************/
int MaxHeap::deleteHeap(int *currentSize){
  if(*currentSize == 0){
    cout << "Heap is Empty" << endl;
  }else{
    int parent, child;
    int item, temp;
    item = heap[1];
    temp = heap[(*currentSize)--];
    parent = 1;
    child = 2;

    while(child <= *currentSize){
      if((child < *currentSize)&&(heap[child] < heap[child+1])){
        child++;
      }
      if(temp >= heap[child]) break;
        heap[parent] = heap[child];
        parent = child;
        child = child * 2;

    }
    heap[parent] = temp;
    displayHeap(currentSize);
    return item;
  }
}

/****************************************************************************
function : void MaxHeap::displayHeap(int *currentSize)
description : 힙을 출력 함수이다.
algorithm : 1) 만약 list가 비어있으면 "Heap is Empty"를 출력해준다.
            2) 아니라면 인덱스 0부터 현재길이까지 출력해준다
variables : int *currentSize = 현재 힙의 원소 개수
****************************************************************************/
void MaxHeap::displayHeap(int *currentSize){
  if(*currentSize == 0){
    cout << "Heap is Empty!" << endl;
  }else{
    cout << "Heap : " << " ";
    for(int i = 1; i < *currentSize+1; i++){
      cout << heap[i] << " ";
    }
    cout << endl;
  }
}

/****************************************************************************
function : void MaxHeap::searchHeap(int item)
description : 찾고자하는 원소가 힙 안에 있는지 확인하는 함수이다.
algorithm : 1) 인덱스 0부터 전체길이까지 입력한 원소가 있는지 확인한다
            2) 찾으면 check의 값을 1로 바꿔주고 힙 안에 있음을 나타내는 메세지를 출력해준다.
            3) 만약 반복문을 다 돌려도 check의 값이 0이라면 힙 안에 없음을 나타내는 메세지를 출력해준다.
variables : int item = 찾고자 하는 원소
            int check = 힙 안에 있음을 구분해주는 변수
****************************************************************************/
void MaxHeap::searchHeap(int item){
  int check = 0;
  for(int i = 1; i < MaxSize; i++){
    if(heap[i] == item){
      cout << heap[i] << " " << "is founded" << endl;
      check = 1;
      break;
    }
  }
  if(check == 0){
    cout << item << " " << "is not founded" << endl;
  }
}

/****************************************************************************
function : void MaxHeap::leveltest(int *currentSize)
description : 힙의 레벨을 나타내는 함수
algorithm : 1) check의 값의 currentSize보다 작으면 2를 곱해주고 result값을 1증가시킨다
            2) 만약 check값이 curresnSize보다 커지면 while문을 종료하고 result를 출력해준다.
variables : int check = 레벨을 체크해주는 매개변수
            int result = 레벨
****************************************************************************/
void MaxHeap::leveltest(int *currentSize){
  int check = 1;
  int result = 0;
  while(check <= *currentSize){
    check = check*2;
    result += 1;
  }
  cout << "Level of Heap is " << result << endl;
}

/****************************************************************************
function : void MaxHeap::MakeHeap(int* heap, int* currentSize)
description : 정렬되지 않는 data를 힙의 형태로 정렬해주는 함수이다.
algorithm : 1)정렬을 해준뒤 출력해준다(자세한 알고리즘은 adjust에서 설명하겠다)
****************************************************************************/
void MaxHeap::MakeHeap(int* heap, int* currentSize){
  for(int i = *currentSize/2; i>0; i--){
    adjust(heap,i,*currentSize);
  }
  cout << "Heap changing: " << " ";
  displayHeap(currentSize);
}

/****************************************************************************
function : void MaxHeap::HeapSort(int* heap, int* currentSize)
description : heapify를 해주는 함수이다
algorithm : 1) 가장 처음 원솨와 맨 마지막 원소의 자리를 바꿔준다
            2) 남은 heap로 정렬를 해준다
            3) 출력해준다
            4) 모든 heapify가 끝난뒤 최종값을 출력해준다.
****************************************************************************/
void MaxHeap::HeapSort(int* heap ,int* currentSize){
  for(int i = *currentSize -1; i > 0; i--){
    swap(heap[1],heap[i+1]);
    adjust(heap,1,i);
    displayHeap(currentSize);
  }
  cout << "Sort result  : ";
  displayHeap(currentSize);
  cout << endl;
}

/****************************************************************************
function : void MaxHeap::adjust(int* heap, int i, int length)
description : heap을 정렬해주는 함수이다
algorithm : 1) child의 값이 노드 개수 보다 작다면 while문을 돌려준다
            2) 자녀 노드 중에서 더 큰거를 선별한다
            3) temp값과 비교해서 temp가 더 크다면 break한다
            4) 아니라면 temp값이 child로 내려가는 과정을 만들어준다
variables : int child = 자녀노드
            int temp = 비교할 값
****************************************************************************/
void MaxHeap::adjust(int* heap, int i, int length){
  int child, j;
  child = 2*i;
  int temp = heap[i];
  while(length >= child){
    if(length >= child && heap[child] < heap[child+1])
      child = child +1;
    if(temp >= heap[child]) break;
    j = child/2;
    heap[j] = heap[child];
    child = 2*child;
  }
  j = child/2;
  heap[j] = temp;
  return;
}



int main(void){
  int data[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
  int length = sizeof(data)/sizeof(int);
  MaxHeap m1(N,data,length);
  int number;
  int deleteNum;
  while(number!=8){
    cout << "Command : (1.insert 2.delete 3.search 4.print 5.leveltest 6.HeapSort 7.MakeHeap 8.quit)  : " << " ";
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
      break;

      case 3:
      int target2;
      cout << "Enter number to search : " << " ";
      cin >> target2;
      m1.searchHeap(target2);
      break;

      case 4:
      m1.displayHeap(m1.getcurrentSize());
      break;

      case 5:
      m1.leveltest(m1.getcurrentSize());
      break;

      case 6:
      m1.HeapSort(m1.getHeap(),m1.getcurrentSize());
      break;

      case 7:
      m1.MakeHeap(m1.getHeap(),m1.getcurrentSize());
      break;

    }
  }
  m1.~MaxHeap();

}
