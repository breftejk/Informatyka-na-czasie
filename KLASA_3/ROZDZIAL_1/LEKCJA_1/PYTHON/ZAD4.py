from stos import Stos

def rozloz(liczba):
    stos = Stos()
    while liczba != 0:
        stos.push(liczba%10)
        liczba//=10
    return stos


do_rozlozenia=int(input('Podaj liczbe: '))
for x in rozloz(do_rozlozenia):
    print(x)