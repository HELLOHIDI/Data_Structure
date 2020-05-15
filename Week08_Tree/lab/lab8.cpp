#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


class Node{
private:
  char data;
  Node *left;
  Node *right;
  char prio;
  friend class Tree;
  friend class linkedStack;
public:
  Node(char value) {data = value; left = 0; right = 0; prio = '4';}
  char getdata() {return data;}
  char getprio() {return prio;}
  void setdata(char value) {data = value;}
  void setprio(char value) {prio = value;}
};

class Tree{
private:
  Node *root;
public:

  void createTree() {root = 0;}
  //~Tree();
  Node* getRoot() {return root;}
  void operand(Node* temp);
  void operate(Node* temp);
  int evalTree(Tree t1);
  void inorder(Node *p);
  void postorder(Node *p);
  void preorder(Node *p);
  int evalTree(Node *p);
};

int main(void){
  char exp1[80] = "8+9-2*3";
  char exp2[80] = "A/B*C*D+E";
  cout << "Infix Expression1  : " << exp1 << endl;
  cout << endl;
  int result;
  char prec[4][2] = {'*','2', '/','2', '+','1', '-','1'};
  Tree t1, t2;
  t1.createTree();  t2.createTree();
  char exp;
  for(int i = 0; i <strlen(exp1); i++){
      exp = exp1[i];
      Node *temp = new Node(exp);
      for(int j = 0; j <= 3; j++){
        if(temp->getdata() == prec[j][0]){
          temp->setprio(prec[j][1]);
          break;
        }
      }
      if(temp->getprio() == '4'){
        t1.operand(temp);
      }else{
        t1.operate(temp);
      }
    }
    cout << "InOrder  : " << " ";
    t1.inorder(t1.getRoot());
    cout << endl;
    cout << "PostOrder  : " << " ";
    t1.postorder(t1.getRoot());
    cout << endl;
    cout << "PreOrder  : " << " ";
    t1.preorder(t1.getRoot());
    cout << endl;

    result = t1.evalTree(t1.getRoot());
    cout << "Evaluation : " << " ";
    cout << result << endl;
    cout << endl;
    cout << "Infix Expression2  : " << exp2 << endl;
  for(int i = 0; i <strlen(exp2); i++){
      exp = exp2[i];
      Node *temp = new Node(exp);
      for(int j = 0; j <= 3; j++){
        if(temp->getdata() == prec[j][0]){
          temp->setprio(prec[j][1]);
          break;
        }
      }
      if(temp->getprio() == '4'){
        t2.operand(temp);
      }else{
        t2.operate(temp);
      }
    }
    cout << "InOrder  : " << " ";
    t2.inorder(t2.getRoot());
    cout << endl;
    cout << "PostOrder  : " << " ";
    t2.postorder(t2.getRoot());
    cout << endl;
    cout << "PreOrder  : " << " ";
    t2.preorder(t2.getRoot());
    cout << endl;

  }


void Tree::operand(Node *temp){
  if(root == 0){
    root = temp;
  }else{
    Node *p = root;
    while(p->right != 0){
      p = p->right;
    }
    p->right = temp;
  }
}

void Tree::operate(Node *temp){
  if(root->prio >= temp->prio){
    temp->left = root;
    root = temp;
  }else{
    temp->left = root->right;
    root->right = temp;
  }
}


void Tree::inorder(Node *p){
  if(p){
    inorder(p->left);
    cout << p->data;
    inorder(p->right);

  }
}

void Tree::postorder(Node *p){
  if(p){
    postorder(p->left);
    postorder(p->right);
    cout << p->data;
  }
}

void Tree::preorder(Node *p){
  if(p){
    cout << p->data;
    preorder(p->left);
    preorder(p->right);
  }
}

int Tree::evalTree(Node *p){
  int value = 0;
  int left, right;
  if(p != 0){
    if(0 <= p->data -'0' && p->data -'0' <= 9){
      value = p->data -'0';
    }else{
      left = evalTree(p->left);
      right = evalTree(p->right);
      switch (p->data) {
        case '+':
          value = left + right;
          break;
        case '-':
          value = left - right;
          break;
        case '*':
          value = left * right;
          break;
        case '/':
          value = left / right;
          break;

      }
    }
  }
  return value;
}
