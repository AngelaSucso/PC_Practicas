#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int f, c;
    cin>>f>>c;
    int lista[f+1]={0};

    int ini, fin;
    for(int i=0; i<c; i++){
        cin>>ini>>fin;
        lista[ini]=lista[ini]+1;
        lista[fin+1]=lista[fin+1]-1;
    }

    for(int i=2; i<=f; i++){
        lista[i]=lista[i-1]+lista[i];
    }

    insertionSort(lista,f+1);

    cout<<lista[(f+1)/2];

    return 0;
}