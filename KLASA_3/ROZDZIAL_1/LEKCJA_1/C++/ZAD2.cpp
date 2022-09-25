#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string infix;
    cout << "Podaj wyrazenie algebraiczne zapisane w tradycyjnej notacji (dozwolone znaki to + - * / %): ";
    cin >> infix;

    stack<char> postfix;
    string onp = "";

    for(int i=0;i<infix.size();i++){
        if(infix[i] == '('){
            postfix.push(infix[i]);
        }else if(infix[i] == ')'){
            while(postfix.top() != '('){
                onp += postfix.top();
                postfix.pop();
            }
            postfix.pop();
        }else if(infix[i] == '+' || infix[i] == '-'){
            while (!postfix.empty() && postfix.top() != '('){
                    onp+=postfix.top();
                    postfix.pop();
            }
            postfix.push(infix[i]);
        }else if(infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '^'){
            if(!postfix.empty() && (postfix.top()=='*' || postfix.top() == '/' || postfix.top() == '%')){
                onp += postfix.top();
                postfix.pop();
            }
            postfix.push(infix[i]);
        }else{
            onp+=infix[i];
        }
    }

    while (!postfix.empty()){
        onp+=postfix.top();
        postfix.pop();
    }

    cout << onp;

    return 0;
}
