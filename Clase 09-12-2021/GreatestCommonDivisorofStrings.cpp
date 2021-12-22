#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string rpta;
        int i,j;
        for (i=0; i<str1.size(); ++i){
            int mod1=str1.size()%(i+1);
            int mod2=str2.size()%(i+1);
            if(mod1!=0||mod2!=0){
                continue;
            }
            string sub=str1.substr(0,i+1);
            string ac1,ac2;
            int div1=str1.size()/(i+1);
            int div2=str2.size()/(i+1);
            for(j=0; j<div1; j++){
                ac1=ac1+sub;
            }
            if(ac1!=str1){
                continue;
            }
            for(j=0; j<div2; j++){
                ac2=ac2+sub;
            }
            if(ac2!=str2){
                continue;
            }
            rpta=sub;
        }
        return rpta;
    }
};

int main()
{
    Solution solu;
    string str1="ABCABC";
    string str2="ABC";
    string rpta=solu.gcdOfStrings(str1,str2);
    cout<<rpta;
    return 0;
}