#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

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

    std::vector<int> tab;
    tab = generate_random_vector(100, 50);
    /// std::sort(tab.begin(), tab.end());

    {
        ScopedTimer timer("chrono bulle");
        // bubble_sort(tab);
    }

    if (is_sorted(tab))
    {
        std::cout << "Le tableau est trié" << std::endl;
        std::cout << ("chrono bulle");
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}