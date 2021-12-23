#include <bits/stdc++.h>

using namespace std;

int minAddToMakeValid(string input_s){
    int acum=0;
    stack<char> st;

    for(int i=0; i<input_s.size(); i++){
        if(input_s[i]=='('){
            st.push(input_s[i]);
        }
        else if(input_s[i]==')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }else{
                st.push(input_s[i]);
            }
        }
    }

    while(!st.empty()){
        st.pop();
        acum++;
    }
    cout<<acum<<endl;
}

int main(){

    string entrada;
    getline(cin,entrada);

    minAddToMakeValid(entrada);

    return 0;
}
