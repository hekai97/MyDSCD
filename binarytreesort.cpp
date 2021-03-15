#include "binarytreesort.h"

BinaryTreeSort::BinaryTreeSort() {};
void BinaryTreeSort::initBTS(Tree*& tree, PersonArray* data) {
    int i = 0;
    while (i < data->length) {
        insertBTS(tree, data->data[i]);
        ++i;
    }
}
bool BinaryTreeSort::insertBTS(Tree*& root, Person data) {
    if (root == nullptr)
    {
        root = new Tree(data,nullptr,nullptr);
        return true;
    }
    else if (data == root->data) {
        if(data.getNumber()<root->data.getNumber())
        {
            return insertBTS(root->left,data);
        }
        else
        {
            return insertBTS(root->left,data);
        }
    }
    else if (data < root->data) {
        return insertBTS(root->left, data);
    }
    else
    {
        return insertBTS(root->right, data);
    }
}

void BinaryTreeSort::printBTS(Tree *root){
    if(root==nullptr){
        return;
    }
    printBTS(root->right);
    qDebug()<<root->data;
    printBTS(root->left);
}
bool BinaryTreeSort::deleteBTS(Tree*& root, Person data)
{
    //实现较为复杂
    return false;
}
void BinaryTreeSort::deleteTree(Tree *&root){
    if(root==nullptr){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    qDebug()<<"节点"<<root->data<<"已删除";
    delete root;
}
void BinaryTreeSort::getSortedArray(Tree *&tree, PersonArray *data){
    int index=0;
    getArray(tree,data,index);
}
void BinaryTreeSort::getArray(Tree *&root, PersonArray *data, int &index){
    if(root==nullptr){
        return;
    }
    getArray(root->right,data,index);
    data->data[index++]=root->data;
    getArray(root->left,data,index);
}
