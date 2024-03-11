#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// TRI A BULLES
void bubble_sort(std::vector<int> &vec)
{
    while (!is_sorted(vec))
    {
        for (int i{0}; i <= vec.size(); i += 2)
        {
            if (i > i + 1)
            {
                std::swap(vec[i], vec[i + 1]);
            }
        }
    }
}

int main()
{
    // std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // if (is_sorted(array))
    // {
    //     std::cout << "Le tableau est trié" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Le tableau n'est pas trié" << std::endl;
    // }

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
}