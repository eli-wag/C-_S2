#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#include "node.hpp"

Node *create_node(int value)
{
    return new Node{value, nullptr, nullptr};
}

bool Node::is_leaf() const
{
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    return false;
}

void Node::insert(int entier)
{
    if (entier <= value)
    {
        if (left != nullptr)
        {
            left->insert(entier);
        }
        else
        {
            left = create_node(entier);
        }
    }
    else
    {
        if (right != nullptr)
        {
            right->insert(entier);
        }
        else
        {
            right = create_node(entier);
        }
    }
}

int Node::height() const
{

    int hauteur_right{0};
    int hauteur_left{0};
    if (left == nullptr && right == nullptr)
    {
        return 0;
    }

    if (right != nullptr)
    {
        hauteur_right = right->height();
    }
    if (left != nullptr)
    {
        hauteur_left = left->height();
    }

    if (hauteur_left >= hauteur_right)
    {
        return hauteur_left + 1;
    }
    else
    {
        return hauteur_right + 1;
    }
};

void Node::delete_childs() // ca se dit pas childs c'est children
{
    if (is_leaf())
    {
        return;
    }
    if (right != nullptr)
    {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
    if (left != nullptr)
    {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
}

void Node::display_infixe() const
{
    if (this != nullptr)
    {
        if (this != nullptr)
        {
            left->display_infixe();
        }
        std::cout << value << " ";
        if (this != nullptr)
        {
            right->display_infixe();
        }
    }
}

// int Node::infixe()
// {
//     if (this != nullptr)
//     {
//         left->display_infixe();
//         return value;
//         right->display_infixe();
//     }
// }

std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> nodes{};
    std::vector<Node const *> child_prefixe{};
    if (this != nullptr)
    {
        nodes.push_back(this);
    }
    if (left != nullptr)
    {
        child_prefixe = left->prefixe();
        nodes.insert(nodes.end(), child_prefixe.begin(), child_prefixe.end());
    }
    if (right != nullptr)
    {
        child_prefixe = right->prefixe();
        nodes.insert(nodes.end(), child_prefixe.begin(), child_prefixe.end());
    }
    return nodes;
}

Node *&most_left(Node *&node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return most_left(node->left);
}

Node *&most_right(Node *&node)
{
    if (node->right == nullptr)
    {
        return node;
    }
    return most_right(node->right);
}

bool remove(Node *&node, int value)
{
    if (value == node->value && node->is_leaf())
    {
        delete node;
        node = nullptr;
        return true;
    }
    if (value == node->value && node->right != nullptr && node->left == nullptr)
    {
        Node *right{node->right};
        delete node;
        node = right;
        return true;
    }
    if (value == node->value && node->right == nullptr && node->left != nullptr)
    {
        Node *left{node->left};
        delete node;
        node = left;
        return true;
    }
    if (value == node->value && node->right != nullptr && node->left != nullptr)
    {
        Node *m_left = most_left(node->left);
        delete node;
        node->value = m_left->value;
        delete most_left(node->left);
        return true;
    }
    return false;
}

void delete_tree(Node *node)
{
    if (!(node->is_leaf()))
    {
        node->delete_childs();
    }
    delete node;
    node = nullptr;
    if (node == nullptr)
    {
        std::cout << "root deleted";
    }
    return;
}

std::vector<Node const *> Node::postfixe() const
{
    std::vector<Node const *> nodes{};
    std::vector<Node const *> child_postfixe{};

    if (this != nullptr)
    {

        child_postfixe = left->postfixe();
        nodes.insert(nodes.end(), child_postfixe.begin(), child_postfixe.end());

        if (this != nullptr)
        {
            right->postfixe();
            nodes.insert(nodes.end(), child_postfixe.begin(), child_postfixe.end());
        }
    }
    return nodes;
}
