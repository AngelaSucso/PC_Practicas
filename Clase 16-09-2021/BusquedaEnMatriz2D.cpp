//Búsqueda en una matriz 2-D
#include <iostream>
#include <vector>
using namespace std;

bool busquedaMatriz2D(int vector[][3], int num){
    int fil = 3, col = 3, ini= 0, fin = fil * col;
    int p_medio, new_f, new_c;

    while (ini < fin)
    {
        /*
        Se verifica si un número está en dicha matriz o no.
        Devuelve verdadero al buscar el número 7
        Devuelve falso al buscar el número 12
        */
        p_medio = (ini+fin)/2;
        new_f = p_medio / col;
        new_c = p_medio % col;

        if(vector[new_f][new_c] < num){
            ini = p_medio + 1;
        }
        else if(vector[new_f][new_c] == num){
            return true;
        }else{
            fin = p_medio;
        }
    }
    return false;
}

int main(){
    /*
        EJEMPLO:
        INPUT:
        7 
        12

        OUTPUT:
        1
        0
    */
    int num;
    int vector[3][3]={{1,3,5},{7,9,11},{13,15,17}};

    while (cin>>num)
    {
        cout<<busquedaMatriz2D(vector,num)<<endl;
    }

    return 0;
}
