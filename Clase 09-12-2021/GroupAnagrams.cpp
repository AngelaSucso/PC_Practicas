#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        vector<vector<string>>rpta;
        
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end());
            map[tmp].push_back(str);
        }
        
        for(auto it:map){
            rpta.push_back(it.second);
        }
        return rpta;
    }
};

int main()
{
    Solution solu;
    vector<string> entrada{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> rpta;
    rpta=solu.groupAnagrams(entrada);
    for (auto iter:rpta){
        for (auto str:iter){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}
