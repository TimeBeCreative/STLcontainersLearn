//
// Created by newvi on 01.05.2026.
//
#include <iostream>
#include <string>
#include "SpyController.h"
#include "EncryptionBox.h"


void SpyController::MakeAction() {
    std::cout << "Welcome back, dear spy! Choose what to do: " << std::endl;
    std::cout << "Encrypt the alphabet - git enc a" << std::endl;

    std::string spyInput;
    std::getline(std::cin, spyInput);

    if (spyInput == "git enc a") {
        std::cout << "Please enter a shift key: " << std::endl;
        std::string shiftKey;
        std::cin >> shiftKey;
        spyArsenal.encryptionBox->shiftAlphabetElements(spyArsenal.standardAlphabet, spyArsenal.spyAlphabet, std::stoi(shiftKey));

    }
    else {
        std::cout << "?" << std::endl;
    }
}