import time

def getPascalRow(n):
    prev_row = []
    actual_row = []

    for i in range(n + 1):
        actual_tam = i + 1
        actual_row = [0] * actual_tam

        actual_row[0] = 1

        for j in range(1, i):
            actual_row[j] = prev_row[j - 1] + prev_row[j]

        if i > 0:
            actual_row[i] = 1

        prev_row = actual_row

    return actual_row


def showPolinom(coef, n):
    for i in range(n + 1):
        potencia = n - i
        c = coef[i]
        print(c, end="")

        if potencia > 1:
            print(f"x^{potencia}", end="")
        elif potencia == 1:
            print("x", end="")

        if i < n:
            print(" + ", end="")

    print()


def calculateValuex(coef, n, x):
    total_sum = 0
    print(f"\nCalculo paso a paso para x = {x}")

    for i in range(n + 1):
        potencia = n - i
        x_elevado = pow(x, potencia)
        term_value = coef[i] * x_elevado

        print(f"Termino {i}:")
        print(f"{coef[i]} * {x}^{potencia} = {term_value}")
        total_sum = total_sum + term_value

    print("---------------------")
    print(f"Suma total = {total_sum}")


def main():
    n = int(input("Introduce un numero entero no negativo: "))

    start = time.time()
    
    row_ptr = getPascalRow(n)
    
    end = time.time()
    
    showPolinom(row_ptr, n)
    calculateValuex(row_ptr, n, 2)

    
    print(f'Tiempo de ejecucion es: {end - start} segundos')


main()
