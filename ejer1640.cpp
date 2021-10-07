/*
CSES Problem Set
Sum of Two Values
*/

#include <iostream>
#include <vector>
using namespace std;

//funcion imprimir
void printArray(vector<int> num, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << num[i] << " ";
    cout << endl;
}

//FUNCION BUSCAR 2 NUMEROS Y SUMADOS DEN EL VALOR DE ENTRADA
bool Dosnumeros(vector<int> num,vector<int> &sal, int entrada, int ini, int fin)
{   
    while(ini != fin)
    {
        /*Se guarda los indices al principio y final del array comparando
        con el dato de entrada, segun sea menor o mayor el dato, los indices se
        moverá al siguiente o anterior, respectivamente, hasta encontrar que la
        suma de los indices sean el dato de entrada*/
        if(entrada < num[ini] + num[fin]){
            fin--;
        }
        else if(entrada > num[ini] + num[fin]){
            ini++;
        }
        else{
            sal.push_back(num[ini]);
            sal.push_back(num[fin]);
            return true;
        }
    }

    if(ini==fin){
        cout<<"IMPOSSIBLE"; 
    }
}


//FUNCIONES PARA ORDENAR EL ARRAY DESORDENADO QUE INGRESA POR CONSOLA
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(vector<int> &num, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (num[j] < num[min_idx])
                min_idx = j;
        }

        swap(&num[min_idx], &num[i]);
    }
}

int main(){

    /*
    EJEMPLO:
    Input:
    4 8
    2 7 5 1

    Output:
    2 4
    */

    //INPUT
    int tam, entrada; cin>>tam>>entrada;
    int numero;
    vector<int> sal;
    vector<int> numeros2;
    vector<int> c_numeros2;
    for(int i=0; i<tam; i++){
        cin>>numero;
        numeros2.push_back(numero);
        c_numeros2.push_back(numero);
    }

    selectionSort(numeros2,numeros2.size());
    bool rpta = Dosnumeros(numeros2,sal,entrada,0,numeros2.size()-1);
    
    //OUTPUT
    for(int i=0; i<c_numeros2.size(); i++){
        for(int j=0; j<sal.size(); j++){
            if(c_numeros2[i]==sal[j]){
                cout<<i+1<<" ";
            }
        }
    }


    return 0;
}