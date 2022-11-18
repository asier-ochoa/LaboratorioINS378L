//ENUNCIADO:
/*Realizar un programa C++ que lea un número real (correspondiente a un monto) y convertir este monto a palabra.

Restricciones: 
• El # tiene mascara 999,999,999.99 
• Si el grupo determina puede variar el alcance del algoritmo. 
• Solo llevar a palabras la parte entera del número. 
• Utilizar el enfoque de divide y venceras 

El programa debe desplegar en pantalla el resultado de la conversión del número a palabra. 
Deben observarse todas las reglas gramaticales relativas a nombrar los numerales. Ejemplo: 
si el usuario introduce 12,345.90 

El programa debería desplegar Doce mil trescientos cuarenta y cinco con 90 centavos*/

//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

//FECHA: 18/11/22

#include <string>
#include <iostream>
#include <vector>

#define NUM_EXCEPTION(n, res) \
case n:                               \
return res;                         \

std::string numString[] = {
        "",
        "uno ",
        "dos ",
        "tres ",
        "cuatro ",
        "cinco ",
        "seis ",
        "siete ",
        "ocho ",
        "nueve "
};

std::string tenthsString[] = {
        "",
        "dieci",
        "veinti",
        "treinta y ",
        "cuarenta y ",
        "cincuenta y ",
        "sesenta y ",
        "setenta y ",
        "ochenta y ",
        "noventa y "
};

std::string hundsString[] = {
        "-",
        "ciento ",
        "doscientos ",
        "trescientos ",
        "cuatrocientos ",
        "quinientos ",
        "seiscientos ",
        "setecientos ",
        "ochocientos ",
        "novecientos "
};

std::string thousString[] = {
        "",
        "mil ",
        "millones ",
        "millardos ",
        "billones ",
        "trillones ",
};

std::string algorithm(uint64_t n);
std::string hundsException(uint64_t n);
std::string thousException(uint64_t n);

int main(int argc, char** argv){
    if (argc > 1){
        try {
            std::string input(argv[1]);
            if (input[0] == '-'){
                std::cout << "Enter a non negative number!\n";
                return 1;
            }
            uint64_t n = std::stoul(input);
            std::cout << n << ": " << algorithm(n) << '\n';
        } catch (std::invalid_argument&){
            std::cout << "Incorrect number format!\n";
            return 1;
        } catch (std::out_of_range&){
            std::cout << "Requested number out of range!\n";
            return 1;
        };
    } else {
        std::cout << "Please input number as parameter!\n";
        return 1;
    }
    return 0;
}

std::string algorithm(uint64_t n){
    if (n == 0)
        return "Cero";
    std::vector<uint64_t> thous;
    std::string output;
    //emplace thousands into vector
    thous.emplace_back(n % 1000);
    while ((n /= 1000) > 0)
        thous.emplace_back(n % 1000);

    for (uint64_t i = 0; i < thous.size(); i++){
        if (thous[i] == 0)
            continue;

        uint8_t k = 0;
        std::string tmpOut;

        if (thous[i] == 1 && i != 0){
            if (i == 1){
                output.insert(0, thousString[i]);
                continue;
            }
            else if (i == 3){
                output.insert(0, thousString[i].erase(thousString[i].find('s')));
                output.insert(0, "un ");
                continue;
            } else {
                output.insert(0, thousString[i].erase(thousString[i].find("es")));
                output.insert(0, "un ");
                continue;
            }
        }
        output.insert(0, thousString[i]);

        if (!(tmpOut = hundsException(thous[i] % 100)).empty()){
            output.insert(0, tmpOut);
            thous[i] /= 100;
            thous[i] *= 100;
        }
        if (!(tmpOut = thousException(thous[i])).empty()){
            output.insert(0, tmpOut);
            thous[i] = 0;
        }

        output.insert(0, numString[thous[i] % 10]);
        while ((thous[i] /= 10) > 0) {
            switch (k) {
                case 0:
                    output.insert(0, tenthsString[thous[i] % 10]);
                    break;
                case 1:
                    output.insert(0, hundsString[thous[i] % 10]);
                    break;
                default:
                    output.insert(0, "ERROR");
            }
            k++;
        }
    }

    return output;
}

std::string hundsException(uint64_t n){
    switch (n) {
        NUM_EXCEPTION(10, "diez ")
        NUM_EXCEPTION(11, "once ")
        NUM_EXCEPTION(12, "doce ")
        NUM_EXCEPTION(13, "trece ")
        NUM_EXCEPTION(14, "catorce ")
        NUM_EXCEPTION(15, "quince ")
        NUM_EXCEPTION(20, "veinte ")
        default:
            return "";
    }
}

std::string thousException(uint64_t n){
    switch (n) {
        NUM_EXCEPTION(100, "cien ")
        default:
            return "";
    }
}