#include <iostream>
#include <array>

//1. Зсув елементів: Реалізувати функцію для зсуву елементів масиву
//std::array на задану кількість позицій за годинниковою стрілкою.
//шифр цезаря
std::array<char, 26> standardAlphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                  'y', 'z'};

int shiftKey = 2;


template <typename T, size_t S>
void shiftElements(std::array<T, S>& array, int shift) {

    std::array<T, S> newAlphabet{};
    auto it = newAlphabet.begin();
        for (auto i = 0; i < S; i++) {
          //  if (array[i+shift] < S) {
                *it = array[(i + shift) % S]; //module
            //}
           /* else {
                *it = array[i + shift - S];
            }*/
            ++it;


    }

    for (auto i = 0; i < 26; i++) {
        std::cout << newAlphabet[i] << " ";
    }
    std::cout << std::endl;

};

int main() {
    for (auto i = 0; i < 26; i++) {
        std::cout << standardAlphabet[i] << " ";
    }
    std::cout << std::endl;

    shiftElements(standardAlphabet, 3);








    return 0;
}

