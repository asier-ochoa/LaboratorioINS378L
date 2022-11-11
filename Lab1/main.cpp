#include <iostream>

int main() {
    int contador=0;
    int cantidad=100;
    for(int i=cantidad-1; i>0; i--){
        
        if((i%6)==0){
            if((i-8)%11==0){
             contador=+1;
            }
            if(contador==1){
                std::cout << "Salvador podría tener " << i;
            }
            else if(contador==2){
               std::cout << " ó " << i <<"."; 
            }
        }
    }
    return 0;
}
