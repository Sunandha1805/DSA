#include<bits/stdc++.h>
using namespace std;

bool isOperand(char c){
    return ((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9'));
}

void prefixTOpostfix(const string& s){
    stack<string> st;
    string result;
    int l = s.length();
    for(int i=l-1; i>=0 ; i--){
        if(isOperand(s[i])){
            string op(1, s[i]);
            st.push(op);
        }
        else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(op1 + op2 + s[i]);
        }
    }
    cout<<"Postfix Expression : "<<st.top(); 
}

int main(){
    string prefix;
    cout<<"Enter Prefix Expression : ";
    cin>>prefix;
    prefixTOpostfix(prefix);
}

