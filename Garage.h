#pragma once
#include <map>
#include <string>
#include <array>
#include <algorithm>
#include "Limousine.h"

class Garage {
    private:

    public:

 //   Limousine limousine;

    std::map<int, Limousine> limousinesInGarage {}; //{
       // {1, {"limoPower", 8}},
      //  {2, {"limoDanger", 3}}
   // };

   std::array<std::string, 20> limousinesNames{
      "LimoPower",
      "Limonade",
      "SuperDuperLimoTrupper",
      "FantasticLimo",
      "LimoMasteryFantasterys",
      "Lim",
      "Limdy",
      "Lililu",
      "LimoDanger",
      "LimoluckyCar",
      "RockBeastLiMonster",
      "L0",
      "OverLimLord",
      "UnderLimo",
      "LimoFairyTale",
      "LimTeam",
      "Limousinery",
      "LimoDinner",
      "LimoSpy",
      "Limonade",
   };

   template <typename T, size_t S>
   void sortCarNames(std::array<T, S>& limoNames) {
      std::sort(limoNames.begin(), limoNames.end(),
      [](const T& a, const T& b) {
         return a.length() > b.length();
      }
   );
   }

   
};