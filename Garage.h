#pragma once
#include <map>
#include <string>
#include <array>
#include <algorithm>
#include "Limousine.h"

struct TaxApplier {
   double taxRate;

   TaxApplier(double rate) : taxRate(rate) {}

   void operator()(double &price) const { //& to change
      price += price * taxRate;
   }
};

class Garage {
    private:

    void printPrices() {
      for (double p : limoPrices) {
         std::cout << p << "$ " <<std::endl;
      }
    }

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

   std::deque<double> limoPrices {
      10000.3,
      1453.124,
      21.35,
      235.0
   };

   void applyMafiaTax() {
      std::cout << "Prices before tax: "<< std::endl;
      printPrices();

      TaxApplier mafiaTax(0.15);
      std::for_each(limoPrices.begin(), limoPrices.end(), mafiaTax);

      std::cout << "Prices after Mafia Tax 15%: " << std::endl;
      printPrices();

   }

   
};

