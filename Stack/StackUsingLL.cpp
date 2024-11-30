#include <bits/stdc++.h>
using namespace std;

struct stackNode {
    int data;
    stackNode* next;

    stackNode(int val){
        data = val;
        next = NULL;
    }
};

struct Stack {
    stackNode* top;
    int size;
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int val){
        if(top == NULL){
            stackNode* element = new stackNode(val);
            top = element;
        }else{
            stackNode* element = new stackNode(val);
            element -> next = top;
            top = element;
            size++;
        }
    }

    int pop(){
        if(top == NULL){
            cout<<"stack is empty!"<<endl;
            return -1;
        }
        int popEl = top -> data;
        stackNode* temp = top;
        top = top ->next;
        delete temp;
        size--;
        return popEl;
    }

    int Top(){
        if(top == NULL){
            cout<<"stack is empty!"<<endl;
            return -1;
        }
        return top -> data;
    }

    int Size(){
        return size;
    }

    void printStack(){
        if(top == NULL){
            cout<<"Stack is empty!"<<endl;
        }else{
            stackNode* current = top;
            while(current != NULL){
                cout<<current -> data<<" ";
                current = current -> next;
            } 
        }
    }
};

int main(){
    Stack s;
    s.push(12);
    s.push(13);
    s.push(56);
    s.push(78);
    cout<<s.pop()<<endl;
    cout<<s.Top()<<endl;
    s.push(45);
    s.push(79);
    s.push(23);
    cout<<s.Size()<<endl;
    s.printStack();
}

//Output
//78
//56
//6
//23 79 45 56 13 12