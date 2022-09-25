from stos import Stos


def wartosc_onp(postfix):
    stos = Stos()
    for i in range(len(postfix)):
        if postfix[i] >= '1' and postfix[i] <= '9':
            stos.push(int(postfix[i]))
        else:
            arg2 = stos.peek()
            stos.pop()
            arg1 = stos.peek()
            stos.pop()

            znak = postfix[i]
            if znak == '+':
                stos.push(arg1 + arg2)
            elif znak == '-':
                stos.push(arg1 - arg2)
            elif znak == '*':
                stos.push(arg1 * arg2)
            elif znak == '/':
                stos.push(arg1 / arg2)
            elif znak == '%':
                stos.push(arg1 % arg2)
            elif znak == '^':
                stos.push(arg1 ** arg2)
    wynik = stos.peek()
    return wynik


print(wartosc_onp(input('Podaj wyrażenie zapisane w ONP (np. 23+5* [to (2+3)*5]): ')))