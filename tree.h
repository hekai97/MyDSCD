#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <person.h>

class Tree
{
public:
    Person data;
    Tree *left;
    Tree *right;
    Tree();
    Tree(Person val);
    Tree(Person val,Tree* left,Tree* right);
};

#endif // TREE_H
