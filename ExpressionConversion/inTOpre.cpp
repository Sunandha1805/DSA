#include<bits/stdc++.h>
using namespace std;

int prio(char c){
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

string infixTOpostfix(string s){
    stack<char> st;
    string result;

    for(int i=0; i<s.length(); i++){
        char c = s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
        }
        else if (c == '('){
            st.push(c);
        }
        else if (c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prio(c) < prio(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}

void infixTOprefix(string s){
    reverse(s.begin(), s.end());
    for (int i=0; i<s.length(); i++){
        if(s[i] == ')') s[i] = '(';
        else if(s[i] == '(') s[i] = ')';
    }
    string prefix = infixTOpostfix(s);
    reverse(prefix.begin(), prefix.end());
    cout<<"Prefix Expression : "<<prefix<<endl;
}

int main(){
    // string exp = "(p+q)*(m-n)";
    string exp;
    cin>>exp;
    cout<<"Infix Expression : "<<exp<<endl;
    infixTOprefix(exp);
}