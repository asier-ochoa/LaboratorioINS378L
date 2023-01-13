// ConsoleApplication4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

int main()
{
    std::string Respuesta="y", numstring;
    int num=0, n, divisor, numnuevo, numposicion;
    bool respuestavalida = false, nodigito=false;

    while (Respuesta == "y") {
        std::cout << "Ingrese un numero: \n";
        std::cin>> numstring;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "No ha ingresado un numero positivo, favor ingresar un numero positivo. \n";
            std::cin >> numstring;
        }
        for (int i = 0; i < numstring.length(); i++) {
            nodigito = isdigit((int)numstring[i]);
            try {
                numposicion = stoi(numstring.substr(i,1));
                num = num + (numposicion * pow(10, (numstring.length() - 1 - i)));
            }
            catch(exception){
                nodigito = true;
                break;
            }
        }
        while (nodigito == true) {
            nodigito = false;
            num = 0;
            std::cout << "El numero ingresado contenia un caractero o era negativo, favor ingresar un numero positivo. \n";
            std::cout << " \n";
            std::cout << "Ingrese un numero: \n";
            std::cin >> numstring;
            while (std::cin.fail()) {
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
                    nodigito = true;
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
    

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln