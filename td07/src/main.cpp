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

    std::cout << root->height() << std::endl;

    root->display_infixe();
    std::vector<Node const *> root_prefixe{root->prefixe()};

    std::cout << " " << std::endl;
    for (int i{0}; i < root_prefixe.size(); i++)
    {
        std::cout << root_prefixe[i]->value << " ";
    }

    std::cout << " " << std::endl;

    delete_tree(root);
    if (root->is_leaf())
    {
        std::cout << "vide" << std::endl;
    }
    else
    {
        std::cout << "plein" << std::endl;
    }

    return 0;
}