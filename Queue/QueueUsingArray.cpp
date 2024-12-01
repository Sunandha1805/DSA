// ************** implementing Queue/Circular-Queue using arr *************

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int front, rear, curSize, maxSize;
    int * arr;

    public:
    Queue(int maxSize){
        (* this).maxSize = maxSize;
        front = -1;
        rear = -1;
        curSize = -1;
        arr = new int[maxSize];
    }

    bool isFull(){
        return curSize == maxSize;
    }

    bool isEmpty(){
        return curSize == 0;
    }

    void push(int x){
        if(isFull()){
            cout<<"Queue is full!"<<endl;
            exit(1);
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % maxSize;
        } 
        arr[rear] = x;
        curSize++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            exit(1);
        }
        int x = arr[front];
        if(curSize == 1){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % maxSize;
        }
        curSize--;
        return x;
    }

    int top(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            exit(1);
        }
        return arr[front];
    }

    int size(){
        return curSize;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
        }
        else{
            int i = front;
            while(true){
                cout<<arr[i]<<" ";
                if(i == rear) break;
                else i = (i+1) % maxSize;
            }
        }
    }
};

int main(){
    Queue q(16);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    q.push(60);
    q.push(70);
    q.display();
}

//Output
//10
//20
//30
//1
//40 60 70
