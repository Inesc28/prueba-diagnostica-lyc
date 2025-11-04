#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int *getPascalRow(int n)
{
    int *prev_row = nullptr;
    int *actual_row = nullptr;

    for (int i = 0; i <= n; i++)
    {
        int actual_tam = i + 1;
        actual_row = new int[actual_tam];

        actual_row[0] = 1;

        for (int j = 1; j < i; j++)
        {
            actual_row[j] = prev_row[j - 1] + prev_row[j];
        }

        if (i > 0)
        {
            actual_row[i] = 1;
        }

        if (prev_row != nullptr)
        {
            delete[] prev_row;
        }
        prev_row = actual_row;
    }

    return actual_row;
}

void showPolinom(int coeficients[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        int potencia = n - i;
        int coef = coeficients[i];
        cout << coef;

        if (potencia > 1)
        {
            cout << "x^" << potencia;
        }
        else if (potencia == 1)
        {
            cout << "x";
        }

        if (i < n)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

void calculateValuex(int coeficients[], int n, int x)
{
    int total_sum = 0;
    cout << "Calculo paso a paso para x = " << x << ":" << endl;

    for (int i = 0; i <= n; i++)
    {
        int potencia = n - i;
        int x_elevado = (int)pow(x, potencia);
        int term_value = coeficients[i] * x_elevado;

        cout << "  Termino " << i << ": ";
        cout << coeficients[i] << " * (" << x << ")^" << potencia << " = " << term_value << endl;
        total_sum = total_sum + term_value;
    }

    cout << "----------------------" << endl;
    cout << "Suma total = " << total_sum << endl;
}

int main()
{
    int n;
    cout << "Introduce un numero entero no negativo: ";
    cin >> n;

    if (n < 0)
        return 1;

    auto start = chrono::high_resolution_clock::now();

    int *row_ptr = getPascalRow(n);

    auto end = chrono::high_resolution_clock::now();

    showPolinom(row_ptr, n);
    calculateValuex(row_ptr, n, 2);

    cout << "Fila " << n << ": ";
    int row_size = n + 1;
    for (int k = 0; k < row_size; k++)
    {
        cout << row_ptr[k] << " ";
    }

    cout << endl;
    delete[] row_ptr;

    

    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "Tiempo de ejecucion: " << duration.count() << " microsegundos" << endl;

    return 0;
}