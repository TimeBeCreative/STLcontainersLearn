//
// Created by newvi on 01.05.2026.
//
#include <iostream>
#include <string>
#include <deque>
#include "SpyController.h"
#include "EncryptionBox.h"


void SpyController::MakeAction() {
      std::cout << "///////////////////////////////////////////////////////" << std::endl;
    std::cout << "Welcome back, dear spy! Choose what to do: " << std::endl;
      std::cout << "///////////////////////////////////////////////////////" << std::endl;
    std::cout << "Encrypt the alphabet = git enc a" << std::endl;
    std::cout << "Add new mission codes to system = git add mcodes" << std::endl;
    std::cout << "Unblock the door = git door unblock" << std::endl;

    std::cout << "Limousine runaway, info (1) = git limo" << std::endl;
    std::cout << "Look which limousine is the best =  git -l best" << std::endl;
    std::cout << "Apply tax (task 3) = git tax"<< std::endl;
    std::cout << "Count impoerant events in range (task 4) = git count e" << std::endl;

    std::cout << "///////////////////////////////////////////////////////" << std::endl;
    

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
    else if (spyInput == "git limo") {
        std::cout << "There are 20 limousines (map) in the garage. Let`s look at them." << std::endl;
        spyArsenal.limousinesInitialisation();

        std::cout<<"Full info:" << std::endl;

        auto it = spyArsenal.garage.limousinesInGarage.begin();

        while (it != spyArsenal.garage.limousinesInGarage.end()) {
             std::cout << "id: " <<it->first << ", "
            <<"Name: " << it->second.name << ", "
            <<"Number of wheels: " << it->second.numberOfWheels << std::endl;
            ++it;
        }

       /* for (const auto& pair : spyArsenal.garage.limousinesInGarage) {
            //pair first = id
            //pair second = Limousine
            std::cout << "id: " <<pair.first << ", "
            <<"Name: " << pair.second.name
            <<"Wheels: " << pair.second.numberOfWheels << std::endl;
        }*/
    }
    else if (spyInput == "git -l best") {
        std::cout << "We have 20 limousines names in the garage." << std::endl;
        std::cout << "More letters in name = better limousine." << std::endl;
        std::cout << "///////////////////////////////////////////////////////" << std::endl;
        //cout before sort
        auto it = spyArsenal.garage.limousinesNames.begin();

        while (it != spyArsenal.garage.limousinesNames.end()) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << "///////////////////////////////////////////////////////" << std::endl;

        std::cout << "Now look sorted names for conviniency: "<< std::endl;
        spyArsenal.garage.sortCarNames(spyArsenal.garage.limousinesNames);
         //cout after sort
        auto it2 = spyArsenal.garage.limousinesNames.begin();

        while (it2 != spyArsenal.garage.limousinesNames.end()) {
            std::cout << *it2 << std::endl;
            ++it2;
        }

        std::cout << "///////////////////////////////////////////////////////" << std::endl;


    }
    else if (spyInput == "git tax") {
        spyArsenal.garage.applyMafiaTax();
    }
    else if (spyInput == "git count e") {
        std::string start;
        std::cout << "Please write start: " << std::endl; 
        std::cin>>start;

        std::string end;
        std::cout << "Please write end: " << std::endl;
        std::cin>>end;

        spyArsenal.diary.countEventsInRange(stoi(start), stoi(end));
    }
    else {
        std::cout << "?" << std::endl;
    }
}

