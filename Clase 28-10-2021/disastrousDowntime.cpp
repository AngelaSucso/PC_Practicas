#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;

int sol, max_sol;
unordered_map<int,int> map;

void requests(int sol, unordered_map<int,int> &map){
    for(int i = 0; i < sol; i++) {
        int temp;
        cin >> temp;
        map[temp]++;
    }
}

int query_actual(unordered_map<int,int> &map){
    int actual=0;
    for(int i = 0; i <= 999; i++) {
        actual += map[i];
    }
    return actual;
}

int max_query(int act, unordered_map<int,int> &map){
    int timeprocess = 1000;
    int maximos = 100000;

    int time = act;
    for(int i = timeprocess; i <= maximos; i++) {
        act += map[i];
        act -= map[i-1000];
        time = max(time, act);
    }
    return time;
}

int smallest(int A, int B) {
    int small=(B+A-1)/B;
    return small;
}

int main() {
    cin>>sol>>max_sol;
    int act, time, rpta;

    requests(sol,map);
    act = query_actual(map);
    time = max_query(act,map);
    rpta = smallest(time,max_sol);

    cout<<rpta<<endl;

    return 0;
}