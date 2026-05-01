//
// Created by newvi on 01.05.2026.
//
#pragma once
#include <array>
#include <iostream>
#ifndef STLCONTAINERSLEARN_SPYARSENAL_H
#define STLCONTAINERSLEARN_SPYARSENAL_H
class EncryptionBox;

class SpyArsenal {
public:

    SpyArsenal();
    ~SpyArsenal();
    EncryptionBox* encryptionBox;

    std::array<char, 26> standardAlphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                  'y', 'z'};

    std::array<char, 26> spyAlphabet{};

    int shiftKey = 3;
};



#endif //STLCONTAINERSLEARN_SPYARSENAL_H