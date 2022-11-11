#include <iostream>

//ENUNCIADO: Los floreros del Salvador 
//Hace algún tiempo Salvador compró 100 floreros para venderlos en un mercadillo. La semana pasada, después de haber vendido algunos de ellos en los días anteriores, tenía los floreros ordenados en seis filas, con el mismo número de unidades en cada una de ellas. En esta semana vendió ocho floreros y en la actualidad tiene los que le quedan ordenados en 11 filas, números con el mismo número de floreros en cada una.
//¿Cuántos floreros tiene salvador para vender todavía?

//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel

//FECHA: 10/11/22

#include <iostream>

int main() { for (int i = 100 - 1; i > 0; i--) { if ((i % 6) == 0) { if ((i - 8) % 11 == 0) { std::cout << "Si salvador vendio " << 100 - i << " en la primera venta. Tendria al final " << i-8 << ".\n";}}}
    return 0;
}
