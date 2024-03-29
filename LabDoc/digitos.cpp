//ENUNCIADO:
//separar digitos
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>


using namespace std;

int main()
{
    string Respuesta="y", numstring;
    int num=0, n, divisor, numnuevo, numposicion;
    bool respuestavalida = false, nodigito=true;
    
    while (Respuesta == "y") {
        cout << "Ingrese un numero: \n";
        cin >> numstring;
        while (cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
            std::cin >> numstring;
        }
        for (int i = 0; i < numstring.length(); i++) {
            try {
                numposicion = stoi(numstring.substr(i,1));
                num = num + (numposicion * pow(10, (numstring.length() - 1 - i)));
            }
            catch(exception){
                nodigito = false;
                break;
            }
        }
        while (nodigito == false) {
            nodigito = true;
            num = 0;
            std::cout << "El numero ingresado contenia un caractero o era negativo, favor ingresar un numero positivo. \n";
            std::cout << " \n";
            cout << "Ingrese un numero: \n";
            cin >> numstring;
            while (cin.fail()) {
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
                std::cin >> numstring;
            }
            for (int i = 0; i < numstring.length(); i++) {
                try {
                    numposicion = stoi(numstring.substr(i,1));
                    num = num + (numposicion * pow(10, (numstring.length() - 1 - i)));
                }
                catch (exception) {
                    nodigito = false;
                    break;
                }
            }
        }
        n = int(log10(num) + 1);
        int* array1 = new int(n);
        for (int i = n; i >0; i--) {
            if (i - 1 == 0) {
                divisor = 1;
            }
            else {
                divisor = pow(10, (i - 1));
            }
            
            array1[n - i] = (num / divisor);
            num = num - (divisor* array1[n - i]);
        }
        std::cout << "Los digitos del numero son: ";
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                std::cout << array1[i] << ".\n";
            }
            else {
                std::cout << array1[i] << ",";
            }
        }
        std::cout << "Desea intentar con otro numero?: (Y) para sí y (N) para no. \n";
        std::cin >> Respuesta;
        for (int i = 0; i < Respuesta.length(); i++) {
            Respuesta[i] = tolower(Respuesta[i]);
        }
        while(Respuesta != "y" && Respuesta != "n") {
            std::cout << "Respuesta incorrecta. \n";
            std::cout << "\n";
            std::cout << "Desea intentar con otro numero?: (Y) para sí y (N) para no. \n";
            std::cin >> Respuesta;
            for (int i = 0; i < Respuesta.length(); i++) {
                Respuesta[i] = tolower(Respuesta[i]);
            }
        }
    }
    std::cout << "Fin del programa. \n";
}

