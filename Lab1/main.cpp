int main() {
    int cantidad=100;
    for(int i=cantidad-1; i>0; i--){
        if((i%6)==0){
            if((i-8)%11==0){
                std::cout << "Sí salvador venido "<< 100-i<<" en la primera venta. Tendría al final" << i;
            }
        }
    }
    return 0;
}
