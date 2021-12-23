#include<bits/stdc++.h>
#define d double
using namespace std;

bool compar(pair<d,d> x, pair<d,d> y){
    d cmp1=x.second>y.second;
    d cmp2=x.first<y.first;
    if (x.first==y.first){
        return cmp1;
    }else{
        return cmp2;
    }
}

d asps,largo,ancho;
d pos,radius,dist;
void regar(d cant, d minim){
    if (cant>=largo){ 
        cout<<minim<<endl; // es posible regar
    }else{
        cout<<"-1"<<endl; // no lo es
    }
}

int main(){
    while(cin>>asps>>largo>>ancho) {
        vector<pair<d, d>> vec;
        d i,j,minim=0,cant=0;
        while(asps--){
            cin>>pos>>radius;
            if((ancho/2)<radius){
                dist=sqrt(pow(radius,2)-pow(ancho/2,2));
                d aux1=pos-dist, aux2=pos+dist;
                vec.push_back({aux1,aux2});
            }
        }
        sort(vec.begin(),vec.end(),compar);
        for(i=0; i<vec.size(); i++){
            if(vec[i].first>cant){
                break;
            }
            for(j=i+1; j<vec.size() && vec[j].first<=cant; j++){
                if(vec[j].second>vec[i].second){
                    i=j;
                }
            }
	        minim++;
            cant=vec[i].second;
            if(largo<=cant){
                break;
            }
        }
        regar(cant,minim);
    }
    return 0;
}