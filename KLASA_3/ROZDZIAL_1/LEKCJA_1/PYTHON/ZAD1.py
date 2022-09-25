from stos import Stos

def sprawdz_wyrazenie(wyrazenie_nawiasowe):
    stos = Stos()
    for nawias in wyrazenie_nawiasowe:
        if nawias == '(':
            stos.push(nawias)
        elif nawias == ')':
            if stos.isEmpty():
                return False
            else:
                if stos.peek() != '(':
                    return False
                else:
                    stos.pop()
    return stos.isEmpty()


print('TAK' if sprawdz_wyrazenie(input('Podaj wyrazenie nawiasowe: ')) else 'NIE')