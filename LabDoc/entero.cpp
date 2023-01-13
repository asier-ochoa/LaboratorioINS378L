//Escriba un programa C++ que dado un número entero retorne los dígitos del número dado.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num = 0;
    cout << "Ingrese el numero a separar: ";
    cin >> num;

    int size = trunc(log10(num)) + 1;

    int digits[size];

    while(num > 0) 
    {
        int mod = num % 10;
        cout << mod << ' ';
    
        num = num / 10;
    }

    return 0;
}