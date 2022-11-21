//ENUNCIADO: Cadena mas larga
//PARTICIPANTES: 1101331 Asier Ochoa ; Yeuris Terrero | 1099399 ; Carlos Garcia | 1101629 ; Miguel Angel | 1100685
//FECHA:19/05/22

#include <cstdlib>
#include <cstdio>
#include <cstring>

int main(int argc, char** argv){
    unsigned int prev_k = 0, longest, buf_size, tmp_buf_size = 32;
    unsigned int* buf = NULL; //Initialize with null so empty free doesn't segfault
    unsigned int* tmp_buf = (unsigned int*)malloc(sizeof(int) * 32);

    //check term params
    unsigned int choosen_n = 0;
    if (argc == 2){
        int i = 0;
        while (argv[1][i] != '\0'){
            if (!(argv[1][i] > '0' && argv[1][i] < '9')){
                printf("Error: incorrect argument format\n");
                return 1;
            }
            i++;
        }
        choosen_n = atoi(argv[1]);
    }

    for (unsigned int i = (argc != 2 ? 10 : choosen_n); i < (argc != 2 ? 100 : choosen_n + 1); i++){
        unsigned int n = i, k = 0;

        printf("Guest %u: ", n);
        while (n != 4){
            n = (n % 2 == 0 ? n / 2 : n * 3 + 1); //The actual logic
            printf("%u<", n);
            if (k > tmp_buf_size - 1){ //Reallocate and swap buffer if out of memory
                unsigned int* tmp = tmp_buf;
                tmp_buf_size *= 2;
                tmp_buf = (unsigned int*)malloc(sizeof(int) * tmp_buf_size);
                memcpy(tmp_buf, tmp, tmp_buf_size / 2);
                free(tmp);
            } else
                tmp_buf[k] = n;
            k++;
        }
        if (k > prev_k){
            prev_k = k;
            longest = i;

            //Save tmp buffer if it's the new longest and allocate new buffer
            free(buf);
            buf = tmp_buf;
            buf_size = tmp_buf_size;

            tmp_buf_size = 32;
            tmp_buf = (unsigned int*)malloc(sizeof(int) * tmp_buf_size);
        }
        printf("\b \n");
    }

    if (argc != 2) {
        printf("\nLongest chain is #%u with %u entries: ", longest, prev_k);
        for (int i = 0; i < prev_k; i++)
            printf("%u<", buf[i]);
        printf("\b \n");
    }
    free(tmp_buf);
    free(buf);
}

//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//
//struct guest{ // DON'T USE VECTORS, BOY
//    unsigned int num;
//    unsigned int* list;
//    size_t size;
//    size_t elements;
//
//    void expand();
//
//    guest(): num(0), list(new unsigned int[1]), size(1), elements(1) {list[0] = num;}
//    guest(const guest& other)
//            : num(other.num), list(new unsigned int[other.size]), size(other.size), elements(other.elements)
//    {memcpy(list, other.list, size);}
//    ~guest() {delete[] list;}
//
//    void makeList();
//
//    bool operator>(const guest& rhs){return this->elements > rhs.elements;}
//    friend std::ostream &operator<<(std::ostream &os, const guest &guest);
//};
//
//template <size_t S>
//unsigned int findLongest(guest* list);
//
//void guest::expand() {
//    auto* tmp = new unsigned int[size * 2];
//    memcpy(tmp, list, size * sizeof(unsigned int));
//    size *= 2;
//    delete[] list;
//    list = tmp;
//}
//
//void guest::makeList() {
//    while (num != 4){
//        elements++;
//        if (elements > size){ //Bound checking to have enough memory
//            expand();
//        }
//        num = (num % 2 == 0 ? num /= 2 : num = num * 3 + 1);
//        list[elements - 1] = num;
//    }
//}
//
//std::ostream &operator<<(std::ostream &os, const guest &guest) {
//    for (int i = 1; i < guest.elements; ++i) {
//        os << guest.list[i] << '<';
//    }
//    os << '\b';
//    return os;
//}
//
//template <size_t S>
//unsigned int findLongest(guest* list) {
//    unsigned int longest = 0;
//    for (int i = 1; i < S; ++i) {
//        longest = (list[i] > list[longest] ? i : longest);
//    }
//    return longest;
//}
//
//int main(const int argc, const char** argv){
//    guest party[90]; //calls constructor on every member (BRUH)
//    for (int i = 10; i <= 99; ++i) {
//        party[i - 10].num = i;
//        party[i - 10].makeList();
//        std::cout << "Guest " << i << ':' << party[i - 10] << '\n';
//    }
//    unsigned int longest = findLongest<90>(party);
//    std::cout << "\nLongest chain is " << longest + 10 << ": " << party[longest] << '\n';
//    return 0;
//}