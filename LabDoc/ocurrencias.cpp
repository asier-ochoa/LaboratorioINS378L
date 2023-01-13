//Escriba un programa C++, que dado un arreglo con múltiples valores, imprima la 
//ocurrencia de cada elemento en el mismo.
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include<iostream>

int main()
{
    int size, v, count, m, c = 0;
    std::string input;
    bool valid = false;
    std::cout << "Digite tamano del arreglo : ";
    while (!valid){
        std::cin >> input;
        valid = true;
        for (const auto& x: input){
            if (x < '0' || x > '9'){
                std::cout << "Caracter invalido! Vuelva a intentar : ";
                valid = false;
                break;
            }
        }
    }
    valid = false;
    size = atoi(input.c_str());
    input.clear();

    int a[size];
    int n[size];

    std::cout << "Digite los valores del arreglo\n";

    for (int i = 0; i < size; i++) {
        std::cout << "Digite el valor numero " << i + 1 << " : ";
        while (!valid){
            std::cin >> input;
            valid = true;
            for (const auto& x: input){
                if (x < '0' || x > '9'){
                    std::cout << "Caracter invalido! Vuelva a intentar : ";
                    valid = false;
                    break;
                }
            }
        }
        a[i] = atoi(input.c_str());
        valid = false;
    }

    for(int j = 0; j < size; j++) {
        v = a[j];
        count = 0;
        m = 1;
        for (int i = 0; i < size; i++) {
            if (v == a[i])
               count++;
        }

        for (int i = 0; i < c; i++) {
            if (n[i] == v)
                m=0;
        }
        if (m == 1) {
            std::cout << "El valor " << v << " se repite " << count << " veces\n";
            n[c] = v;
            c++;
        }
    }
    return 0;
}