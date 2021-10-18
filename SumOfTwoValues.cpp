/*
CSES Problem Set
Sum of Two Values
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    /*
    EJEMPLO:
    Input:
    4 8
    2 7 5 1

    Output:
    2 4
    */
    vector<int> numeros;
	map<int, int> pos;
	int tam, entrada, valor, num_esta;
    cin>>tam>>entrada;
	for (int i=0; i<tam; i++)
    {
        cin>>valor;
		numeros.push_back(valor);
        num_esta=entrada-numeros[i];
		if(pos.count(num_esta)) //count para comprobar si existe en valor en la key
        {
            cout<<pos[num_esta]<<" "<<i+1<<endl;
			return 0;
		}
        else{
            pos.insert(make_pair(numeros[i],i+1));
        }
	}
	cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
