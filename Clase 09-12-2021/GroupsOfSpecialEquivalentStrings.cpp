#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        map<pair<string,string>,int> map;
        int i,j,tam=words.size();
        for(i=0; i<tam; i++){
            string str[2];
            int tami=words[i].length();
            for(j=0; j<tami; j++){
                str[j%2]=str[j%2]+words[i][j];
            }
            sort(str[0].begin(),str[0].end());
            sort(str[1].begin(),str[1].end());
            map[{str[0],str[1]}]++;
        }
        return map.size();       
    }
};

int main()
{
    Solution solu;
    vector<string> entrada{"abc","acb","bac","bca","cab","cba"};
    int rpta=solu.numSpecialEquivGroups(entrada);
    cout<<rpta;
    return 0;
}