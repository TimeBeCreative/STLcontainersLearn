
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <array>
#include <deque>
#include <string>

//Macros - це мітка, визначена у вихідному коді програми,
//яка замінюється своїм значенням препроцесором перед компіляцією

//Макроси ініціалізуються за допомогою команди препроцесора #define і
//можуть бути скасовані за допомогою команди #undef

//Macro(s)

#define MAX_VALUE 100

#define MAX(a,b) ((a>b?a:b))

#define SQUARE(a) a*a // не правильно вийде
#define RIGHT_SQUARE(a) ((a) * (a)) // YES нормальні дужки для пріорітету

int main() {
    std::cout << MAX(3,5)<<std::endl; //5
    std::cout << MAX(2.5, 1.9) << std::endl;//2.5
    std::cout << MAX('x', 'A') << std::endl; //x

    std::cout << 100 / SQUARE(5) << std::endl; // no no no 100 спочатку поділиться на 5 а потім помножиться на наступне 5
    std::cout << RIGHT_SQUARE(5) << std::endl; // YES 100 поділиться зразу на 25

    /////////////// /////////// /////////////////////
    ///
    /// Standart Template Library
    /// Контейнери
    //- структури даних, що можуть містити об'єкти фактично будь-якого типу (Template-based class)
    //- кожен контейнер є  класом із своїми методами
    ///////////є методи унікальні до контейнера, є узагальнені поміж всіма контейнерами
    //- у кожного контейнера є  свій власний хедер-файл
    //////// #include <container_type>
    ///Контейнер завжди робитиме копії об'єктів, тому
    ///можна складати: Будь-які примітиви, Складні об'єкти
    //Кожен об'єкт повинен мати:
    //   можливість копіювання та перепризначення (Copy/assign)
    //   можливість переміщення для кращої продуктивності(Move)
    //Контейнери, для яких важливий порядок, повинні мати можливість сортувати елементи
    //    operator<,  operator==,...

    /// STL::Iterators
    //Дозволяють абстрактно підходити до будь-якого контейнера та уявляти його як послідовність елементів
    //Працюють із об'єктами так, як вказівники
    //Більшість контейнерів можна обхоодити за допомогою ітераторів

    //STL::Iterators - оголошення

    std::vector<int>::iterator vectorIterator;
    std::list<std::string>::iterator listIterator;
    std::map<std::string, int>::iterator mapIterator;
    std::set<char>::iterator setIterator;

    // vector.begin() = перший елемент
    // vector.end() = після останнього елементу

    std::vector<int> vector{1,2,3};

    std::vector<int>::iterator  it = vector.begin();
    // або
    auto it1 = vector.begin();


    // STL::Iterators - приклад
    std::vector<int> vector1{1,2,3};
    auto it2 = vector1.begin();
    while (it2 != vector1.end()) {
        std::cout << *it2 <<  " ";
        ++it2; //перевантажений унарний оператор ПРЕФІКСНИЙ
    }

    // STL::Iterators - приклад
    std::vector<int> vector3{1,2,3};
    for (auto it3 = vector3.begin(); it3 != vector3.end(); it3++) {
        std::cout << *it3 <<  " ";
    }

    // STL::Iterators - приклад
    std::vector<int> numbers{1,2,3};
    auto it4 = numbers.rbegin(); //reverse iterator, rbegin = 3
    while (it4 != numbers.rend()) { // rend = зліва від 1
        std::cout <<  *it4 << " ";
        ++it4;
    }

    //STL::array
    std::array<int, 5> numbers2{1,2,3,4,5};
    std::cout<<numbers2.size()<<std::endl;
    try {
        std::cout<<numbers2.at(7)<<std::endl;
    }catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << numbers2[1] << std::endl;
    std::cout << numbers2.front() << std::endl; // перший елементи
    std::cout << numbers2.back() << std::endl; // останній елемент


    //STL::deque (double ended queue) можна додавати і виділяти елементи з обох кінців за сталий час О(1)
    //в вектор вставка дорога, дек спроєктований для такого.
    std::deque<int> d1{1,2,3,4,5};
    std::deque<int> d2(10,100); //10 елементів, кожен = 100

    std::deque<std::string> names {
        std::string("Harry"),
        "Hermione",
        std::string("Rone")
    };

    d1 = {2,5,6,7,8,9};

    return 0;
}