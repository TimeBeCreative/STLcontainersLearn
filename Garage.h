#pragma once
#include <map>
#include <string>
#include <array>
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
   
};