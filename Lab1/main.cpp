//ENUNCIADO: Los floreros del Salvador 
//Hace algún tiempo Salvador compró 100 floreros para venderlos en un mercadillo. La semana pasada, después de haber vendido algunos de ellos en los días anteriores, tenía los floreros ordenados en seis filas, con el mismo número de unidades en cada una de ellas. En esta semana vendió ocho floreros y en la actualidad tiene los que le quedan ordenados en 11 filas, números con el mismo número de floreros en cada una.
//¿Cuántos floreros tiene salvador para vender todavía?

//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Yeuris Terrero 1099399

//FECHA: 14/12/22

#include <cstdio>
int main() {
    for (size_t i = 0; i < 100; i++)
    {
        int semana1 = 100 - i;
        int semana2 = semana1 - 8;
        if (semana1%6 == 0 && semana2%11 == 0)
        {
            printf("Tiene %d floreros\n", semana2);
        }
    }
}