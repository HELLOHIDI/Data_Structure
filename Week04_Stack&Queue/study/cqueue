#include <iostream>
#define CQueueSize 10
using namespace std;

class CQueue{
    private:
        int front;
        int rear;
        int cqueue[CQueueSize];
    
    public:
        CQueue(){
            front = 0;
            rear = 0;
        }
        
        bool isEmpty(){
            if(front == rear){
                cout << "CQueue is empty" << endl;
                return true;
            }else{
                return false;
            }
        }
        
        bool isFull(){
            if(rear == CQueueSize){
                cout << "CQueue is full" << endl;
                return true;
            }else{
                return false;
            }
        }
        
        void enqueue(int val){
            rear %= CQueueSize;
            cqueue[++rear] = val;
        }
        int dequeue(){
            front %= CQueueSize;
            return cqueue[++front];
        }
        void printCQueue(){
            if(!isEmpty()){
                for(int i = front+1; i <= rear; i++){
                    cout << cqueue[i] << " ";                
                }
                cout << endl;
            }else{
                cout << "Queue is empty" << endl;
            }
            
        }
    };
