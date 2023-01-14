//Numero inmediatamente superior en O n
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include <iostream>
#include<stdio.h>
using namespace std;
int x = 0;

int partition(int Array[], int start, int end)
{

    int pivot = Array[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (Array[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(Array[pivotIndex], Array[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (Array[i] <= pivot) {
            i++;
        }

        while (Array[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(Array[i++], Array[j--]);
        }
    }

    return pivotIndex;
}
void quickSort(int Array[], int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(Array, start, end);

    // Sorting the left part
    quickSort(Array, start, p - 1);

    // Sorting the right part
    quickSort(Array, p + 1, end);
}
int main() {
    int j;
    int respuesta;
    bool existe = false;
    bool continuar = true;
    string respuestastring;
    // Preguntando tamaño del arreglo
    while (continuar == true) {
        cout << "De cuantos elementos desea sea el arreglo? \n";
        cin >> j;
        int* Array = new int[j];
        for (int i = 0; i < j; i++) {
            cout << "Ingrese el numero del elemento " << i << " del arreglo :\n";
            cin >> respuesta;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
                cin >> respuesta;
            }
            Array[i] = respuesta;
        }
        quickSort(Array, 0, j - 1);
        while (continuar == true) {
            cout << "El arreglo es: ";
            for (int i = 0; i < j; i++) {
                if (i == 0) {
                    cout << " " << Array[i] << " ,";
                }
                else {
                    if (i == j - 1) {
                        cout << " " << Array[i] << ".";
                    }
                    else {
                        cout << " " << Array[i] << " ,";
                    }

                }
            }
            cout << "\n";

            cout << "De cual numero desea saber el inmediatamente superior? \n";
            cin >> respuesta;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
                cin >> respuesta;
            }
            for (int i = 0; i < j; i++) {
                if (respuesta == Array[i]) {
                    if (i == j - 1) {

                        cout << "El numero no tiene otro valor inmediatamente superior en el arreglo.\n";
                    }
                    else {
                        existe = true;
                        cout << "El numero inmediatamente superior es: " << Array[i + 1] << ".\n";
                    }

                }

            }
            while (existe == false) {
                cout << "El numero " << respuesta << " no esta en el areglo. \n";
                cout << "El arreglo es: ";
                for (int i = 0; i < j; i++) {
                    if (i == 0) {
                        cout << " " << Array[i] << " ,";
                    }
                    else {
                        if (i == j - 1) {
                            cout << " " << Array[i] << ".";
                        }
                        else {
                            cout << " " << Array[i] << " ,";
                        }

                    }
                }
                cout << "\n";

                cout << "De cual numero desea saber el inmediatamente superior? \n";
                cin >> respuesta;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
                    cin >> respuesta;
                }
                for (int i = 0; i < j; i++) {
                    if (respuesta == Array[i]) {
                        if (i == j - 1) {
                            cout << "El numero no tiene otro valor inmediatamente superior en el arreglo.\n";
                        }
                        else {
                            existe = true;
                            cout << "El numero inmediatamente superior es: " << Array[i + 1] << ".\n";
                        }
                    }
                }
            }
            std::cout << "Desea iintentar con otro numero?: (Y) para sí y (N) para no. \n";
            std::cin >> respuestastring;
            for (int i = 0; i < respuestastring.length(); i++) {
                respuestastring[i] = tolower(respuestastring[i]);
            }
            while (respuestastring != "y" && respuestastring != "n") {
                std::cout << "Respuesta incorrecta. \n";
                std::cout << "\n";
                std::cout << "Desea intentar con otro numero?: (Y) para sí y (N) para no. \n";
                std::cin >> respuestastring;
                for (int i = 0; i < respuestastring.length(); i++) {
                    respuestastring[i] = tolower(respuestastring[i]);
                }
            }
            if (respuestastring[0] == 'y') {
                continuar = true;
            }
            else {
                if (respuestastring[0] == 'n') {
                    continuar = false;
                }
            }
        }
        continuar = false;
        std::cout << "Desea intentar con otro arreglo?: (Y) para sí y (N) para no. \n";
        std::cin >> respuestastring;
        for (int i = 0; i < respuestastring.length(); i++) {
            respuestastring[i] = tolower(respuestastring[i]);
        }
        while (respuestastring != "y" && respuestastring != "n") {
            std::cout << "Respuesta incorrecta. \n";
            std::cout << "\n";
            std::cout << "Desea intentar con otro arreglo?: (Y) para sí y (N) para no. \n";
            std::cin >> respuestastring;
            for (int i = 0; i < respuestastring.length(); i++) {
                respuestastring[i] = tolower(respuestastring[i]);
            }
        }
        if (respuestastring[0] == 'y') {
            continuar = true;
        }
        else {
            if (respuestastring[0] == 'n') {
                continuar = false;
            }

        }
    }
    std::cout << "Fin del programa. \n";
}








