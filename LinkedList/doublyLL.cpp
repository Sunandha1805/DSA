#include <bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* ConvertArrToDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=0; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = prev->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    while(prev->next->next != NULL){
        prev = prev->next;
    }
    Node* temp = prev->next;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
 
Node* deletePos(Node* head, int pos){
    if(head == NULL) return NULL;
    Node* kNode = head;
    int cnt = 0;
    while(kNode != NULL){
        cnt++;
        if(cnt == pos) break;
        kNode = kNode->next;
    }
    Node* prev = kNode;
    prev->back->next = prev->next;
    prev->next->back = prev->back;
    prev->next = nullptr;
    prev->back = nullptr;
    delete prev;
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    delete temp;
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {23,67,34,45,56,67,78,89,90};
    Node* head = ConvertArrToDLL(arr);
    PrintLL(head);
    
    cout<<endl;
    
    head = deleteHead(head);
    PrintLL(head);

    cout<<endl;
    
    head = deleteTail(head);
    PrintLL(head);

    cout<<endl;
    
    head = deletePos(head, 4);
    PrintLL(head);
}



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        if(n%10 == 0) cout<<"NO";
        else{
            if((n/100==10 && n%100>1)||(n/10==10 && n%10 > 1)){
                cout<<"YES";
            }
            else cout<<"NO";
        }
    }
}


// ************************** output *********************

// 23 23 67 34 45 56 67 78 89 90 
// 23 67 34 45 56 67 78 89 90 
// 23 67 34 45 56 67 78 89 
// 23 67 34 56 67 78 89