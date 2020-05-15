/*
1) Main Heading
*********************************************************
* Name:  류희재
* Student ID : 20191587
* Program ID : HW4
* Description : Doubly Linked List의 여러 함수들을 테스트
* Algorithm : 함수들을 테스트 하는 것임으로 각각 함수 설명에서 알고리즘 개별적 설명 진행
* Variables:
클래스: Node, List
함수 : 
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
description : int형의 data값과 next, prev의 link를 묶어준 class이다.
              friend class list를 통해서 class list에서 private형인 
              변수들을 활용할 수 있도록 한다.
variables : data : 노드의 값
            next : 다음 노드를 가리키는 링크
            prev : 이전 노드를 가리키는 링크
function : Node(int val) -> class Node의 생성자

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
description : Node를 활용한 다양한 함수들을 묶은 class이다.
variables : Node *head = linked list의 시작을 알리는 노드이다
            Node *current = linked list의 현재 위치를 알리는 노드이다.

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
description : current node 뒤에 insert하는 함수이다.
algorithm : 1) 삽입해줄 노드를 생성한다.
            2) 만약 list가 비어있으면 삽입해줄 노드는 head이자 current 노드가 된다.
            3) 만약 current node의 next가 0이 아니라면 temp->next값을 current->next를 대입한다
            4) 그리고 current->next값을 temp로 지정한뒤 prev 노드들은 이 관계에 적합하게 대입해준다.
            5) temp를 current노드로 지정한다.
            6) 만약에 current node가 list의 마지막 노드라면 맨 마지막의 temp값을 삽입하고 current노드로 지정한다.
variables : Node *temp = 삽입해줄 노드
            Node * head = 시작을 알리는 노드
            Node *current = 현재상태를 알리는 노드

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
description : current node 앞에 insert하는 함수이다.
algorithm : 1) 삽입해줄 노드를 생성한다.
            2) 만약 list가 비어있으면 삽입해줄 노드는 head이자 current 노드가 된다.
            3) 만약 current node와 head node가 같다면 삽입해줄 노드의 다음 링크를 head로 지정하고(그에 맞게 prev 지정) temp노드는 
               head노드이자 current 노드가 된다.
            4) 만약 그렇지 않다면 값을 중간에 삽입해주는 코드를 구현한다
            5) temp를 current노드로 지정한다.
variables : Node *temp = 삽입해줄 노드
            Node * head = 시작을 알리는 노드
            Node *current = 현재상태를 알리는 노드

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
description : 리스트의 맨 앞에 insert하는 함수이다.
algorithm : 1) 삽입해줄 노드를 생성한다.
            2) 만약 list가 비어있으면 삽입해줄 노드는 head이자 current 노드가 된다.
            3) list가 비어있지 않으면 temp의 다음값을 head로 지정하고 (그에 맞게 prev 설정) temp는 head이자 current 노드가 된다.
variables : Node *temp = 삽입해줄 노드
            Node * head = 시작을 알리는 노드
            Node *current = 현재상태를 알리는 노드

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
description : 리스트에 맨 뒤에 insert하는 함수이다.
algorithm : 1) 삽입해줄 노드를 생성한다.
            2) 만약 list가 비어있으면 삽입해줄 노드는 head이자 current 노드가 된다.
            3) 만약 그렇지 않다면 Node *ptr을 생성하여 ptr->next값이 0이 될때까지 ptr = ptr->next를 대입해준다.
            4) ptr->next가 0이 되면 그 자리에 노드를 삽입한다
            5) temp를 current노드로 지정한다.
variables : Node *temp = 삽입해줄 노드
            Node *ptr = 삽입해줄 노드의 위치를 알려주는 매개변수

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
description : current node를 delete하는 함수이다.
algorithm : 1) 삽입해줄 노드를 생성한다.
            2) 만약 list가 비어있으면 삽입해줄 노드는 head이자 current 노드가 된다.
            3) 만약 current node의 next가 0이 아니라면 temp->next값을 current->next를 대입한다
            4) 그리고 current->next값을 temp로 지정한뒤 prev 노드들은 이 관계에 적합하게 대입해준다.
            5) temp를 current노드로 지정한다.
            6) 만약에 current node가 list의 마지막 노드라면 맨 마지막의 temp값을 삽입하고 current노드로 지정한다.
variables : Node *temp = 삽입해줄 노드
            Node * head = 시작을 알리는 노드
            Node *current = 현재상태를 알리는 노드

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
description : Nth번째 위치에 노드의 데이터를 출력하고 current node로 지정하는 함수이다.
algorithm : 1) Nth와 비교를 해주기 위해 cnt변수를 만들어서 순서를 표시하는 매개변수를 만들어준다.
            2) 만약 head가 0이면 리스트가 비어있음을 뜻함으로 "List is empty"를 출력해준다.
            3) 만약 리스트의 길이가 Nth보다 작으면 이 리스트 안에 값이 없다는 뜻으로 "No such a line"을 출력해준다.
            4) Nth와 cnt의 값이 같아질때까지 Node *p값을 p->next로 지정해준다
            5) Nth와 cnt 값이 같으면 순서를 나타내는 cnt와 p의 data값을 출력해준다.
            6) 그리고 current를 p로 바꿔준다.
variables : int cnt : 순서를 나타내는 변수
            Node *p = current 노드가 될 변수
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
description : current node의 data값을 바꿔주는 함수이다.
algorithm : 1) current의 data값을 바꿔준다.
****************************************************************************/
void List::updatecurrent(int data){
  current->data = data;
}
/****************************************************************************
function : void List::displaycurrent()
description : current node의 data값을 보여주는 함수이다.
algorithm : 1) 만약 head가 0이라면 리스트가 비어있음을 뜻함으로 "List is empty"를 출력한다.
            2) 리스트가 비어있지 않으면 current의 data값을 출력한다.
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
description : 리스트의 전체 노드를 출력하는 함수이다.
algorithm : 1) 노드의 순서를 표시하는 cnt 변수를 생성한다.
            2) 만약 head가 0이라면 리스트가 비어있음을 뜻함으로 "List is empty"를 출력한다.
            3) 리스트가 비어있지 않으면 Node *p를 생성한뒤 p를 head로 지정한다.
            4) p의 값이 current가 아니면 중간에 : 로 표시해주어 순서와 데이터값을 출력한다.
            5) p의 값이 current면 중간에 * 로 표시해주어 순서와 데이터값을 출력한다.
            6) Node를 출력하면 cnt값을 하나 늘려주고 p = p->nextㄹ 지정해준다.
variables : int cnt = 순서를 나타내는 변수
            Node *p = 출력을 하기 위한 매개변수

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
description : List의 소멸자함수이다.
algorithm : 1) Node 타입의 p를 생성한다
            2) p를 head로 지정한다.
            3) head를 head->next로 지정하면서 p의값을 삭제한다.
variables : Node *p = 리스트를 소멸하기 위한 매개변수

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
description : 리스트의 길이를 반환해주는 함수이다.
algorithm : 1) Node 타입의 p를 생성한다
            2) length 변수의 값을 1로 지정한다.(컴퓨터에선 0번째라고 생각하지만 locatecurrent()함수를 활용한때는 첫번째부터 생각하기 때문)
            3) p->next의 값이 0이 될때까지 length의 값을 하나씩 더해준다.
            4) length를 반환한다
variables : Node *p = 길이값을 만들어줄 매개변수
            int length = 리스트의 길이

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
description : List 클래스의 함수들을 실행하는 메인함수이다
algorithm : 1) List 타입의 변수를 생성해준다.
            2) number을 입력받아서 각각의 함수를 호출한다.
            3) number의 값이 10이 되면 l1을 소멸자를 통해 소멸하고 메인함수를 종료한다.
variables : List l1 = LIST의 변수
            int number = case를 나눠줄 변수
            int data = 노드를 생성 혹은 몇번째 노드를 가져올지 정할때 활용하는 변수

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
