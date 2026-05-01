//
// Created by newvi on 01.05.2026.
//
#pragma once
#include <vector>
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
};



#endif //STLCONTAINERSLEARN_SPYARSENAL_H