#include <iostream>
#include "utils.hpp"

int main()
{

    // // EXERCICE 1

    std::string str1{"abc"};
    std::string str2{"bca"};
    std::cout << folding_string_hash(str1, 2048) << std::endl;
    std::cout << folding_string_ordered_hash(str1, 2048) << std::endl;
    std::cout << folding_string_ordered_hash(str2, 2048) << std::endl;
    std::cout << polynomial_rolling_hash(str1, 2, 1024) << std::endl;
    std::cout << polynomial_rolling_hash(str2, 2, 1024) << std::endl;

    // EXERCICE 2
    std::vector<std::pair<std::string, float>> const &robots_fixes{get_robots_fix(1000)};
    std::unordered_map<std::string, std::vector<float>> map{robots_fixes_map(robots_fixes)};

    for (auto const &[robotName, value] : map)
    {
        std::cout << robotName << " : " << sum(value) << std::endl;
    }

    // EXERCICE 3
    std::vector<Card> game{get_cards(100)};

    std::unordered_map<Card, int> allCards = countCard(game);

    for (const std::pair<Card, int> &p : allCards)
    {
        std::cout << card_name(p.first) << " : " << p.second << std::endl;
    }

    return 0;
}