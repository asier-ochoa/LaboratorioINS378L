//ENUNCIADO: Flores de Salvador
//PARTICIPANTES: 1101331 Ochoa Asier
//FECHA: 10/11/22

#include <cstdio>
int main() {for (int i = 100 / 6; i > 0; i--) ((100 - ((100 - i * 6) + 8)) % 11 == 0 ? printf("If %d flowers per row, %d sold | Has %d flowers left\n", i, 100 - i * 6, 100 - ((100 - i * 6) + 8)) : 0);}
//    int flowers = 100;
//    int rows = 6;
//
//    int soldNow;
//    for (int i = flowers / rows; i > 0; i--){
//        soldNow = flowers - i * rows;
//        printf("If %d flowers per row, %d were sold", i, soldNow);
//        soldNow += 8;
//        if ((flowers - soldNow) % 11 == 0)
//            printf(" | yup, he has %d flowers\n", flowers - soldNow);
//        else
//            printf(" | nope, %d are left out\n", (flowers - soldNow) % 11);
//    }
//    return 0;