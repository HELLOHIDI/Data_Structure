#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Node{
private:
  char data;
  Node *next;
  friend class List;
  Node(char value){data = value; next = 0;}
public:
  char getData() {return data;}
  Node * getNext() {return next;}

};
class List{
private:
  Node* head;
  Node *front;
  Node *rear;

public:
  void createStack() {head = 0;}
  void push(char data);
  char pop();
  bool isEmpty();
  void displayStack();
  void createQueue() {front = 0; rear = 0;}
  void enqueue(char data);
  char dequeue();
  void displayQueue();
  List();
  void insert(char data);
  void displayList();
  List invert();
  void deleteCurrent();
  void concentrate(List l1,List l2);
  int listLength();
};



List::List() { head = 0;}
void List::insert(char data){
  Node *temp = new Node(data);
  Node *p, *q;
  if(head != 0 ){
    if(temp->data < head->data){
      temp->next = head;
      head = temp;
    }else{
      p = head;
      while((p != 0 && (p->data < temp->data))){
        q = p;
        p = p->next;
      }if (p != 0){
        temp->next = p;
        q->next = temp;
      }else{
        q->next = temp;
      }
    }
  }else{
    head = temp;
  }
}
void List::displayList(){
  Node *ptr;
  ptr = head;
  while(ptr){
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

List List::invert(){
  Node *p = head;
  Node *q = 0;
  Node *r;
  while(p){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}
int List::listLength(){
  Node *ptr;
  int length = 0;
  ptr = head;
  while(ptr){
    length++;
    ptr = ptr->next;
  }
  return length;
}
void List::concentrate(List l1 ,List l2){
  Node *temp;
  if(!l1.isEmpty()){
    temp = l1.head;
    while(temp){
      insert(temp->getData());
      temp = temp->getNext();
    }
  }
  temp = l2.front;
  while(temp){
    insert(temp->getData());
    temp = temp->getNext();
  }
}





void List::push(char data){
  Node *temp = new Node(data);
  if(head == 0) {head = temp;}
  else{temp->next = head; head = temp;}
}
char List::pop(){
  Node *p;
  char num;
  num = head->data;
  p = head;
  head = head->next;
  delete p;
  cout << num << "=>  is popped!" << endl;
  return num;
}
bool List::isEmpty(){
  if(head == 0) return true;
  else return false;
}
void List:: displayStack(){
  Node *p;
  if(!isEmpty()){
    p = head;
    while(p){
      cout << p->data << " "; p = p->next;}
    }else{
      cout << "Stack empty";
    }
    cout << endl;
  }

void List::enqueue(char data){
    Node *temp = new Node(data);
    if(front == 0){
      front = temp;
      rear = temp;
    }else{
      rear->next = temp;
      rear = temp;
    }
  }
char List::dequeue(){
    Node *p;  char num;
    num = front->data;
    p = front;

    if(front ==rear){
      front = 0; rear = 0;
    }else{
      front = front->next;
    }
    delete p;
    cout << num << "=>  is popped!" << endl;
    return num;
  }
void List::displayQueue(){
    Node *p;
    if(front != 0){
      p = front;
      while(p){
        cout << p->data << " ";
        p = p->next;
      }
      cout << endl;
    }else{
      cout << "Queue is empty" << endl;
    }
  }


int main(void){
  List l1,l2,l3,l4;
  l1.createStack();
  l2.createQueue();
  int number;


  while(number != 10){
    cout << "Command : 1 )psuh, 2)pop, 3)printST, 4)enqueue, 5)dequeue, 6)printQ, 7)Merge 8)Invert 9)PrintList 10)quit   =>";
    cin >> number;
    switch (number) {
      case 1:
        char data;
        cout << "Enter an integer to push: " << " ";
        cin >> data;
        l1.push(data);
        break;
      case 2:
        l1.pop();
        break;
      case 3:
        l1.displayStack();
        break;
      case 4:
      char target;
      cout << "Enter an integer to enqueue: " << " ";
      cin >> target;
      l2.enqueue(target);
      break;
      case 5:
        l2.dequeue();
        break;
      case 6:
        l2.displayQueue();
        break;
      case 7:
        l3.concentrate(l1,l2);
        l3.displayList();
        break;
      case 8:
        l3.invert();
        l3.displayList();
        break;
      case 9:
        l3.displayList();
        break;
      }
    }
}
