//
// Created by newvi on 01.05.2026.
//
#include <iostream>
#include <string>
#include <deque>
#include "SpyController.h"
#include "EncryptionBox.h"


void SpyController::MakeAction() {
    std::cout << "Welcome back, dear spy! Choose what to do: " << std::endl;
    std::cout << "Encrypt the alphabet - git enc a" << std::endl;
    std::cout << "Add new mission codes to system - git add mcodes" << std::endl;
    std::cout << "Unblock the door - git door unblock" << std::endl;

    std::string spyInput;
    std::getline(std::cin, spyInput);

    if (spyInput == "git enc a") {
        std::cout << "Please enter a shift key: " << std::endl;
        std::string shiftKey;
        std::cin >> shiftKey;
        spyArsenal.encryptionBox->shiftAlphabetElements(spyArsenal.standardAlphabet, spyArsenal.spyAlphabet, std::stoi(shiftKey));

    }
    else if (spyInput == "git add mcodes") {
        std::cout << "Please enter how many new codes: " << std::endl;
        std::string newCodeCount;
        std::cin >> newCodeCount;

        std::cout << "Please enter a placement position of new codes: " << std::endl;
        std::string placementPosition;
        std::cin >> placementPosition;


        std::vector<std::string> toAddTaskCodes{};
        std::cout << "Please enter arrived toAddTaskCodes: " << std::endl;
        for (int i = 0; i < std::stoi(newCodeCount); i++) {
            std::string code;
            std::cin >> code;
            toAddTaskCodes.push_back(code);
        }
        std::cout << "System processing the data right now..." << std::endl;

        std::cout << "Take a look what was before: " << std::endl;
        for (const auto & missionTasksCode : spyArsenal.missionTasksCodes) {
            std::cout << missionTasksCode << ", " << std::endl;
        }

        spyArsenal.addMissionTasksCodes(spyArsenal.missionTasksCodes, toAddTaskCodes, std::stoi(placementPosition));

    }
    else if (spyInput == "git door unblock") {

        spyArsenal.doorUnblock();

    }
    else {
        std::cout << "?" << std::endl;
    }
}

