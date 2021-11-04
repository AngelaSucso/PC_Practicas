/*
 CSES Problem Set
Sum of Three Values
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool dosnumeros(int aux, int tam, int entrada, vector<int> &numeros, map<int, int> &pos, vector<int> &rpta)
{
    for (int i = 0; i < tam; i++)
    {
        if (i != aux)
        {
            int num_esta = entrada - numeros[i];
            if (pos.count(num_esta))
            {
                rpta.push_back(pos[num_esta]);
                rpta.push_back(i + 1);
                return true;
            }
            else
            {
                pos.insert(make_pair(numeros[i], i + 1));
            }
        }
        else
        {
            continue;
        }
    }
    return false;
}

void tresnumeros(int tam, int entrada, vector<int> &numeros, map<int, int> &pos, vector<int> &rpta)
{
    /*
    Se recorre el vector de datos y se llama a la funcion de 2 numeros para darle un tamaño distinto, 
    (el valor de entrada menos el indice actual del recorrido)
    */
    int aux;
    for (int i = 0; i <= tam; i++)
    {
        rpta.push_back(i + 1);
        aux = i;
        if (dosnumeros(aux, tam, entrada - numeros[i], numeros, pos, rpta))
        {
            for (int i = 0; i < rpta.size(); i++)
            {
                cout << rpta[i] << " ";
            }
            cout << endl;
            break;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
            break;
        }
        rpta.clear();
    }
}

int main()
{
    /*
        EJEMPLO:
        Input:
        4 8
        2 7 5 1
        Output:
        1 3 4
    */

    vector<int> numeros, rpta;
    map<int, int> pos;
    int tam, entrada;
    cin >> tam >> entrada;

    int valor;

    // RECIBO LOS VALORES DE ENTRADA
    for (int i = 0; i < tam; i++)
    {
        cin >> valor;
        numeros.push_back(valor);
    }
    tresnumeros(tam, entrada, numeros, pos, rpta);

    return 0;
}
