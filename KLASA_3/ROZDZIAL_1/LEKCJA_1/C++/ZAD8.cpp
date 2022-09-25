#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool czy_para(char otwierajacy, char zamykajacy)
{
    map<char,char> pary;
    pary['('] = ')';
    pary['['] = ']';
    pary['{'] = '}';

    return pary[otwierajacy] == zamykajacy;
}

bool czy_wiekszy(char nawias1, char nawias2)
{
    map<char,int> moce;
    moce['('] = 0;
    moce['['] = 1;
    moce['{'] = 2;
    return moce[nawias1] > moce[nawias2];
}

bool sprawdz_wyrazenie(string wyrazenie)
{
    stack<char> stos;

    for(char nawias: wyrazenie){
        if(nawias=='(' || nawias=='[' || nawias=='{'){
            if(!stos.empty()){
                char ostatni = stos.top();
                if(czy_wiekszy(nawias,ostatni))return false;
            }
            stos.push(nawias);
        }else{
            if(stos.empty())return false;
            char otwierajacy = stos.top();
            stos.pop();
            if(!czy_para(otwierajacy, nawias))return false;
        }
    }

    return stos.empty();
}

int main()
{
    string wyrazenie;

    cout << "Podaj wyrazenie nawiasowe: ";
    cin >> wyrazenie;

    cout << (sprawdz_wyrazenie(wyrazenie) ? "TAK" : "NIE");

    return 0;
}
