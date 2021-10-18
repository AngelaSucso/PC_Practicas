/*
 CSES Problem Set
Sum of Three Values 
*/

#include <iostream>
#include <vector>
using namespace std;

//FUNCION IMPRIMIR
void printArray(vector<int> num, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << num[i] << " ";
    cout << endl;
}

//FUNCION BUSCAR 2 DE LOS 3 NUMEROS
bool Dosnumeros(vector<int> num, int entrada, int &ini, int &fin)
{    
    while(ini != fin){
        if(entrada < num[ini] + num[fin]){ 
            fin--;
        }
        else if(entrada > num[ini] + num[fin]){  
            ini++;
        }
        else
        {
            return true;
        }
    }

    return false;
}

//FUNCION BUSCAR 3 NUMEROS Y SUMADOS DEN EL VALOR DE ENTRADA
bool TresNumeros(vector<int> num,vector<int> &sal, int entrada)
{
    /*Se guarda 2 indices al principio y uno al final del array comparando
    con el dato de entrada, segun sea menor o mayor el dato, un indice del principio
    se y el del final se moverán al siguiente o anterior, respectivamente, llamando
    a la funcion Dosnumeros(), se encontrara el valor de entrada menos el primer
    indice que se encuentra en el array(iterara por el array de forma independiente), 
    hasta que los 3 indices obtengan sumados el dato de entrada*/
    int i;
    for(i=0; i<=num.size()-2; i++){
        int ini = i+1, final=num.size()-1;
        if (Dosnumeros(num,entrada-num[i], ini, final)){
            sal.push_back(num[i]);
            sal.push_back(num[ini]);
            sal.push_back(num[final]);
            return true;
        }
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
        1 3 4
    */

    //INPUT
    int tam, entrada; cin>>tam>>entrada;
    int numero;
    vector<int> sal;
    vector<int> numeros3;
    vector<int> c_numeros3;
    for(int i=0; i<tam; i++){
        cin>>numero;
        numeros3.push_back(numero);
        c_numeros3.push_back(numero);
    }

    selectionSort(numeros3,numeros3.size());
    bool rpta = TresNumeros(numeros3,sal,entrada);

    //OUTPUT
    if(rpta){
        for(int i=0; i<c_numeros3.size(); i++){
            for(int j=0; j<sal.size(); j++){
                if(c_numeros3[i]==sal[j]){ // 5
                    cout<<i+1<<" ";
                }
            }
        }
    }else{
        cout<<"IMPOSSIBLE ";
    }

    return 0;
}
