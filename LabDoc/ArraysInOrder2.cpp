//ENUNCIADO:
//2 arreglos ordenados se combinan
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399

#include <algorithm>
#include <iostream>
#include <vector>

//Validates a comma separated list of numbers was given and sorts it if unsorted
int* arrayInput(std::string& input, int* size) {
    char prev = '\0';
    std::vector<int> array;
    for (const auto& c: input){
        //Initial condition
        if (prev == '\0' || prev == ','){
            if (c < '0' || c > '9'){
                return nullptr;
            }
            prev = c;
        } else if (prev >= '0' && prev <= '9'){
            if ((c < '0' || c > '9') && c != ','){
                return nullptr;
            }
            prev = c;
        } else {
            return nullptr;
        }
    }
    //Validate that list ends in a number
    if (input.back() == ',') {
        return nullptr;
    }

    size_t pos = 0;
    std::string token;
    while ((pos = input.find(',')) != std::string::npos) {
        token = input.substr(0, pos);
        array.emplace_back(atoi(token.c_str()));
        input.erase(0, pos + 1);
    }
    array.emplace_back(atoi(input.c_str()));

    std::sort(array.begin(), array.end());
    *size = array.size();
    auto* ret = new int[array.size()];
    for (int i = 0; i < array.size(); i++){
        ret[i] = array[i];
    }
    return ret;
}

int main(){
    std::string input;
    int *a = nullptr, *b = nullptr;
    int sizeA, sizeB;
    while (a == nullptr){
        std::cout << "Input a first list of numbers separated by commas:\n";
        std::cin >> input;
        a = arrayInput(input, &sizeA);
        if (a == nullptr){
            std::cout << "Invalid Input\n";
        }
        input.clear();
    }

    while (b == nullptr){
        std::cout << "Input a second list of numbers separated by commas:\n";
        std::cin >> input;
        b = arrayInput(input, &sizeB);
        if (b == nullptr){
            std::cout << "Invalid Input\n";
        }
        input.clear();
    }

    auto* c = new int[sizeA + sizeB];
    int ai = 0, bi = 0, ci = 0;
    while (ci < sizeA + sizeB){
        //bounds check
        if (ai == sizeA){
            c[ci] = b[bi];
            bi++; ci++;
        } else if (bi == sizeB) {
            c[ci] = a[ai];
            ai++; ci++;
        } else {
            //Assigning to composed array
            if (a[ai] < b[bi]){
                c[ci] = a[ai];
                ai++; ci++;
            } else {
                c[ci] = b[bi];
                bi++; ci++;
            }
        }
    }

    std::cout << "Combined array:\n";
    for (int i = 0; i < sizeA + sizeB; i++){
        std::cout << c[i] << ',';
    }
    std::cout << "\b \n";
}