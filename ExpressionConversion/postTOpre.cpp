#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    return ((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'));
}

void postfixTOprefix(const string& s){
    stack<string> st;
    string result;
    for(int i=0; i<s.length(); i++){
        if(isOperand(s[i])){
            string op(1, s[i]);
            st.push(op);
        }
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(s[i] + op2 + op1);
        }
    }
    cout<<"Prefix Expression : "<<st.top(); 
}

int main(){
    string postfix;
    cout<<"Enter Postfix Expression : ";
    cin>>postfix;
    postfixTOprefix(postfix);
}

