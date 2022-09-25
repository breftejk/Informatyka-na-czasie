class Stos:
    def __init__(self):
        self.stos=[]

    def __str__(self):
        return f'{self.stos}'

    def push(self, wartosc):
        self.stos.append(wartosc)

    def peek(self):
        return self.stos[-1]

    def pop(self):
        self.stos.pop()

    def isEmpty(self):
        return len(self.stos) == 0