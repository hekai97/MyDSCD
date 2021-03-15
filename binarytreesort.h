#pragma once
#ifndef BINARYTREESORT_H
#define BINARYTREESORT_H

#include "tree.h"
#include "personarray.h"
#include <QDebug>

class BinaryTreeSort{
public:
    BinaryTreeSort();
    Tree* root;          //二叉树的节点
    void initBTS(Tree*& tree, PersonArray* data);     //二叉排序树的构造
    bool insertBTS(Tree*& root, Person data);     //二叉排序树的插入
    bool deleteBTS(Tree*& root, Person data);
    void printBTS(Tree* root);
    void deleteTree(Tree*& root);
    void getSortedArray(Tree*& tree,PersonArray* data);
private:
    void getArray(Tree*& tree,PersonArray* data,int& index);
};

#endif // BINARYTREESORT_H
