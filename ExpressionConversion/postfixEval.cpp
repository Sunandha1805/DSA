#include<bits/stdc++.h>
using namespace std;

void postfixEval(const string& s){
    stack<int> st;
    string result;

    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch(s[i]){
                case '*' :
                    st.push(val2 * val1);
                    break;
                case '/' :
                    st.push(val2 / val1);
                    break;
                case '+' :
                    st.push(val2 + val1);
                    break;
                case '-' :
                    st.push(val2 - val1);
                    break;
            }
        }
    }
    cout<<"Postfix Evaluation : "<<st.top(); 
}

int main(){
    string postfix;
    cout<<"Enter Postfix Expression : ";
    cin>>postfix;
    postfixEval(postfix);
}