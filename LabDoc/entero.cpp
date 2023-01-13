//Escriba un programa C++ que dado un número entero retorne los dígitos del número dado.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num = 0, length = 0;
    cout << "Ingrese el numero a separar: ";
    cin >> num;

    int size = trunc(log10(num)) + 1;

    do
    {
        ++length;
        num /= 10;
    } while (num);

    cout << length << " dividiendo base 10\n";
    cout << size << " con Cmath";
    

    return 0;
}