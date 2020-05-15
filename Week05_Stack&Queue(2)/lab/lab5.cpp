#include <iostream>
using namespace std;


const int StackSize = 2;
const int QueueSize = 3;
const int CQueueSize = 10;
class Stack{
private:
  char stack[StackSize]; //stack
  int top; //top
public:
  Stack() {top = -1;}
  void push(int val){
    if(isFull()){
      cout << "Stack is full" << endl;

    }else{
      stack[++top] = val;
      }
  }
  int pop(){
    if(isEmpty()){
      cout << "Stack is Empty" << endl;
    }else{
        cout << stack[top] << " ";
        return stack[top--];
    }

  }
  bool isEmpty(){
    if(top == -1){
        return true;
    }else{
    return false;
  }
}
  bool isFull(){
    if(top == StackSize -1){
        return true;
    }else{
        return false;
    }
}
  void displayStack();
};

void Stack::displayStack(){
  int sp; sp = top;
  cout << "Stack: ";
  while(sp != -1){  cout << stack[sp--] << " ";  }
};


class CQueue{
private:
  int flag;
  int rear = 0;
  int front = 0;
  char cqueue[QueueSize];

public:
  CQueue(){
    rear = 0; front = 0;
  }
  bool isFull(){
    if((rear+1)%CQueueSize == front){
      return true;
    }else{
      return false;
    }

  }
  bool isEmpty(){
    if(front ==  rear){
      return true;
    }else{
      return false;
    }

  }
  void enQueue(char item){
    if(isFull()&& flag == 1){
      cout << "CQueue is FUll" << endl;
      exit(1);
    }else{
      rear = (rear + 1) % CQueueSize;
      cqueue[rear] = item;
      flag = 1;
    }
  }
  int deQueue(){
    if(isEmpty()){
      cout << "CQueue is Empty" <<  endl;
      exit(1);
    }else{
      front = (front+1)%CQueueSize;
      flag = 0;
      return  cqueue[front];
    }
  }

  void print_cqueue(){
    if(isEmpty()){
      cout << "CQueue is Empty ";
    }else{
      cout << "CQueue: ";
      int i = front + 1;
      while(i <= rear){
        cout << cqueue[i] << " ";
        i = i + 1;
      }
    }
  }
};


class Queue{
private:
  int front; int rear;
  char queue[QueueSize];

public:
  Queue(){
    front = -1;
    rear = -1;
  }

void enQueue(int value){
  if(isFull()){
    cout << "Queue is full" << endl;
  }else{
    queue[++rear] = value;
  }

}

int deQueue(){
  if(isEmpty()){
    cout << "Queue is empty" << endl;
  }else{
    cout << queue[++front] << " ";

  }
}

bool isFull(){
  if(rear == QueueSize-1){
    return true;
  }else{
      return false;
  }
}
bool isEmpty(){
  if(front == rear){
    return true;
  }else{
    return false;
  }

}


void print_queue(){
  if(isEmpty()){
    cout << "Queue is Empty ";
  }else{
    cout << "Queue: ";
    int i = front + 1;
    while(i <= rear){
      cout << queue[i] << " ";
      i = i + 1;
    }
  }
}
};


int main(void){
  Stack s1;
  Queue q1;
  CQueue c1;
//1)
  s1.push('a');
  q1.enQueue('b');
  q1.enQueue('c');
  q1.enQueue('d');
  s1.push('e');

//2)
  s1.push('F');
  q1.enQueue('G');

//3)
  s1.displayStack();
  cout << endl;
//4)
  q1.print_queue();
  cout << endl;//cout change!!

//5)
  cout << "OUTPUT: ";
  s1.pop();
  q1.deQueue();
  q1.deQueue();
  q1.deQueue();
  s1.pop();
  cout << endl;


//6)
  s1.pop();
  q1.deQueue();

//7)
  c1.enQueue('A');
  c1.enQueue('B');
  c1.enQueue('C');
  c1.deQueue();
  c1.enQueue('D');

//8)
  c1.print_cqueue();
  cout << endl;

//9)
  c1.deQueue();
  c1.deQueue();
  c1.deQueue();
  c1.deQueue();

}
