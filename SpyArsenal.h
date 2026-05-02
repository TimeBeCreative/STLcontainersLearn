//
// Created by newvi on 01.05.2026.
//
#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <deque>
#include <random>
#include <windows.h>
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


    /////////
    ///
    std::vector<std::string> missionTasksCodes{
        "3801297356287",
        "3809523465",
        "380667435421",
        "380123456789",
        "380987654321",
        "380111111111",
    };

    template <typename T>
    void addMissionTasksCodes(std::vector<T>& oldTaskCodes, std::vector<T>& toAddTaskCodes, int placementPosition) {
        int count = 0; //number
        auto it = oldTaskCodes.begin(); // pointer
        while (it !=  oldTaskCodes.end()) {
            if (count == placementPosition - 2) {
                auto insertIt = oldTaskCodes.begin() + placementPosition;
                for (int i = 0; i < toAddTaskCodes.size(); i++) {
                    insertIt = oldTaskCodes.insert(insertIt, toAddTaskCodes[i]);
                    ++insertIt;
                }
                break;
            }
            ++it;
            ++count;
        }

        std::cout << "Success!" << std::endl;
        for (int i = 0; i < oldTaskCodes.size(); i++) {
            std::cout << oldTaskCodes[i] << ", " << std::endl;
        }
    };


    void doorUnblock() {



        std::cout << "You are standing in front of the new blocked door." << std::endl;
        std::cout << "There are several gates on the door, you need to shoot the middle one." << std::endl;

        std::random_device rd;
        std::mt19937 gen(rd());

        std::vector<std::string> emojis = {
            "😀", "😂", "😎", "😍", "🤔", "👽",
            "🎃", "🌈", "🍕", "🍔", "🍟", "🍦", "🍩", "🍪", "🍫",
        };

        std::uniform_int_distribution<size_t> dist(0, emojis.size() - 1);
        std::uniform_int_distribution<> dSize(1, 5);
        int gatesSize = dSize(gen) * 2;
        std::deque<std::string> gates(static_cast<size_t>(gatesSize), "A");

        auto it = gates.begin();
        while (it != gates.end()) {
            *it = emojis[dist(gen)];
            ++it;
        }


        for (const auto& gate : gates) std::cout << gate << " ";
        std::cout << std::endl;
        deleteCentralDequeElement(gates);
        std::cout << "Central gates are shot!" << std::endl;
        for (const auto& gate : gates) std::cout << gate << " ";
        std::cout << std::endl;


        std::cout << "Inside the central door are runes, you need to shoot central to activate it." << std::endl;
        std::cout << "After activation rune destroys." << std::endl;
        int runesSize = dSize(gen) * 2 + 1;
        std::deque<std::string> runes(static_cast<size_t>(runesSize), "<");


        auto it1 = runes.begin();
        while (it1 != runes.end()) {
            *it1 = emojis[dist(gen)];
            ++it1;
        }

        for (const auto& rune : runes) std::cout << rune << " " ;
        std::cout << std::endl;
        deleteCentralDequeElement(runes);
        std::cout << "Central rune is shot!" << std::endl;
        for (const auto& rune : runes) std::cout << rune << " " ;
        std::cout << std::endl;

    }

#define INCREMENT(number) (number + 1)

    template <typename T>
    void deleteCentralDequeElement(std::deque<T>& deque) {
        size_t size = deque.size();
        size_t center = size / 2; // rounds down without +1
        if (size % 2 == 0) {
            //delete two elements at center
            auto itDelStart = deque.begin() + (center - 1);
            auto itDelEnd = deque.begin() + (center + 1);
            deque.erase(itDelStart, itDelEnd);
        }
        else {
            //delete one element at center
            auto itDel = deque.begin() + center;
            deque.erase(itDel);
        }
    };
};



#endif //STLCONTAINERSLEARN_SPYARSENAL_H