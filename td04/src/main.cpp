#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "utils.hpp"

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

    std::string s{"le mot de la fin nif al ed tom el"};
    std::cout << "Longueur du premier mot : " << count(s) << std::endl;

    std::vector<std::string> vec{split_string(s)};

    for (int i{0}; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    if (palindrome(s))
    {
        std::cout << "c'est un palindrome" << std::endl;
    }
    else
    {
        std::cout << "ce n'est pas un palindrome" << std::endl;
    }

    return 0;
}