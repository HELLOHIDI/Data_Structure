#include <iostream>
using namespace std;


class Node{
private:
  int val;
  Node *next;
  Node(int data) {val = data; next = 0;}
  friend class List;
};

class List{
private:
  Node* head;
public:
  List();
  void insert();
  void deletelist();
  void search();
  void displayList();
  bool is_empty();
  void printlast();
  void printnth();
  int listLength();
};
List::List() { head = 0;}
int List::listLength(){
  Node *ptr;
  int length = 0;
  ptr = head;
  while(ptr){
    length++;
    ptr = ptr->next;
  }
  cout << length << endl;
  return length;
}
void List::insert(){
  int val;
  cout << "input a number => " ;
  cin >> val;
  Node *temp = new Node(val);
  Node *p, *q;
  if(head != 0 ){
    if(temp->val < head->val){
      temp->next = head;
      head = temp;
    }else{
      p = head;
      while((p != 0 && (p->val < temp->val))){
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
  displayList();
}
void List::deletelist(){
  Node *p, *q;
  int val;
  cout << "input a number => " ;
  cin >> val;
  if(head == 0){
    cout << "list is empty" << endl;
  }else{
    if(head->val == val){
      p = head;
      head = head->next;
      delete p;
    }else{
      p = head;
      while(p->val != val){
        q = p;
        p = p->next;
      }if(p!=0){
        q->next = p->next;
        delete p;
      }
    }
  }
}
void List::displayList(){
  Node *ptr;
  ptr = head;
  if(head == 0){cout << "List empty" << endl;}
  while(ptr){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;
}
bool List::is_empty(){
  if (head == 0)   {return true;}
  else  {return false;}
}
void List::printnth(){
  int idx;
  Node *p;
  cout << "Enter Nth  =>  " << endl;
  cin >> idx;
  if(head == 0){
    cout << "list is empty" << endl;
  }else if(idx > listLength() ){
    cout << "Out of boundary" << endl;
  }else{
    cout << "The  " << idx <<"st node: " ;
  }
}



void List::search(){
  int num;    Node *p;
  cout << "Enter a number =>  ";
  cin >> num;   cout << endl;
  if(head!=0){
    p = head;
    while(p!=0 && p->val != num){
      p = p->next;
    }if(p){
      cout << p->val << "is found" << endl;
    }else{
      cout << num << "is not in the list" << endl;
    }
  }else{
    cout << "List is empty" << endl;
  }
}

void List::printlast(){
  Node *p;
  if (head == 0){
    cout << "list is empty" << endl;
  }else{
    p = head;
    while(p->next != 0){
      p = p->next;
    }
    cout << p->val << endl;
  }
}











int main(void){
  List l1;
  int number;


  while(number != 7){
    cout << "Command : 1 )insert, 2)delete, 3)search, 4)printlist, 5)printLast, 6)printNth, 7) quit   =>";
    cin >> number;
    switch (number) {
      case 1:
        l1.insert();
        break;
      case 2:
        l1.deletelist();
        break;
      case 3:
        l1.search();
        break;
      case 4:
        l1.displayList();
        break;
      case 5:
        l1.printlast();
        break;
      case 6:
        l1.printnth();
        break;
      case 7:
        return 0;
      }
    }
}
