#include<bits/stdc++.h>
using namespace std;

int main(){
    string cad; cin>>cad;
    map<string,int> sub_cad;
    vector<int> arr_subcad;

    int k;
    for(k=0; k<cad.size(); k++){
        string aux_subcad=cad.substr(k);
        sub_cad.insert(make_pair(aux_subcad,k));
    }

    for(auto it:sub_cad){
        arr_subcad.push_back(it.second);
    }

    for(k=0; k<arr_subcad.size(); k++){
        cout<<arr_subcad[k]<<endl;
    }
    cout<<endl;

    return 0;
}