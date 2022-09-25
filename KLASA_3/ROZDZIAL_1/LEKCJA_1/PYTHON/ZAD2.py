from stos import Stos


infix = input('Podaj wyrażenie algebraiczne zapisane w tradycyjnej notacji (dozwolone znaki to + - * / %): ')
postfix = Stos()
onp = ""

for i in range(len(infix)):
    if infix[i] == '(':
        postfix.push(infix[i])
    elif infix[i] == ')':
        while postfix.peek() != '(':
            onp += postfix.peek()
            postfix.pop()
        postfix.pop()
    elif infix[i] == '+' or infix[i] == '-':
        while (not postfix.isEmpty()) and postfix.peek() != '(':
            onp += postfix.peek()
            postfix.pop()
        postfix.push(infix[i])
    elif infix[i] == '*' or infix[i] == '/' or infix[i] == '%' or infix[i] == '^':
        if (not postfix.isEmpty()) and (postfix.peek() == '*'
                                        or postfix.peek() == '/'
                                        or postfix.peek() == '%'):
            onp += postfix.peek()
            postfix.pop()
        postfix.push(infix[i])
    else:
        onp += infix[i]

while (not postfix.isEmpty()):
    onp += postfix.peek()
    postfix.pop()

print(onp)