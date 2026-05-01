//
// Created by newvi on 01.05.2026.
//

#include "EncryptionBox.h"

EncryptionBox::EncryptionBox() = default;
EncryptionBox::~EncryptionBox() = default;

/*
template <typename T, size_t S>
void EncryptionBox::shiftAlphabetElements(std::array<T, S>& array, std::array<T,S>& spyAlphabet, int shift) {


    auto it = spyAlphabet.begin();
    for (auto i = 0; i < S; i++) {
        //  if (array[i+shift] < S) {
        *it = array[(i + shift) % S]; //module
        //}
        /* else {
             *it = array[i + shift - S];
         }
        ++it;


    }

    std::cout << "HAHA! 😈 Pzks chnu" << std::endl;

    for (auto i = 0; i < 26; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (auto i = 0; i < 26; i++) {
        std::cout << spyAlphabet[i] << " ";
    }
    std::cout << std::endl;

};




*/




/*

template <typename T, size_t S>
void shiftAlphabetElements(std::array<T, S>& array, std::array<T,S>& spyAlphabet, int shift) {


    auto it = spyAlphabet.begin();
    for (auto i = 0; i < S; i++) {
        //  if (array[i+shift] < S) {
        *it = array[(i + shift) % S]; //module
        //}

++it;


    }

std::cout << "HAHA! 😈 Pzks chnu" << std::endl;

for (auto i = 0; i < 26; i++) {
    std::cout << array[i] << " ";
}
std::cout << std::endl;

for (auto i = 0; i < 26; i++) {
    std::cout << spyAlphabet[i] << " ";
}
std::cout << std::endl;

};
*/
