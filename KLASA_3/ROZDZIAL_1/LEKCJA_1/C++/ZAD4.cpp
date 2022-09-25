#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    int liczba;
    stack<int> rozlozona;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    while(liczba != 0){
        rozlozona.push(liczba%10);
        liczba=liczba/10;
    }

    while(!rozlozona.empty()){
        cout << rozlozona.top() << endl;
        rozlozona.pop();
    }

    return 0;
}
