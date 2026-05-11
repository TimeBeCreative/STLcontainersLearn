#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

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

    /* 5. Задано std::map<st::string, int>, яка описує предмети та їхню кількість
(уявний склад). Використовуючи алгоритми, написати функцію, яка
покаже елементи, кількість яких більша 100.

🔝Джерело (конверт), дохід (всередині конверту)*/

    std::map<std::string, int> spyIncomes = {
        {"University mission", 50 },
        {"Icecream breack", 203},
        {"Hacking 176425 system", 350},
        {"Volunteering", 0}
    };

    void showHighIncomes() {
        std::cout << "Incomes > 100" << std::endl;

        std::for_each(spyIncomes.begin(), spyIncomes.end(),
    [](const std::pair<std::string, int>& item) {
        if (item.second > 100) {
            std::cout << "Source of the income: " << item.first << "; Amount: " << item.second << std::endl;
        }
    });
    }

    /*7. Створити std::vector<int>. Одночасно обчислити суму елементів та
знайти середнє значення (НЕ використовувати std::accumulte).

🔝Успіх шпигуна, статистика. 100 = успіх, 0 = провал.*/

    void checkTaskAnalysis()  {
        std::vector<int> taskAnalysis = {
        70, 50, 90, 100, 34
    };

    int sum = 0;
    std::for_each(taskAnalysis.begin(), taskAnalysis.end(), [&sum](int value) {

        sum += value;
    });

    double average = 0;
    if (!taskAnalysis.empty()) {
        average = static_cast<double>(sum) / taskAnalysis.size();
    }

    std::cout << "Spy tasks statistics: "<< std::endl;
    std::cout << "All success sum: " << sum << std::endl;
    std::cout << "Average success level: " << average << "%" << std::endl;

    if (average >= 50.0) {
        std::cout << "Status: productive output" << std::endl;
    } else {
        std::cout << "Status: spy, work more." << std::endl;
    }
    }
    

};