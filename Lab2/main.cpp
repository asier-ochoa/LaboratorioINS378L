//ENUNCIADO: Cadena mas larga
//PARTICIPANTES: 1101331 Asier Ochoa ; Yeuris Terrero | 1099399 ; Carlos Garcia | 1101629 ; Miguel Angel | 1100685
//FECHA:19/05/22

#include <iostream>
#include <cstdlib>
#include <cstring>

struct guest{ // DON'T USE VECTORS, BOY
    unsigned int num;
    unsigned int* list;
    size_t size;
    size_t elements;

    void expand();

    guest(): num(0), list(new unsigned int[1]), size(1), elements(1) {list[0] = num;}
    guest(const guest& other)
            : num(other.num), list(new unsigned int[other.size]), size(other.size), elements(other.elements)
    {memcpy(list, other.list, size);}
    ~guest() {delete[] list;}

    void makeList();

    bool operator>(const guest& rhs){return this->elements > rhs.elements;}
    friend std::ostream &operator<<(std::ostream &os, const guest &guest);
};

template <size_t S>
unsigned int findLongest(guest* list);

void guest::expand() {
    auto* tmp = new unsigned int[size * 2];
    memcpy(tmp, list, size * sizeof(unsigned int));
    size *= 2;
    delete[] list;
    list = tmp;
}

void guest::makeList() {
    while (num != 4){
        elements++;
        if (elements > size){ //Bound checking to have enough memory
            expand();
        }
        num = (num % 2 == 0 ? num /= 2 : num = num * 3 + 1);
        list[elements - 1] = num;
    }
}

std::ostream &operator<<(std::ostream &os, const guest &guest) {
    for (int i = 1; i < guest.elements; ++i) {
        os << guest.list[i] << '<';
    }
    os << '\b';
    return os;
}

template <size_t S>
unsigned int findLongest(guest* list) {
    unsigned int longest = 0;
    for (int i = 1; i < S; ++i) {
        longest = (list[i] > list[longest] ? i : longest);
    }
    return longest;
}

int main(const int argc, const char** argv){
    guest party[90]; //calls constructor on every member (BRUH)
    for (int i = 10; i <= 99; ++i) {
        party[i - 10].num = i;
        party[i - 10].makeList();
        std::cout << "Guest " << i << ':' << party[i - 10] << '\n';
    }
    unsigned int longest = findLongest<90>(party);
    std::cout << "\nLongest chain is " << longest + 10 << ": " << party[longest] << '\n';
    return 0;
}