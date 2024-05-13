#include <iostream>
#include "node.hpp"

int main()
{
    Node *root{create_node(5)};
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    // if (root->is_leaf())
    // {
    //     std::cout << "vide" << std::endl;
    // }
    // else
    // {
    //     std::cout << "plein" << std::endl;
    // }

    // std::cout << root->value << std::endl;
    // std::cout << root->left->value << std::endl;

    std::cout << "Taille de l'arbre : " << root->height() << std::endl;

    std::cout << "Tri infixe  : ";
    root->display_infixe();
    std::vector<Node const *> root_prefixe{root->prefixe()};

    std::cout << " " << std::endl;

    std::cout << "Tri prefixe : ";
    for (int i{0}; i < root_prefixe.size(); i++)
    {
        std::cout << root_prefixe[i]->value << " ";
    }

    delete_tree(root);

    std::vector<Node const *> root_postfixe{root->postfixe()};
    std::cout << "Tri postfixe : ";
    for (int i{0}; i < root_postfixe.size(); i++)
    {
        std::cout << root_postfixe[i]->value << " ";
    }

    return 0;
}