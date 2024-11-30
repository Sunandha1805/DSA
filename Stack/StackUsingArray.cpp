// ******************implementing stack using array ************************

#include<bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    int top;
    int * arr;
    
    public:
    Stack(){
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    bool isFull(){
        return top == size;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int x){
        if(isFull()){
            cout<<"Stack is Full!"<<endl;
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            exit(1);
        }
        int x = arr[top];
        top--;
        return x;
    }

    int Top(){
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            exit(1);
        }
        return arr[top];
    }

    int Size(){
        return top + 1;
    }

    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
        }
        else{
            for(int i = 0; i <= top; i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    s.push(40);
    s.display();
}

// output 
// 30
// 3
// 30
// 20
// 2
// 10 40


