#include <iostream>
using namespace std;

class Node{
private:
  int data;
  Node *left;
  Node *right;
  friend class BST;
public:
  Node(int value) {data = value; left = 0; right = 0;}
};

class BST{
private:
  Node *root;
public:
  void createTree() {root = 0;}
  Node* getRoot() {return root;}
  void setRoot(Node *ptr) {root = ptr;}
  Node* searchTree(Node *ptr, int key);
  Node* insertTree(Node *ptr, int key);
  Node* deleteTree(Node* ptr, int key);
  Node* find_max(Node *p);
  void drawTree();
  void drawBSTree(Node *ptr,int level);
  bool isEmpty() const{return root == NULL;}
  bool printlevel(Node *p, int level);
  void Levelorder();
  void NumOfNodes();
  int Nonleaves(Node *ptr, int count);
  int leaves(Node *p, int count);
};


Node* BST::searchTree(Node *ptr, int key){
  if(ptr == 0)  {cout << key << "is not found in Tree" << endl;}
  else{
    if(key == ptr->data) {cout << ptr->data << "is founded in Tree" << endl;}
    else if(key < ptr->data){
      ptr = searchTree(ptr->left, key);
    }else if(key > ptr->data){
      ptr = searchTree(ptr->right, key);
    }
  }
  return ptr;
}


Node* BST::insertTree(Node *ptr, int key){
  if(ptr == 0){
    Node* temp = new Node(key);
    return temp;
  }
  if(key < ptr->data){
    ptr->left = insertTree(ptr->left, key);
  }else if(key > ptr->data){
    ptr->right = insertTree(ptr->right, key);
  }
  return ptr;
}

Node* BST::deleteTree(Node*ptr, int key){
  if(ptr!=0){
    if(key < ptr->data){
      ptr->left = deleteTree(ptr->left,key);
    }else if(key > ptr->data){
      ptr->right = deleteTree(ptr->right,key);
    }else if((ptr->left == 0)&&(ptr->right == 0)){
      ptr = 0;
    }else if(ptr->left == 0){
      Node *p = ptr;
      ptr = ptr->right;
      delete(p);
    }else if(ptr->right == 0){
      Node *p = ptr;
      ptr = ptr->left;
      delete(p);
    }else{
      Node *temp = find_max(ptr->left);
      ptr->data = temp->data;
      ptr->left = deleteTree(ptr->left, ptr->data);
    }
  }else{
    cout << "Not found" << endl;
  }
  return ptr;
}

Node* BST::find_max(Node *p){
  if(p == 0) {return 0;}
  if(p->right == 0)  {return p;}
  else {return find_max(p->right);}
}


void BST::drawTree(){
  drawBSTree(getRoot(),1);
}

void BST::drawBSTree(Node *ptr, int level){
  if(ptr!=0&&level <= 7){
    drawBSTree(ptr->right,level+1);
    for(int i = 1; i <= (level-1); i++)
      cout << " ";
    cout<<ptr->data;
    if(ptr->left != 0 && ptr->right != 0) cout << "<" << endl;
    else if(ptr->right != 0) cout << "/" << endl;
    else if(ptr->left != 0) cout << "\\" << endl;
    else                    cout << endl;
    drawBSTree(ptr->left,level+1);
  }
}



bool BST::printlevel(Node *ptr, int level){
  if(ptr == 0) {return false;}
  if(level == 1) {cout << ptr->data << " ";  return true;}
  else{
    bool left = printlevel(ptr->left, level-1);
    bool right = printlevel(ptr->right, level - 1);
    return left||right;
  }
}

void BST::Levelorder(){
  int level = 1;
  while(printlevel(getRoot(),level)){
    level++;
  }
  cout << endl;
}

void BST::NumOfNodes(){
  int count_leaves = 0;
  int count_Nonleaves = 0;
  int a = leaves(getRoot(),count_leaves);
  cout << "Number of leaves: " << a << " ";
  int b = Nonleaves(getRoot(),count_Nonleaves);
  cout << "Number of Nonleaves: " << b << " ";
  cout << endl;
}


int BST::leaves(Node *ptr, int count){
  if(ptr){
    if(ptr->left == 0 && ptr->right == 0){
      count++;
    }else{
      count = leaves(ptr->left,count) + leaves(ptr->right,count);
    }
  }else{
    count = 0;
  }
  return count;
}

int BST::Nonleaves(Node *ptr, int count){
  if(ptr){
    if(ptr->right == 0 && ptr->left == 0){
      count = 0;
    }else{
      count = Nonleaves(ptr->left,count) + Nonleaves(ptr->right,count)+1;
    }
  }else{
    count = 0;
  }
  return count;
}








int main(void){
  BST b1;
  b1.createTree();
  int number;
  while(number!=7){
      cout<< "Command:(1.insert 2.delete 3.Levelorder 4.search 5.Draw 6.NumofNodes 7.quit):" << " ";
      cin >> number;
      switch (number) {
        case 1:
        int target;
        cout << "Enter number to insert: " << " ";
        cin >> target;
        b1.setRoot(b1.insertTree(b1.getRoot(),target));
        break;
        case 2:
        int target2;
        if(b1.getRoot() == 0){
          cout << "Tree is empty!" << endl;
          break;
        }else{
          cout << "Enter number to delete: " << " ";
          cin >> target2;
          b1.deleteTree(b1.getRoot(),target2);
          break;
        }
        case 3:
        if(b1.getRoot() == 0){
          cout << "Tree is empty!" << endl;
          break;
        }else{
          b1.Levelorder();
          break;
        }
        case 4:
        int target3;
        if(b1.getRoot() == 0){
          cout << "Tree is empty!" << endl;
          break;
        }else{
          cout << "Enter number to search: " << " ";
          cin >> target3;
          b1.searchTree(b1.getRoot(),target3);
          break;
        }

        case 5:
        b1.drawTree();
        break;

        case 6:
        if(b1.getRoot() == 0){
          cout << "Tree is empty!" << endl;
          break;
        }else{
          b1.NumOfNodes();
          break;
        }
      }
    }
  }
