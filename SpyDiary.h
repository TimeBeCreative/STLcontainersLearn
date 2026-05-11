#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>

struct WithinRange {

    int max;
    int min;

    WithinRange(int minValue, int maxValue) : min(minValue), max(maxValue) {}

    bool operator()(int day) const {
        return day >= min && day <= max; 
    }
};

class SpyDiary {
    private:

    public:
    std::set<int> spyImporatantDays = {3, 8, 10, 18, 30};


    void countEventsInRange(int start, int end) {
        WithinRange checker(start, end);

        int result = std::count_if(spyImporatantDays.begin(), spyImporatantDays.end(), checker);
        std::cout << "Events analysis..."<< std::endl;
        std::cout << "In range: from " << start << " to " << end << std::endl;
        std::cout << "Count of important events: " << result<< std::endl;

    }

};