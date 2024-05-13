#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

// EXERCICE 1

size_t folding_string_hash(std::string const &s, size_t max);
size_t folding_string_ordered_hash(std::string const &s, size_t max);
size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t m);

// EXERCICE 2

std::string random_name(size_t size);
std::vector<std::pair<std::string, float>> get_robots_fix(size_t size);
std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes);
float sum(std::vector<float> v);

// EXERCICE 3

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;
    bool operator==(Card c) const;
    int hash() const;
};

std::string card_name(Card const &card);
std::vector<Card> get_cards(size_t const size);
std::unordered_map<Card, int> countCard(std::vector<Card> cardList);

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}
