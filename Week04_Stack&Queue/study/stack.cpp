#include <iostream>
#define StackSIZE 10
using namespace std;

class Stack{
    private:
        int stack[StackSIZE];
        int top;
    public:
    Stack(){top = -1;}
    
    bool isFull(){
        if(top == StackSIZE){
            cout << "stack is full" << endl;
            return true;
        }else{
            return false;
        }
    }
    
    bool isEmpty(){
        if(top == -1){
            cout << "stack is empty" << endl;
            return true;
        }else{
            return false;
        }
    }
    
    void push(int val){
        stack[++top] = val;
    }
    
    int pop(){
        return stack[top--];
    }
    
    void printStack(){
        for(int i = 0; i <= top; i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};
