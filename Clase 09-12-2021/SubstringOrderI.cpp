#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mTam = 1e5+5;
ll pos[mTam],aux,tam_cad;
bool cmp(ll A, ll B){
    ll men;
    if (pos[A] != pos[B]){
        men=pos[A]<pos[B];
        return men;
    }
    A=A+aux, B=B+aux;

    if(A<tam_cad && B<tam_cad){
        men=pos[A]<pos[B];
        return men;
    }else{
        return A>B;
    }
}
 
void suff(string cad,ll subcad[],ll temp[]) {
    ll i=0;
    for(i=0; i<tam_cad; i++){
        pos[i]=cad[i];
        subcad[i]=i;
    }
 
    for(aux=1;; aux <<= 1) {
        sort(subcad, subcad+tam_cad, cmp);
        for(i=0; i<tam_cad-1; i++){
            temp[i+1]=cmp(subcad[i],subcad[i+1])+temp[i];
        }
        for(i=0; i<tam_cad; i++){
            pos[subcad[i]]=temp[i];
        }
        if(tam_cad-1==temp[tam_cad-1]){
            break;
        }
    }
}

void LCP(string cad,ll lcp[],ll subcad[]) {
    ll i,j;
    for(i=0, j=0; i<tam_cad; i++){
        if(pos[i]!=tam_cad-1) {
            while(cad[subcad[pos[i]+1]+j]==cad[i+j]){
                j++;
            }
            lcp[pos[i]]=j;
            if(j){
                j--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string cad; cin>>cad;
    tam_cad=cad.size();
    ll k; cin>>k;

    ll subcad[mTam],temp[mTam],lcp[mTam];
    suff(cad,subcad,temp);
    LCP(cad,lcp,subcad);

    ll i,j,ant=0,act=0;
    string resp;
    for(i=0; i<tam_cad; i++) {
        if(act+(tam_cad-subcad[i])-ant>=k) {
            j=ant;
            resp=cad.substr(subcad[i], j);
            while(act<k){
                resp+=cad[subcad[i]+j], act++,j++;
            }
            return cout<<resp,0;
        }
        ll auxi=(tam_cad-subcad[i])-ant;
        act+=auxi, ant=lcp[i];
    }
}