#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "utils.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

auto const is_space = [](char letter)
{
    return letter == ' ';
};

int count(std::string const string)
{
    std::string::const_iterator iterator = std::find_if(string.begin(), string.end(), is_space);
    auto n = std::distance(string.begin(), iterator);
    return n;
}

std::vector<std::string> split_string(std::string const &str)
{

    std::string::const_iterator iterator{str.begin()};
    std::string::const_iterator iterator2{std::find_if(iterator, str.end(), is_space)};
    std::vector<std::string> mots{};
    while (iterator2 != str.end())
    {

        std::string lettre(iterator, iterator2);
        if (lettre.size() > 1)
        {
            mots.push_back(lettre);
        }
        iterator = iterator2 + 1;
        iterator2 = std::find_if(iterator, str.end(), is_space);
    }
    return mots;
}

// EXERCICE 3

// bool palindrome(const std::string s)
// {
//     return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
// };