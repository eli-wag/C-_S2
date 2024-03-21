#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include <cctype>
#include <stack>
#include "utils.hpp"

// EXERCICE 1
std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    for (int i{0}; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            continue;
        }
        else if (std::isdigit(s[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// bool is_floating_colin(std::string const &s)
// {
//     for (int i{0}; i < s.size(); i++)
//     {
//         if(s[i] != '.' || !std::isdigit(s[i]))
//         {
//             return false;
//         }
//     }
//     return true;
// }

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack;

    for (int i{0}; i < tokens.size(); i++)
    {
        if (is_floating(tokens[i]))
        {
            stack.push(std::stof(tokens[i]));
        }
        else
        {
            float firstOperand{stack.top()};
            stack.pop();
            float secondOperand{stack.top()};
            stack.pop();
            if (tokens[i] == "+")
            {
                stack.push(firstOperand + secondOperand);
            }
            else if (tokens[i] == "-")
            {
                stack.push(secondOperand - firstOperand);
            }
            else if (tokens[i] == "/")
            {
                stack.push(secondOperand / firstOperand);
            }
            else if (tokens[i] == "*")
            {
                stack.push(firstOperand * secondOperand);
            }
            else if (tokens[i] == "^")
            {
                stack.push(pow(secondOperand, firstOperand));
            }
        }
    }
    return stack.top();
}

// EXERCICE 2

Token make_token(float value)
{
    Token nombre;
    nombre.value = value;
    nombre.type = TokenType::OPERAND;
    return nombre;
}

Token make_token(Operator op)
{
    Token operateur;
    operateur.op = op;
    operateur.type = TokenType::OPERATOR;
    return operateur;
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> vecTokens;
    for (int i{0}; i < words.size(); i++)
    {
        if (is_floating(words[i]))
        {
            vecTokens.push_back(make_token(std::stof(words[i])));
        }
        else
        {
            if (words[i] == "+")
            {
                vecTokens.push_back(make_token(Operator::ADD));
            }
            else if (words[i] == "-")
            {
                vecTokens.push_back(make_token(Operator::SUB));
            }
            else if (words[i] == "*")
            {
                vecTokens.push_back(make_token(Operator::MUL));
            }
            else if (words[i] == "/")
            {
                vecTokens.push_back(make_token(Operator::DIV));
            }
        }
    }
    return vecTokens;
}

float npi_evaluate(std::vector<Token> const &tokens)
{
    std::stack<float> stack;

    for (int i{0}; i < tokens.size(); i++)
    {
        if (tokens[i].type == TokenType::OPERAND)
        {
            stack.push(tokens[i].value);
        }
        else
        {
            float firstOperand{stack.top()};
            stack.pop();
            float secondOperand{stack.top()};
            stack.pop();
            if (tokens[i].op == Operator::ADD)
            {
                stack.push(firstOperand + secondOperand);
            }
            else if (tokens[i].op == Operator::SUB)
            {
                stack.push(secondOperand - firstOperand);
            }
            else if (tokens[i].op == Operator::DIV)
            {
                stack.push(secondOperand / firstOperand);
            }
            else if (tokens[i].op == Operator::MUL)
            {
                stack.push(firstOperand * secondOperand);
            }
            else if (tokens[i].op == Operator::POW)
            {
                stack.push(pow(secondOperand, firstOperand));
            }
        }
    }
    return stack.top();
}

// float npi_evaluate(std::vector<Token> const &tokens)
// {
//     std::stack<float> stack;

//     for (int i{0}; i < tokens.size(); i++)
//     {
//         switch (tokens[i].type)
//         {
//         case TokenType::OPERAND:
//             stack.push(tokens[i].value);
//             break;

//         case TokenType::OPERATOR:
//             float firstOperand{stack.top()};
//             stack.pop();
//             float secondOperand{stack.top()};
//             stack.pop();

//             switch (tokens[i].op)
//             {
//             case Operator::ADD:
//                 stack.push(secondOperand + firstOperand);
//                 break;
//             case Operator::SUB:
//                 stack.push(secondOperand - firstOperand);
//                 break;
//             case Operator::MUL:
//                 stack.push(secondOperand * firstOperand);
//                 break;
//             case Operator::DIV:
//                 stack.push(secondOperand / firstOperand);
//                 break;
//             case Operator::POW:
//                 stack.push(pow(secondOperand, firstOperand));
//                 break;
//             default:
//                 break;
//             }
//             break;
//         default:
//             break;
//         }
//     }
//     return stack.top();
// }