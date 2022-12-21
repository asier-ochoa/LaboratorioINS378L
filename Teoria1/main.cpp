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

//PARTICIPANTES: Yeuris Terrero 1099399

//FECHA: 20/12/22

#include<iostream>
#include<string>
using namespace std;


int main()
{
    int num = 22583;
    //cout<<"Ingrese valor: ";
    //cin>>num;

    string uno[] = {"", "uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
    string diez[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    string cien[] = {"", "cien", "dosciento", "tresciento", "cuatrosciento", "quiniento", "seisciento", "seteciento", "ochociento", "noveciento"};
    string result = "";
    string result2 = "";
    string result3 = "";

    int million = num/1000000;

    for (size_t i = 1; i < 1000; i++)
    {
        int hundreds = i%1000;
        result = cien[hundreds/100];
        result.append(" ").append(diez[(hundreds%100)/10]);
        result.append(" y ").append(uno[hundreds%10]);

        cout << result << endl;
    }
    
    /*if (num < 1000)
    {
        int hundreds = num%1000;

        result = cien[hundreds/100];
        result.append(" ").append(diez[(hundreds%100)/10]);
        result.append(" y ").append(uno[hundreds%10]);

        cout << result;
        return 0;
    }

    if (num >= 1000 || num < 1000000)
    {
        int thousands = (num/1000)%1000;

        result2 = cien[thousands/100];
        result2.append(" ").append(diez[thousands%100]);
        result2.append(" y ").append(uno[thousands%10]);
        result2.append(" mil ");

        cout << result2;
        return 0;
    }
    
    
    result3 = cien[hundreds/100];
    result3.append(" ").append(diez[hundreds%100]);
    result3.append(" y ").append(uno[hundreds%10]);
    result3.append(" millon ");*/
    
    cout<< "Error";

    return 0;
}