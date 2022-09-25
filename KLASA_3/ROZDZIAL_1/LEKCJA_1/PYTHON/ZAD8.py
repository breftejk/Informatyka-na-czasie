from stos import Stos


def czy_para(otwierajacy, zamykajacy):
    pary = {
        '(': ')',
        '{': '}',
        '[': ']'
    }
    return pary[otwierajacy] == zamykajacy


def czy_wiekszy(nawias1, nawias2):
    moce = {
        '(': 0,
        '[': 1,
        '{': 2
    }
    return moce[nawias1] > moce[nawias2]


def sprawdz_wyrazenie(wyrazenie_nawiasowe):
    stos = Stos()
    for nawias in wyrazenie_nawiasowe:
        if nawias in '({[':
            if not stos.isEmpty():
                ostatni = stos.peek()
                if czy_wiekszy(nawias, ostatni):
                    return False
            stos.push(nawias)
        elif nawias in ')}]':
            if stos.isEmpty():
                return False
            else:
                otwierajacy = stos.peek()
                stos.pop()
                if not czy_para(otwierajacy, nawias):
                    return False
    return stos.isEmpty()


print('TAK' if sprawdz_wyrazenie(input('Podaj wyrażenie nawiasowe: ')) else 'NIE')