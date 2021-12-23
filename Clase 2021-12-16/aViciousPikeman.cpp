#include<bits/stdc++.h>
#define l long
using namespace std;

int compare(const void *cantProb, const void *totMins) {
    int *x=(int*)cantProb;
    int *y=(int*)totMins;
    int res=*x - *y;
    return res;
}

l cantProb,totMins;
void rpta(l timeReq[]){
    l res=0,penal=0,timeTot=0;
    for(int i=0; i<cantProb; i++){
        l sum=timeReq[i]+timeTot;
		if(sum<=totMins){
			res=res+1;
			timeTot+=timeReq[i];
			penal+=timeTot;
		}else{
            break;
        }
	}
    l mod=penal%1000000007;
    cout<<res<<" "<<mod;
}

int main(){
	cin>>cantProb>>totMins;
    l A, B, C, t0; cin>>A>>B>>C>>t0;
    l timeReq[cantProb];
	timeReq[0]=t0;
    
	for(int i=1; i<cantProb; i++){
        //formula tiempo requerido para c/ problema
        l form=(((A*timeReq[i-1])+B)%C)+1;
		timeReq[i]=form;
	}
	qsort(timeReq,cantProb,sizeof(l),compare);
    rpta(timeReq);

	return 0;
}