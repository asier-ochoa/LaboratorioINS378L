#include <cstdio>

int main() {
    int flowers = 100;
    int rows = 6;

    int soldNow;
    for (int i = flowers / rows; i > 0; i--){
        soldNow = flowers - i * rows;
        printf("If %d flowers per row, %d were sold", i, soldNow);
        soldNow += 8;
        if ((flowers - soldNow) % 11 == 0)
            printf(" | yup, he has %d flowers\n", flowers - soldNow);
        else
            printf(" | FUCK YOU, %d are left out\n", (flowers - soldNow) % 11);
    }
    return 0;
}