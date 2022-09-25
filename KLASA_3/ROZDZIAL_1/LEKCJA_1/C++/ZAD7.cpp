#include <iostream>
#include <stack>

using namespace std;

bool czy_operand(char znak)
{
    return (znak >= '0' && znak <= '9') || (znak >= 'a' && znak <= 'z');
}

bool czy_operator(char znak)
{
    return (
        znak == '+' ||
        znak == '-' ||
        znak == '*' ||
        znak == '/'
    );
}

bool czy_poprawne(string wyrazenie)
{
    if(wyrazenie.size()<3)return false;
    if(!czy_operand(wyrazenie[0]) || !czy_operand(wyrazenie[1]) || !czy_operator(wyrazenie[wyrazenie.size()-1]))return false;

    int check = 0;
    for(char znak: wyrazenie){
        if(czy_operand(znak)){
            check++;
        }else if(czy_operator(znak)){
            check--;
        }
    }
    if(check!=1)return false;
    return true;
}

int main()
{
    string wyrazenie;
    cout << "Podaj wyrazenie zapisane w ONP do zweryfikowania: ";
    cin >> wyrazenie;

    cout << (czy_poprawne(wyrazenie) ? "TAK" : "NIE");

    return 0;
}
