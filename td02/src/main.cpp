#include <vector>
#include <iostream>
#include <algorithm>
#include "sort.hpp"
#include "ScopedTimer.hpp"

int main()
{
    // TRI BULLES
    std::vector<int> tab{6, 2, 8, 1, 5, 3, 9};
    bubble_sort(tab);
    if (is_sorted(tab))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    // TRI FUSION
    std::vector<int> vec{6, 2, 8, 1, 5, 3, 9};
    merge_sort(vec);
    if (is_sorted(vec))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }

    // COMPARAISON DES ALGOS
    std::vector<int> vector{generate_random_vector(500, 100)};

    {
        ScopedTimer timer("tri à bulles");
        bubble_sort(vector);
    }

    {
        ScopedTimer timer("tri fusion");
        merge_sort(vector);
    }

    std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};

    {
        ScopedTimer timer("bibliothèque");
        std::sort(array.begin(), array.end());
    }

    // On constate que le tri fourni par la bibliothèque standard est bien plus rapide que les deux algorithmes que nous avons programmé.

    // DICHOTOMIE
    std::vector<int> tab1{1, 2, 2, 3, 4, 8, 12};
    std::vector<int> tab2{1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> tab3{2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> tab4{5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> tab5{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "tab1 : " << search(tab1, 8) << std::endl;
    std::cout << "tab2 : " << search(tab2, 15) << std::endl;
    std::cout << "tab3 : " << search(tab3, 16) << std::endl;
    std::cout << "tab4 : " << search(tab4, 6) << std::endl;
    std::cout << "tab5 : " << search(tab5, 10) << std::endl;

    return 0;
}