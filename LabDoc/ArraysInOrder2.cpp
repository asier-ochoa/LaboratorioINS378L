
#include <iostream>

int main(){
    int a[] = {1,4,4,5};
    int b[] = {2,3,6};
    int sizeA = 4, sizeB = 3;

    // {1,4,4,5} {2,3,6} -> {1,2,3,4,4,5,6}
    //Composed array
    auto* c = new int[sizeA + sizeB];
    int ai = 0, bi = 0, ci = 0;
    while (ci < sizeA + sizeB){
        //bounds check
        if (ai == sizeA){
            c[ci] = b[bi];
            break;
        }
        if (bi == sizeB) {
            c[ci] = a[ai];
            break;
        }

        //Assigning to composed array
        if (a[ai] < b[bi]){
            c[ci] = a[ai];
            ai++; ci++;
        } else {
            c[ci] = b[bi];
            bi++; ci++;
        }
    }

    for (int i = 0; i < sizeA + sizeB; i++){
        std::cout << c[i] << ',';
    }
    std::cout << "\b \n";
}