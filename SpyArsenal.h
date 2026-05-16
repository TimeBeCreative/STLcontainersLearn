//
// Created by newvi on 01.05.2026.
//
#pragma once
#include <vector>
#include <array>
#include <iostream>
#include <deque>
#include <random>
#include <list>
#include <algorithm>
//#include <windows.h>
#include "SpyDiary.h"
#include "Garage.h"

class EncryptionBox;


class SpyArsenal {


public:

    SpyArsenal();
    ~SpyArsenal();
    EncryptionBox* encryptionBox;
    Garage garage;
    SpyDiary diary;

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
    void addMissionTasksCodesOld(std::vector<T>& oldTaskCodes, std::vector<T>& toAddTaskCodes, int placementPosition) {
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

    template  <typename T>
    void addMissionTasksCodes(std::vector<T>& oldTaskCodes, std::vector<T>& toAddTaskCodes, int placementPosition) {
        if (placementPosition > oldTaskCodes.size()) placementPosition = oldTaskCodes.size();
        oldTaskCodes.insert(oldTaskCodes.begin() + placementPosition, toAddTaskCodes.begin(), toAddTaskCodes.end());

        std::cout << "Success!" << std::endl;
        for (const auto& code : oldTaskCodes)  {
            std::cout <<  code << ", " << std::endl;
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
    void deleteCentralListElement(std::list<T>& myList) {
        if (myList.empty()) return;
        size_t  size = myList.size();
        size_t center = size / 2;
        auto it = myList.begin();
        if (size % 2 == 0) {
            std::advance(it, center - 1);
            auto itEnd = it;
            std::advance(itEnd, 2);

            myList.erase(it, itEnd);
        }
        else {
            std::advance(it, center);
            myList.erase(it);

        }
    }

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



   /* 1. Створити std::list<int> на 20 елементів. Заповнити список рандомно
(випадковим чином). Написати функцію bool isOdd(int n) та
використати std::remove_if для обробки списку.

🔝Шпигуну потрібно лише те, що ділиться на 2. Лімузини, колеса лімузина. Список колес (кількості колес кожної машини) машин. */

int genRandWheelsCount() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, 14);
    return dis(gen);
}

struct isOdd {
    bool operator()(int n) const {
        return n % 2 != 0;
    }
};

template <typename T>
void deleteOdd(std::list<T>& list) {
    list.erase(std::remove_if(list.begin(), list.end(), //remove зсуває, erase прибирає
        isOdd()), list.end());

}

template <typename T>
void coutList(std::list<T>& list) {
    for (int n : list) std::cout << n << " ";
    std::cout << "\n\n";
}


//void filterCarWithEvenNumberOfWheels() {
//template <typename T>
void limousinesInitialisation() {

    std::list<int> wheelsList;
    for(int i = 0; i < 20; ++i) {

       int notListWheels = genRandWheelsCount();
       wheelsList.push_back(notListWheels);

       
       //list no [i]

        garage.limousinesInGarage[i] = {std::string("Limo") + garage.limousinesNames[i], notListWheels};
    };

    std::cout << "System is working..." << std::endl;
    std::cout << "List of how many wheels has each limo:" << std::endl;
    coutList(wheelsList);
    }

    
 //Limousine limo = {std::string("Limo") + garage.limousinesNames[i], wheelsList[i]};


 /*8. Задано текстовий рядок. Написати функцію, для підрахунку кількості
голосних літер в рядку. (Використовуючи алгоритми).

🔝голосних менше 10 -> не іти на таємний мітинг, більше 10 -> іти*/

    void analyzeSecretMessage(const std::string& message) {
        std::cout << "Analysis of secret message..."<< std::endl;
        auto isVowel = [](char c) {
            char low = std::tolower(static_cast<unsigned char>(c));
            return low == 'a' ||  low == 'e' || low == 'i' || low == 'o' || low == 'u' || low == 'y';
        };
        int count = std::count_if(message.begin(), message.end(), isVowel);

        std::cout << "Vowel letters count: " << count << std::endl;

        if (count > 10) {
            std::cout << "Mafia asks you to come to the secret meeting." << std::endl;
        }
        else {
            std::cout << "Mafia not hosting any meetings this week." << std::endl;
        }

        
    }

};


