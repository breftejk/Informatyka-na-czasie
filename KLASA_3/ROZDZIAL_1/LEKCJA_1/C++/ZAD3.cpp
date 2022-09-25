#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int main()
{
    stack<int> stos;

    string onp;
    cout << "Podaj wyrazenie zapisane w ONP (np. 23+5* [to (2+3)*5]): ";
    cin >> onp;

    for(int i=0;i<onp.size();i++){
        if (onp[i] >= '1' && onp[i] <= '9'){
            stos.push(int(onp[i])-'0');
        }else{
            int arg2 = stos.top();
            stos.pop();
            int arg1 = stos.top();
            stos.pop();

            char znak = onp[i];
            if(znak == '+'){
                stos.push(arg1+arg2);
            }else if(znak == '-'){
                stos.push(arg1-arg2);
            }else if(znak == '*'){
                stos.push(arg1*arg2);
            }else if(znak == '/'){
                stos.push(arg1/arg2);
            }else if(znak == '%'){
                stos.push(arg1%arg2);
            }else if(znak == '^'){
                stos.push(pow(arg1,arg2));
            }
        }
    }

    cout << stos.top();

    return 0;
}
