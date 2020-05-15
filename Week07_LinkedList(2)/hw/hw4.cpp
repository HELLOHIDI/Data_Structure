/*
1) Main Heading
*********************************************************
* Name:  ������
* Student ID : 20191587
* Program ID : HW4
* Description : Doubly Linked List�� ���� �Լ����� �׽�Ʈ
* Algorithm : �Լ����� �׽�Ʈ �ϴ� �������� ���� �Լ� ������ �˰��� ������ ���� ����
* Variables:
Ŭ����: Node, List
�Լ� : 
  List(){head = 0; current = 0;}
  ~List();
  void insertafter(int data);
  void insertbefore(int data);
  void insertfirst(int data);
  void insertlast(int data);
  void deletecurrent();
  void locatecurrent(int Nth, int length);
  void updatecurrent(int data);
  void displaycurrent();
  void displaylist();
  void quit();
  int length();
  int main(void);
*************************************************************************/
#include <iostream>
using namespace std;

/****************************************************************************
class : Node
description : int���� data���� next, prev�� link�� ������ class�̴�.
              friend class list�� ���ؼ� class list���� private���� 
              �������� Ȱ���� �� �ֵ��� �Ѵ�.
variables : data : ����� ��
            next : ���� ��带 ����Ű�� ��ũ
            prev : ���� ��带 ����Ű�� ��ũ
function : Node(int val) -> class Node�� ������

****************************************************************************/
class Node{
private:
  int data;
  Node *next;
  Node *prev;
  Node (int val){ data = val; next = 0; prev = 0;}
  friend class List;
};

/****************************************************************************
class : List
description : Node�� Ȱ���� �پ��� �Լ����� ���� class�̴�.
variables : Node *head = linked list�� ������ �˸��� ����̴�
            Node *current = linked list�� ���� ��ġ�� �˸��� ����̴�.

****************************************************************************/
class List{
private:
  Node *head;
  Node *current;
public:
  List(){head = 0; current = 0;}
  ~List();
  void insertafter(int data);
  void insertbefore(int data);
  void insertfirst(int data);
  void insertlast(int data);
  void deletecurrent();
  void locatecurrent(int Nth, int length);
  void updatecurrent(int data);
  void displaycurrent();
  void displaylist();
  void quit();
  int length();

};

/****************************************************************************
function : void List::insertafter(int data)
description : current node �ڿ� insert�ϴ� �Լ��̴�.
algorithm : 1) �������� ��带 �����Ѵ�.
            2) ���� list�� ��������� �������� ���� head���� current ��尡 �ȴ�.
            3) ���� current node�� next�� 0�� �ƴ϶�� temp->next���� current->next�� �����Ѵ�
            4) �׸��� current->next���� temp�� �����ѵ� prev ������ �� ���迡 �����ϰ� �������ش�.
            5) temp�� current���� �����Ѵ�.
            6) ���࿡ current node�� list�� ������ ����� �� �������� temp���� �����ϰ� current���� �����Ѵ�.
variables : Node *temp = �������� ���
            Node * head = ������ �˸��� ���
            Node *current = ������¸� �˸��� ���

****************************************************************************/
void List::insertafter(int data){
  Node *temp = new Node(data);
  if(head == 0){
    head = temp;
    current = temp;
  }else if(current->next != 0){
    temp->next = current->next;
    current->next = temp;
    temp->prev = current;
    temp->next->prev = temp;
    current = temp;
}else{
    current->next = temp;
    temp->next = 0;
    temp->prev = current;
    current = temp;
  }
}
/****************************************************************************
function : void List::insertbefore(int data)
description : current node �տ� insert�ϴ� �Լ��̴�.
algorithm : 1) �������� ��带 �����Ѵ�.
            2) ���� list�� ��������� �������� ���� head���� current ��尡 �ȴ�.
            3) ���� current node�� head node�� ���ٸ� �������� ����� ���� ��ũ�� head�� �����ϰ�(�׿� �°� prev ����) temp���� 
               head������� current ��尡 �ȴ�.
            4) ���� �׷��� �ʴٸ� ���� �߰��� �������ִ� �ڵ带 �����Ѵ�
            5) temp�� current���� �����Ѵ�.
variables : Node *temp = �������� ���
            Node * head = ������ �˸��� ���
            Node *current = ������¸� �˸��� ���

****************************************************************************/
void List::insertbefore(int data){
  Node  *temp = new Node(data);
  if(head == 0){
    head = temp;
    current = temp;
  }else if(current == head){
    temp->next = head;
    head->prev = temp;
    head = temp;
    current = temp;
  }else{
      temp->prev = current->prev;
      current->prev->next = temp;
      current->prev = temp;
      temp->next = current;
      current = temp;
  }
}
/****************************************************************************
function : void List::insertfirst(int data)
description : ����Ʈ�� �� �տ� insert�ϴ� �Լ��̴�.
algorithm : 1) �������� ��带 �����Ѵ�.
            2) ���� list�� ��������� �������� ���� head���� current ��尡 �ȴ�.
            3) list�� ������� ������ temp�� �������� head�� �����ϰ� (�׿� �°� prev ����) temp�� head���� current ��尡 �ȴ�.
variables : Node *temp = �������� ���
            Node * head = ������ �˸��� ���
            Node *current = ������¸� �˸��� ���

****************************************************************************/
void List::insertfirst(int data){
  Node *temp = new Node(data);
  if(head == 0){
    head = temp;
    current = temp;
  }else{
    temp->next = head;
    head->prev = temp;
    head = temp;
    current = temp;
  }
}
/****************************************************************************
function : void List::insertlast(int data)
description : ����Ʈ�� �� �ڿ� insert�ϴ� �Լ��̴�.
algorithm : 1) �������� ��带 �����Ѵ�.
            2) ���� list�� ��������� �������� ���� head���� current ��尡 �ȴ�.
            3) ���� �׷��� �ʴٸ� Node *ptr�� �����Ͽ� ptr->next���� 0�� �ɶ����� ptr = ptr->next�� �������ش�.
            4) ptr->next�� 0�� �Ǹ� �� �ڸ��� ��带 �����Ѵ�
            5) temp�� current���� �����Ѵ�.
variables : Node *temp = �������� ���
            Node *ptr = �������� ����� ��ġ�� �˷��ִ� �Ű�����

****************************************************************************/
void List::insertlast(int data){
  Node *temp = new Node(data);
  if(head == 0){
    head = temp;
    current = temp;
  }else{
    Node *ptr = head;
    while(ptr->next != 0){
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
  current = temp;
}
/****************************************************************************
function : void List::deletecurrent()
description : current node�� delete�ϴ� �Լ��̴�.
algorithm : 1) �������� ��带 �����Ѵ�.
            2) ���� list�� ��������� �������� ���� head���� current ��尡 �ȴ�.
            3) ���� current node�� next�� 0�� �ƴ϶�� temp->next���� current->next�� �����Ѵ�
            4) �׸��� current->next���� temp�� �����ѵ� prev ������ �� ���迡 �����ϰ� �������ش�.
            5) temp�� current���� �����Ѵ�.
            6) ���࿡ current node�� list�� ������ ����� �� �������� temp���� �����ϰ� current���� �����Ѵ�.
variables : Node *temp = �������� ���
            Node * head = ������ �˸��� ���
            Node *current = ������¸� �˸��� ���

****************************************************************************/
void List::deletecurrent(){
  Node *temp;
  Node *p, *q;
  if(head == 0){
    cout << "List is empty" << endl;
  }else if(current == head){
    temp = head;
    head = head->next;
    head->prev = 0;
    current = head;
    delete temp;
  }else{
    q = head; p = head;
    while(p != current){
      q = p;
      p = p->next;
    }
    if( p!= 0){
      q->next = p->next;
      if(p->next != 0){
        p->next->prev = q;
        current = q;
        delete p;
      }else{
        current = q;
        delete p;
      }
    }
  }
}
/****************************************************************************
function : void List::locatecurrent(int Nth, int length)
description : Nth��° ��ġ�� ����� �����͸� ����ϰ� current node�� �����ϴ� �Լ��̴�.
algorithm : 1) Nth�� �񱳸� ���ֱ� ���� cnt������ ���� ������ ǥ���ϴ� �Ű������� ������ش�.
            2) ���� head�� 0�̸� ����Ʈ�� ��������� �������� "List is empty"�� ������ش�.
            3) ���� ����Ʈ�� ���̰� Nth���� ������ �� ����Ʈ �ȿ� ���� ���ٴ� ������ "No such a line"�� ������ش�.
            4) Nth�� cnt�� ���� ������������ Node *p���� p->next�� �������ش�
            5) Nth�� cnt ���� ������ ������ ��Ÿ���� cnt�� p�� data���� ������ش�.
            6) �׸��� current�� p�� �ٲ��ش�.
variables : int cnt : ������ ��Ÿ���� ����
            Node *p = current ��尡 �� ����
****************************************************************************/
void List::locatecurrent(int Nth, int length){
  int cnt = 1;
  if(head == 0){
    cout << "List is empty" << endl;
  }else if(length < Nth){
    cout << "No such a line" << endl;
  }else{
    Node *p = head;
    while(cnt != Nth){
      p = p->next;
      cnt++;
    }
    cout << cnt << " " << "*" << " " <<  p->data << endl;
    current = p;

  }
}
/****************************************************************************
function : void List::updatecurrent(int data)
description : current node�� data���� �ٲ��ִ� �Լ��̴�.
algorithm : 1) current�� data���� �ٲ��ش�.
****************************************************************************/
void List::updatecurrent(int data){
  current->data = data;
}
/****************************************************************************
function : void List::displaycurrent()
description : current node�� data���� �����ִ� �Լ��̴�.
algorithm : 1) ���� head�� 0�̶�� ����Ʈ�� ��������� �������� "List is empty"�� ����Ѵ�.
            2) ����Ʈ�� ������� ������ current�� data���� ����Ѵ�.
****************************************************************************/
void List::displaycurrent(){
  if(head == 0){
    cout << "list is empty" << endl;
  }else{
    cout<< current->data << endl;
  }
}
/****************************************************************************
function : void List::displaylist()
description : ����Ʈ�� ��ü ��带 ����ϴ� �Լ��̴�.
algorithm : 1) ����� ������ ǥ���ϴ� cnt ������ �����Ѵ�.
            2) ���� head�� 0�̶�� ����Ʈ�� ��������� �������� "List is empty"�� ����Ѵ�.
            3) ����Ʈ�� ������� ������ Node *p�� �����ѵ� p�� head�� �����Ѵ�.
            4) p�� ���� current�� �ƴϸ� �߰��� : �� ǥ�����־� ������ �����Ͱ��� ����Ѵ�.
            5) p�� ���� current�� �߰��� * �� ǥ�����־� ������ �����Ͱ��� ����Ѵ�.
            6) Node�� ����ϸ� cnt���� �ϳ� �÷��ְ� p = p->next�� �������ش�.
variables : int cnt = ������ ��Ÿ���� ����
            Node *p = ����� �ϱ� ���� �Ű�����

****************************************************************************/
void List::displaylist(){
  int cnt = 0;
  if(head == 0){
    cout << "List is empty" << endl;
  }else{
    cout << "---List---" << endl;
    Node *p;
    p = head;
    while (p != 0){
      cnt++;
      if(p == current){ cout << cnt << " " << "*" << " " << p->data << endl;}
      else{ cout << cnt << " " << ":" << " " << p->data << endl;}
      p = p->next;
    }
  }
}
/****************************************************************************
function : List::~List()
description : List�� �Ҹ����Լ��̴�.
algorithm : 1) Node Ÿ���� p�� �����Ѵ�
            2) p�� head�� �����Ѵ�.
            3) head�� head->next�� �����ϸ鼭 p�ǰ��� �����Ѵ�.
variables : Node *p = ����Ʈ�� �Ҹ��ϱ� ���� �Ű�����

****************************************************************************/
List::~List(){
  Node *p;
  while(head != 0){
    p = head;
    head = head->next;
    delete p;
  }
}
/****************************************************************************
function : int List::length()
description : ����Ʈ�� ���̸� ��ȯ���ִ� �Լ��̴�.
algorithm : 1) Node Ÿ���� p�� �����Ѵ�
            2) length ������ ���� 1�� �����Ѵ�.(��ǻ�Ϳ��� 0��°��� ���������� locatecurrent()�Լ��� Ȱ���Ѷ��� ù��°���� �����ϱ� ����)
            3) p->next�� ���� 0�� �ɶ����� length�� ���� �ϳ��� �����ش�.
            4) length�� ��ȯ�Ѵ�
variables : Node *p = ���̰��� ������� �Ű�����
            int length = ����Ʈ�� ����

****************************************************************************/
int List::length(){
  Node *p =head;
  int length = 1;
  while(p->next != 0){
    p = p->next;
    length++;
  }
  return length;
}

/****************************************************************************
function : int main(void)
description : List Ŭ������ �Լ����� �����ϴ� �����Լ��̴�
algorithm : 1) List Ÿ���� ������ �������ش�.
            2) number�� �Է¹޾Ƽ� ������ �Լ��� ȣ���Ѵ�.
            3) number�� ���� 10�� �Ǹ� l1�� �Ҹ��ڸ� ���� �Ҹ��ϰ� �����Լ��� �����Ѵ�.
variables : List l1 = LIST�� ����
            int number = case�� ������ ����
            int data = ��带 ���� Ȥ�� ���° ��带 �������� ���Ҷ� Ȱ���ϴ� ����

****************************************************************************/
int main(void){
  List l1;
  int number;
  while(number != 10){
    cout << "Command:1)insertafter 2)insertbefore 3)insertfirst 4)insertlast 5)deletecurrent" << endl;
    cout << "        6)locatecurrent 7)updatecurrent 8)displaycurrent 9)displaylist 10)quit" << endl;
    cout << "==>  " << " ";
    cin >> number;
    switch (number) {
      int data;

      case 1:
        cout << "Enter a data to insert: " << " ";
        cin >> data;
        l1.insertafter(data);
        l1.displaylist();
        break;
      case 2:
        cout << "Enter a data to insert: " << " ";
        cin >> data;
        l1.insertbefore(data);
        l1.displaylist();
        break;
      case 3:
        cout << "Enter a data to insert: " << " ";
        cin >> data;
        l1.insertfirst(data);
        l1.displaylist();
        break;
      case 4:
        cout << "Enter a data to insert: " << " ";
        cin >> data;
        l1.insertlast(data);
        l1.displaylist();
      break;
      case 5:
        l1.deletecurrent();
        l1.displaylist();
        break;
      case 6:
        cout << "Enter a position to locate: " << " ";
        cin >> data;
        l1.locatecurrent(data,l1.length());
        break;
      case 7:
        cout << "Enter a data to update: " << " ";
        cin >> data;
        l1.updatecurrent(data);
        l1.displaylist();
        break;
      case 8:
        l1.displaycurrent();
        break;
      case 9:
        l1.displaylist();
        break;
      case 10:
        l1.~List();
        break;
      }
    }
}
