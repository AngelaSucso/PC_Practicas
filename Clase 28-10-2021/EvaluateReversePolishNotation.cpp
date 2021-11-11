#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void imprimir_pila(stack<int>enteros){
    stack<int> st=enteros;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int num, n1, n2;

    for(int i=0; i<tokens.size(); i++){
        if(tokens[i][0]!='+' && tokens[i][0]!='*' && tokens[i][0]!='/' && tokens[i][0]!='-'){
            num=atoi(tokens[i].c_str());
            st.push(num);
        }
        else if(tokens[i][0]=='-' && tokens[i].size()>1){
            num=atoi(tokens[i].c_str());
            st.push(num);
        }
        else{
            n1=st.top(); //3
            st.pop();
            n2=st.top(); //4
            st.pop();
            if(tokens[i][0]=='+'){
                st.push(n1+n2);
            }
            else if(tokens[i][0]=='-'){
                st.push(n2-n1);
            }
            else if(tokens[i][0]=='*'){
                st.push(n1*n2);
            }
            else if(tokens[i][0]=='/'){
                st.push(n2/n1);
            }
        }
        //imprimir_pila(st);
    }
    return st.top();
}

int main(){
    vector<string> str;
    str={"4","3","-"};

    cout<<evalRPN(str);
}
