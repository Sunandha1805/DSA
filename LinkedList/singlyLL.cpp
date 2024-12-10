#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArrToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int LenghtOfLL(Node*head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* deleteHead(Node* head){
    Node* temp = head;
    head = temp->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deletePos(Node* head, int pos){
    if(head == NULL) return head;
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == pos){
            prev->next = prev->next->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteVal(Node* head, int val){
    if(head == NULL) return head;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

Node* insertTail(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == NULL) return newNode;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertPos(Node* head, int pos, int val){
    if(head == NULL){
        if(pos == 1) return new Node(val);
        else return head;
    }
    if(pos == 1){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == pos){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeVal(Node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == el){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->next->data == el){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {4,5,9,1,7,3,0,2};
    Node* head = ConvertArrToLL(arr);
    PrintLL(head);
    
    cout<<endl;
    
    head = deleteHead(head);
    PrintLL(head);
    
    cout<<endl;
    
    head = deleteTail(head);
    PrintLL(head);
    
    cout<<endl;
    
    head = deletePos(head,5);
    PrintLL(head);
    
    cout<<endl;
    
    head = deleteVal(head,9);
    PrintLL(head);
    
    cout<<endl;

    head = insertHead(head,10);
    PrintLL(head);

    cout<<endl;
    
    head = insertTail(head,20);
    PrintLL(head);

    cout<<endl;
    
    head = insertPos(head,5,30);
    PrintLL(head);

    cout<<endl;
    
    head = insertBeforeVal(head,1,40);
    PrintLL(head);
}


// *********************** output ***************************

// 4 5 9 1 7 3 0 2 
// 5 9 1 7 3 0 2 
// 5 9 1 7 3 0 
// 5 9 1 7 0 
// 5 1 7 0 
// 10 5 1 7 0 
// 10 5 1 7 0 20 
// 10 5 1 7 30 20 