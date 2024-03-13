#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"
#include "sort.hpp"

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// TRI A BULLES
void bubble_sort(std::vector<int> &vec)
{
    while (!is_sorted(vec))
    {
        for (int i{0}; i <= vec.size() - 2; i += 1)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
            }
        }
    }
}

// TRI FUSION
void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right)
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

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right)
{
    if (left < right)
    {
        size_t middle = left + (right - left) / 2;
        merge_sort(vec, left, middle);
        merge_sort(vec, middle + 1, right);
        merge_sort_merge(vec, left, middle, right);
    }
}
void merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

// COMPARAISON DES ALGOS
std::vector<int> generate_random_vector(size_t const size, int const max)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// DICHOTOMIE

int search(std::vector<int> &vec, int const val, int left, int right)
{
    if (left > right)
        return -1;

    int middle = (left + right) / 2;

    if (vec[middle] == val)
    {
        return middle;
    }
    if (vec[middle] < val)
    {
        return search(vec, val, middle + 1, right);
    }
    else if (vec[middle] > val)
    {
        return search(vec, val, left, middle);
    }
}

int search(std::vector<int> &vec, int const val)
{
    return search(vec, val, 0, vec.size() - 1);
}
