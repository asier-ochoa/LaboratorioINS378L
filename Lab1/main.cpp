//ENUNCIADO: Los floreros del Salvador 
//Hace algún tiempo Salvador compró 100 floreros para venderlos en un mercadillo. La semana pasada, después de haber vendido algunos de ellos en los días anteriores, tenía los floreros ordenados en seis filas, con el mismo número de unidades en cada una de ellas. En esta semana vendió ocho floreros y en la actualidad tiene los que le quedan ordenados en 11 filas, números con el mismo número de floreros en cada una.
//¿Cuántos floreros tiene salvador para vender todavía?

//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

//FECHA: 10/11/22

#include <cstdio>
int main() {for (int i = 100 / 6; i > 0; i--) ((100 - ((100 - i * 6) + 8)) % 11 == 0 ? printf("If %d flowers per row, %d sold | Has %d flowers left\n", i, 100 - i * 6, 100 - ((100 - i * 6) + 8)) : 0);}
//int main() {
//    int flowers = 100;
//    int rows = 6;
//
//    int soldNow;
//    for (int i = flowers / rows; i > 0; i--) {
//        soldNow = flowers - i * rows;
//        printf("If %d flowers per row, %d were sold", i, soldNow);
//        soldNow += 8;
//        if ((flowers - soldNow) % 11 == 0)
//            printf(" | yup, he has %d flowers\n", flowers - soldNow);
//        else
////            printf(" | nope, %d are left out\n", (flowers - soldNow) % 11);
//            printf("\n");
//    }
//    return 0;
//}