#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

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
    std::string::const_iterator iterator{};
    while (iterator != str.end())
    {
        iterator = std::find_if(str.begin(), str.end(), is_space);
        auto n = std::distance(str.begin(), iterator);

        std::vector<std::string> mots{};
        for (int i{0}; i <= n; i++)
        {
            mots.push_back();
        }
    }
};

int main()
{

    // EXERCICE 1
    std::vector<int> random_vector{generate_random_vector(10, 100)};

    std::vector<int>::iterator end_iterator{random_vector.end()};

    for (std::vector<int>::iterator it{random_vector.begin()}; it != end_iterator; ++it)
    {
        std::cout << *it << ", ";
    }

    int entier{0};
    std::cout << " " << std::endl;
    std::cout << "Entrer un entier compris entre 0 et 100 :" << std::endl;
    std::cin >> entier;

    auto it{std::find(random_vector.begin(), random_vector.end(), entier)};

    // On compare l'itérateur avec l'itérateur sur le dernier élément du vecteur
    if (it != random_vector.end())
    {
        std::cout << *it << " trouve ! " << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    std::sort(random_vector.begin(), random_vector.end());

    // Parcours du vecteur avec l'itérateur
    for (int element : random_vector)
    {
        std::cout << element << ", ";
    }

    std::cout << " " << std::endl;
    int sum = std::accumulate(random_vector.begin(), random_vector.end(), 0);
    std::cout << "somme  : " << sum << std::endl;

    // EXERCICE 2

    std::string s{"Moi c'est Mike"};
    std::cout << "Longueur du premier mot : " << count(s);

    return 0;
}