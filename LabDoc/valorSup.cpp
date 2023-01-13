//Escriba un programa C++, que dado un arreglo con números, resuelva de manera eficiente la inquietud siguiente: ¿Cuál es el valor inmediatamente superior para un número en la posición i?, donde la distancia es la diferencia entre los índices del arreglo.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<iostream>
using namespace std;

int main()
{
    //1 4 2 3 5 7
    int size = 0, indx = 0;
    cout << "Ingrese la longitud: ";
    cin >> size;
    int arr[size];

    for (size_t i = 0; i < size; i++)
    {
        cout << "Ingrese un valor: ";
        cin >> arr[i];
    }
    
    cout << "Cual indice quiere encontrar? ";
    cin >> indx;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == arr[indx] + 1)
        {
            cout << arr[i] << " es indmediatamente superior a " << arr[indx];
        }
    }
    
    return 0;
}