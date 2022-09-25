#include <iostream>
#include <stack>

using namespace std;

bool czy_poprawny(string wyrazenie)
{
    stack<char> stos;

    for(char nawias: wyrazenie){
        if(nawias == '('){
            stos.push(nawias);
        }else if(nawias == ')'){
            if(stos.empty())return false;
            if(stos.top() != '(')return false;
            stos.pop();
        }
    }

    return stos.size() == 0;
}

int main ()
{
    string wyrazenie;
    cout << "Podaj wyrazenie nawiasowe: ";
    cin >> wyrazenie;

    cout << (czy_poprawny(wyrazenie) ? "TAK" : "NIE");
    return 0;
}
