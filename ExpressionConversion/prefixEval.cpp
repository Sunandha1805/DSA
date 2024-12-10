#include<bits/stdc++.h>
using namespace std;

void prefixEval(const string& s){
    stack<int> st;
    string result;
    int l = s.length();
    for(int i=l-1; i>=0; i--){
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
                    st.push(val1 * val2);
                    break;
                case '/' :
                    st.push(val1 / val2);
                    break;
                case '+' :
                    st.push(val1 + val2);
                    break;
                case '-' :
                    st.push(val1 - val2);
                    break;
            }
        }
    }
    cout<<"Prefix Evaluation : "<<st.top(); 
}

int main(){
    string prefix;
    cout<<"Enter Prefix Expression : ";
    cin>>prefix;
    prefixEval(prefix);
}