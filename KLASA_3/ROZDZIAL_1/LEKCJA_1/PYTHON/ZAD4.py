from stos import Stos

def rozloz(liczba):
    stos = Stos()
    while liczba != 0:
        stos.push(liczba%10)
        liczba//=10
    return stos


do_rozlozenia=int(input('Podaj liczbe: '))
rozlozone=rozloz(do_rozlozenia)
while not rozlozone.isEmpty():
    print(rozlozone.peek())
    rozlozone.pop()