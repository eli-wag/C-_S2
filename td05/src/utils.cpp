#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include "utils.hpp"

// EXERCICE 1

size_t folding_string_hash(std::string const &s, size_t max)
{
    int sum{0};
    for (int i{0}; i <= s.size(); i++)
    {
        sum += char(s[i]);
    }
    return sum % max;
}

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    int sum{0};
    for (int i{0}; i <= s.size(); i++)
    {
        sum += char(s[i]) * i;
    }
    return sum % max;
}

size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m)
{
    int sum{0};
    int power{1};
    for (int i{0}; i <= s.size(); i++)
    {
        sum += char(s[i]) * power;
        power *= p;
    }
    return sum % m;
}

// EXERCICE 2

std::string random_name(size_t size)
{
    std::string name{""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        // random name
        std::string robotName{random_name(2)};
        // random cost
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> robots_fixes_map{};
    std::string robotName{robots_fixes[0].first};
    for (int i{0}; i < robots_fixes.size(); i++)
    {
        robotName = robots_fixes[i].first;
        auto robotNumber{robots_fixes_map.find(robotName)};
        if (robotNumber != robots_fixes_map.end())
        {
            robots_fixes_map[robotName].push_back(robots_fixes[i].second);
        }
        else
        {
            robots_fixes_map.insert(std::make_pair(robotName, std::vector<float>{robots_fixes[i].second}));
        }
    }
    return robots_fixes_map;
}

float sum(std::vector<float> v)
{
    float sum{0};
    for (int i{0}; i <= v.size(); i++)
    {
        return sum += v[i];
    }
}

bool Card::operator==(Card c) const
{
    return kind == c.kind && value == c.value;
}

int Card::hash() const
{
    int card_value = (int)(value);
    int card_kind = (int)(kind);
    return (card_value) + (card_kind * 13);
}

std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::unordered_map<Card, int> countCard(std::vector<Card> cardList)
{
    std::unordered_map<Card, int> countCardMap;
    for (int i{0}; i < cardList.size(); i++)
    {
        if (countCardMap.find(cardList[i]) == countCardMap.end())
        {
            countCardMap.insert(std::make_pair(cardList[i], 1));
        }
        else
        {
            countCardMap[cardList[i]]++;
        }
    }
    return countCardMap;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}