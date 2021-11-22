#include <iostream>
#define QueueSize 10
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int queue[QueueSize];
    
    public:
        Queue(){
            front = 0;
            rear = 0;
        }
        
        bool isEmpty(){
            if(front == rear){
                cout << "Queue is empty" << endl;
                return true;
            }else{
                return false;
            }
        }
        
        bool isFull(){
            if(rear == QueueSize){
                cout << "Queue is full" << endl;
                return true;
            }else{
                return false;
            }
        }
        
        void enqueue(int val){
            queue[++rear] = val;
        }
        int dequeue(){
            return queue[++front];
        }
        void printQueue(){
            if(!isEmpty()){
                for(int i = front+1; i <= rear; i++){
                    cout << queue[i] << " ";                
                }
                cout << endl;
            }else{
                cout << "Queue is empty" << endl;
            }
            
        }
    };
