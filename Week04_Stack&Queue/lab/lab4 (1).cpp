#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


const int StackSize = 100; //stacksize
int check(char* exp);
void total(int a, int b, int c);
bool unmatch(char* a, char* b);


class Stack{
private:
  char stack[StackSize]; //stack
  int top; //top
public:
  Stack(){
    top = -1;
  }
  void push(int val){
    stack[++top] = val;
  }
  int pop(){
    return stack[top--];
  }
  int isEmpty(){
    return top == -1;
  }
  int isFull(){
    return top == StackSize - 1;
  }
  void displayStack();
};




int main(void){
  char buffer[80];
  int balanced = 0;
  int unbalanced = 0;
  int Mismatched = 0;
  ifstream inFile("lab4inputfile.txt");
  if(!inFile.is_open()){
    cerr << "error : inputfile.txt can't open" << endl;
    return 1;
  }
  else{
    while(inFile.getline(buffer,80)){
      cout << buffer << endl;
      int checking = check(buffer);
      if(checking == 0){
        unbalanced++;
      }else if(checking == 1){
        Mismatched++;
      }else{
        balanced++;
      }

    }

    total(balanced,unbalanced,Mismatched);
  }
}


int check(char *exp){
  Stack s1;

  for(int i = 0; i < strlen(exp); i++){
    char target = exp[i];
    if(target == '(' || target == '{' || target == '['){
      s1.push(exp[i]);
    }else if(target == ')' || target == '}' || target == ']'){
      if(s1.isEmpty()){
        cout << "The Expression has unbalanced parenthese" << endl;
        cout << endl;
        return 0;

      }else{
        char temp = s1.pop();
        if((target == ')' && temp != '(') || (target == '}' && temp != '{') || (target == ']' && temp != '[')){
          cout << "The Mismatched parenthese in the Expression are" << " " << temp << " " << "and" << " " << exp[i] << endl;
          cout << endl;
          return 1;
        }
      }
    }
    }
    if(s1.isEmpty()){
      cout << "The Expression is Valid" << endl;
      cout << endl;
      return 2;


    }else{
      cout << "The Expression has unbalanced parenthese" << endl;
      cout << endl;
      return 1;
    }


  }

void total(int a, int b, int c){
  cout << "Total:   " << "balanced: " << a << " " << "unbalanced:  " << b << " " << "Mismatched " << c << endl;
}
