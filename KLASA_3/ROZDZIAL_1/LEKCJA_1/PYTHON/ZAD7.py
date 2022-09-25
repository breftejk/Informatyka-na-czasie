def czy_operand(char):
    return (char >= '0' and char <= '9') or (char >= 'a' and char <= 'z')


def czy_operator(char):
    return char in '+-*/'


def czy_poprawne(wyrazenie):
    if len(wyrazenie)<3:
        return False
    if (not czy_operand(wyrazenie[0])) or (not czy_operand(wyrazenie[1])) or (not czy_operator(wyrazenie[-1])):
        return False

    check=0
    for char in onp:
        if czy_operand(char):
            check+=1
        elif czy_operator(char):
            check-=1
    if check != 1:
        return False

    return True


onp = input('Podaj wyrażenie zapisane w ONP do zweryfikowania: ')
print('TAK' if czy_poprawne(onp) else 'NIE')