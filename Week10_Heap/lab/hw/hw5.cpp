/*
1) Main Heading
*********************************************************
* Name:  ������
* Student ID : 20191587
* Program ID : HW5
* Description : HEAP�� Ȱ���Ͽ� �پ��� �Լ��� �׽�Ʈ
* Algorithm : �Լ����� �׽�Ʈ �ϴ� �������� ���� �Լ� ������ �˰��� ������ ���� ����
* Variables:
Ŭ����: MaxHeap
�Լ� :
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
description : int���� currentSize���� int�迭�� heap �׸��� int ����� MaxSize�� ���� class�̴�.

variables : int *heap : heap�迭
            int currentSize : ���� heap�� ũ��
            const int MaxSize : heap�� �ִ� ũ��
function : (�Լ��� ���� ������ ���������� �ڼ���) 
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
description : �������Լ�
variables : currentSize = ���� �迭�� ũ��
            heap = heap�迭 ����
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
description : �Ҹ����Լ�
****************************************************************************/
MaxHeap::~MaxHeap(){
  currentSize = 0;
  delete[] heap;
}

/****************************************************************************
function : void MaxHeap::isFull(int *currentSize)
description : ���� ���� �� �ִ��� Ȯ�����ִ� �Լ��̴�.
algorithm : 1) ���� ���� ũ�Ⱑ ���� ��ü ũ��� ���ٸ� "Heap is Full"�� ����Ѵ�
            2) �ƴ϶�� "Heap is not full"�� ����Ѵ�
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
description : ���� ��� �ִ��� Ȯ�����ִ� �Լ��̴�.
algorithm : 1) ���� ���� ũ�Ⱑ 0�̸� "Heap is Empty"�� ����Ѵ�
            2) �ƴ϶�� "Heap is not Empty"�� ����Ѵ�
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
description : ���� ���Ҹ��߰��ϴ� �Լ��̴�. 
algorithm : 1) ���� ���� ������ �ִٸ� "Heap is full"�� ������ش�
            2) �ƴ϶�� ���� ���� ũ�⸦ �÷��ش�.
            3) ����ũ�Ⱑ 1�� �ƴϰ�  item�� heap[i/2](child)������ ũ��
            4) heap[i]���� heap[i/2]�� ����
            5) i = i/2�� ���ش�
            6) while���� ������ ������ ��ġ�� ���Ҹ� �������ش�
            7) �ٲ� ���� ������ش�
variables : int item = �������� ����
            int *currentSize = ���� ���� ���� ����
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
description : ���� ���� ū ���� ���Ҹ� �����ϴ� �Լ��̴�.
algorithm : 1) ���� ���� ��������� "Heap is Empty"�� ������ش�
            2) �ƴ϶�� ù°�� currentSize�� ���� �ٿ��� ���� ���� ������ ������ �ٿ��ش�
            3) �׸��� parent�� child���� ���ؼ� temp�� ��ġ�� ã������ while���� ������
            4) ������ ���� ���� ������ش�
variables : int parent : �ӽ����� �θ� ���
            int child : �ӽ����� �ڳ� ���
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
description : ���� ��� �Լ��̴�.
algorithm : 1) ���� list�� ��������� "Heap is Empty"�� ������ش�.
            2) �ƴ϶�� �ε��� 0���� ������̱��� ������ش�
variables : int *currentSize = ���� ���� ���� ����
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
description : ã�����ϴ� ���Ұ� �� �ȿ� �ִ��� Ȯ���ϴ� �Լ��̴�.
algorithm : 1) �ε��� 0���� ��ü���̱��� �Է��� ���Ұ� �ִ��� Ȯ���Ѵ�
            2) ã���� check�� ���� 1�� �ٲ��ְ� �� �ȿ� ������ ��Ÿ���� �޼����� ������ش�.
            3) ���� �ݺ����� �� ������ check�� ���� 0�̶�� �� �ȿ� ������ ��Ÿ���� �޼����� ������ش�.
variables : int item = ã���� �ϴ� ����
            int check = �� �ȿ� ������ �������ִ� ����
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
description : ���� ������ ��Ÿ���� �Լ�
algorithm : 1) check�� ���� currentSize���� ������ 2�� �����ְ� result���� 1������Ų��
            2) ���� check���� curresnSize���� Ŀ���� while���� �����ϰ� result�� ������ش�.
variables : int check = ������ üũ���ִ� �Ű�����
            int result = ����
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
description : ���ĵ��� �ʴ� data�� ���� ���·� �������ִ� �Լ��̴�.
algorithm : 1)������ ���ص� ������ش�(�ڼ��� �˰����� adjust���� �����ϰڴ�)
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
description : heapify�� ���ִ� �Լ��̴�
algorithm : 1) ���� ó�� ���ݿ� �� ������ ������ �ڸ��� �ٲ��ش�
            2) ���� heap�� ���ĸ� ���ش�
            3) ������ش�
            4) ��� heapify�� ������ �������� ������ش�.
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
description : heap�� �������ִ� �Լ��̴�
algorithm : 1) child�� ���� ��� ���� ���� �۴ٸ� while���� �����ش�
            2) �ڳ� ��� �߿��� �� ū�Ÿ� �����Ѵ�
            3) temp���� ���ؼ� temp�� �� ũ�ٸ� break�Ѵ�
            4) �ƴ϶�� temp���� child�� �������� ������ ������ش�
variables : int child = �ڳ���
            int temp = ���� ��
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
