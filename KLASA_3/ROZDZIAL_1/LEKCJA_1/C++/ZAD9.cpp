#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

stack<int> sortuj(vector<int> liczby, int sposob_sortowania)
{
    stack<int> stos;
    stack<int> stos_temp;

    for(int i=0;i<liczby.size();i++){
        while(!stos.empty() && (
                (sposob_sortowania == 1) ? stos.top() <= liczby[i] : stos.top() >= liczby[i]
        )){
            stos_temp.push(stos.top());
            stos.pop();
        }
        stos.push(liczby[i]);
        while (!stos_temp.empty()){
            stos.push(stos_temp.top());
            stos_temp.pop();
        }
    }

    return stos;
}

int main()
{
    string liczby_str;
    cout << "Podaj liczby: ";
    getline(cin, liczby_str);
    stringstream iss(liczby_str);

    vector<int> liczby;

    int liczba;
    while (iss >> liczba) {
        liczby.push_back(liczba);
    }

    int sposob;
    cout << "Jak sortowac? 0 - malejaco, 1 - rosnaco: ";
    cin >> sposob;

    stack<int> posortowane = sortuj(liczby, sposob);

    while(!posortowane.empty()){
        cout << posortowane.top() << " ";
        posortowane.pop();
    }

    return 0;
}
