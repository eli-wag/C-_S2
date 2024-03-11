#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<float> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// TRI FUSION
// std::vector<float> division(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
// {
//     std::vector<float> vec1;
//     std::vector<float> vec2;

//     for (size_t i{0}; i < middle; i++)
//     {
//         vec1.push_back(vec[i]);
//         division(vec1, 0, right - left + 1, vec1.size() - 1);
//     }
//     for (size_t j{middle}; j <= vec.size(); j++)
//     {
//         vec2.push_back(vec[j]);
//         division(vec2, 0, right - left + 1, vec2.size() - 1);
//     }
// }

// void tri(std::vector<float> &vec, size_t const left, size_t const right)
// {
//     while (vec.size() != 2)
//     {
//         division(vec, 0, right - left + 1, vec.size() - 1);
//     }
//     if (vec[left] > vec[vec.size()])
//     {
//         std::swap(vec[left], vec[vec.size()]);
//     }
// }
// void merge_sort(std::vector<float> &vec)
// {
//     tri(vec, 0, vec.size() - 1);
// }

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size{middle - left + 1};
    size_t const right_size{right - middle};
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index{0};
    size_t right_index{0};

    size_t index{left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size)
    {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] <= right_vec[right_index])
        {
            vec[index] = left_vec[left_index];
            left_index++;
        }
        else
        {
            vec[index] = right_vec[right_index];
            right_index++;
        }
        /* TODO */
        index++;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index < left_size)
    {
        vec[index] = left_vec[left_index];
        left_index++;
        index++;
    }
    while (right_index < right_size)
    {
        vec[index] = right_vec[right_index];
        right_index++;
        index++;
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}
void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
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

    std::vector<float> tab{6, 2, 8, 1, 5, 3, 9};
    merge_sort(tab);
    if (is_sorted(tab))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}