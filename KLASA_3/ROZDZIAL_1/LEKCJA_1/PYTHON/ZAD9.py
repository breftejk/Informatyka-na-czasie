from stos import Stos


def sortuj(lista, sposob_sortowania):
    stos=Stos()
    stos_temp=Stos()
    for i in range(len(lista)):
        while (not stos.isEmpty()) and (
                stos.peek() <= lista[i] if sposob_sortowania == 0
                else stos.peek() >= lista[i]
        ):
            stos_temp.push(stos.peek())
            stos.pop()
        stos.push(lista[i])
        while (not stos_temp.isEmpty()):
            stos.push(stos_temp.peek())
            stos_temp.pop()
    return stos


liczby=[int(x) for x in input('Podaj liczby: ').split()]
jak_sortowac=int(input('Jak sortować? 0 - malejąco, 1 - rosnąco: '))
print(sortuj(liczby, jak_sortowac))