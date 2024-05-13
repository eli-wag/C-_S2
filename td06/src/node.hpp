#pragma once
#include <iostream>
#include <vector>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};
    void insert(int entier);
    bool is_leaf() const;
    int height() const;
    void delete_childs();
    void display_infixe() const;
    // int Node::infixe();
    std::vector<Node const *> prefixe() const;
    Node *&most_left(Node *&node);
    Node *&most_right(Node *&node);
    bool remove(Node *&node, int value);
    std::vector<Node const *> postfixe() const;
};
Node *create_node(int value);
void delete_tree(Node *node);
