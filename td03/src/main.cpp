#include <stack>
#include <iostream>
#include <string>
#include "utils.hpp"

int main()
{
    // EXERCICE 1
    std::stack<float> stack;

    std::string npi{""};
    std::cout << "Entrez votre calcul en notation npi : " << std::endl;
    std::getline(std::cin, npi);
    std::vector<std::string> vec{split_string(npi)};

    // for (int i{0}; i < vec.size(); i++)
    // {
    //     if (is_floating(vec[i]))
    //     {
    //         std::cout << vec[i] << " ";
    //     }
    // }
    std::cout << npi_evaluate(vec) << std::endl;

    std::cout << "3 + 4 = " << npi_evaluate(split_string("3 4 +")) << std::endl;
    std::cout << "2 + 12 + 5 = " << npi_evaluate(split_string("2 12 + 5 +")) << std::endl;
    std::cout << "3 + 4 / ( 11 + 5 ) = " << npi_evaluate(split_string("3 4 11 5 + / +")) << std::endl;
    std::cout << "4 + 5 * 2 = " << npi_evaluate(split_string("4 5 2 * +")) << std::endl;
    std::cout << "3 + 4 ^ 2 / ( 1 - 5 ) ^ 6 = " << npi_evaluate(split_string("3 4 2 ^ 1 5 - 6 ^ / +")) << std::endl;

    // EXERCICE 2

    std::cout << "3 + 4 = " << npi_evaluate(tokenize(split_string("3 4 +"))) << std::endl;
    std::cout << "2 + 12 + 5 = " << npi_evaluate(tokenize(split_string("2 12 + 5 +"))) << std::endl;
    std::cout << "3 + 4 / ( 11 + 5 ) = " << npi_evaluate(tokenize(split_string("3 4 11 5 + / +"))) << std::endl;
    std::cout << "4 + 5 * 2 = " << npi_evaluate(tokenize(split_string("4 5 2 * +"))) << std::endl;
    std::cout << "3 + 4 ^ 2 / ( 1 - 5 ) ^ 6 = " << npi_evaluate(tokenize(split_string("3 4 2 ^ 1 5 - 6 ^ / +"))) << std::endl;
}