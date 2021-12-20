#include <bits/stdc++.h>
using namespace std;

const long long maxsize = 1e5 + 5;

string cad, aux_subcad;
map<string, long long> sub_cad;
vector<string> arr_subcad;
long long ind_subcad[maxsize], cnt, tam, acum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int casos;
    cin >> casos;

    for (long long i = 0; i < casos; i++)
    {
        cin >> cad;
        long long k;
        for (k = 0; k < cad.size(); k++)
        {
            aux_subcad = cad.substr(k);
            sub_cad.insert(make_pair(aux_subcad, k));
        }
        for (auto it : sub_cad)
        {
            arr_subcad.push_back(it.first);
        }

        ind_subcad[0] = 0;
        for (k = 1; k < arr_subcad.size(); k++)
        {
            cnt = 0;
            for (long long i = 0; i < min(arr_subcad[k].size(), arr_subcad[k - 1].size()); i++)
            {
                if (arr_subcad[k][i] == arr_subcad[k - 1][i])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            ind_subcad[k] = cnt;
        }

        acum = 0;
        for (k = 0; k < arr_subcad.size(); k++)
        {
            if (ind_subcad[k] > ind_subcad[k - 1])
            {
                acum += (ind_subcad[k] - ind_subcad[k - 1]);
            }
        }
        cout << acum << endl;
        arr_subcad.clear();
        sub_cad.clear();
    }
    return 0;
}