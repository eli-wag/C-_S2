#include <iostream>
#include <vector>

bool is_sorted(std::vector<int> const &vec);

void bubble_sort(std::vector<int> &vec);

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> &vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> &vec);

std::vector<int> generate_random_vector(size_t const size, int const max = 100);

int search(std::vector<int> &vec, int const val, int left, int right);
int search(std::vector<int> &vec, int const val);