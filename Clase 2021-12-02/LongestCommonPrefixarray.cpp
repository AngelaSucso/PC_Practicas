#include<bits/stdc++.h>
using namespace std;

int main(){
    string cad; cin>>cad;
    map<string,int> sub_cad;
    vector<string> arr_subcad;
    vector<int> ind_subcad;

    int k;
    for(k=0; k<cad.size(); k++)
    {
        string aux_subcad=cad.substr(k);
        sub_cad.insert(make_pair(aux_subcad,k));
    }
    
    for(auto it:sub_cad)
    {
        arr_subcad.push_back(it.first);
    }

    ind_subcad.push_back(0);
    for(k=1; k<arr_subcad.size(); k++)
    {
        int cnt=0;
        int tam=min(arr_subcad[k].size(),arr_subcad[k-1].size());
        for(int i=0; i<tam; i++)
        {
            if(arr_subcad[k][i] == arr_subcad[k-1][i])
            {
                cnt++;
            }else{
                break;
            }
        }
        ind_subcad.push_back(cnt);
        cnt=0;
    }
    
    for(k=0; k<ind_subcad.size(); k++)
    {
        cout<<ind_subcad[k]<<endl;
    }
    return 0;
}
