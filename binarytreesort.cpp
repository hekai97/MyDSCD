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
//        if(data.getNumber()<root->data.getNumber())
//        {
//            return insertBTS(root->left,data);
//        }
//        else
//        {
//            return insertBTS(root->left,data);
//        }
        return false;
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
    if(root==nullptr)
    {
        return false;
    }
    else
    {
        if(data<root->data)
        {
            return deleteBTS(root->left,data);
        }
        else if(data>root->data)
        {
            return deleteBTS(root->right,data);
        }
        else
        {
            deleteNode(root);
            return true;
        }
    }
}
void BinaryTreeSort::deleteNode(Tree *& root)
{
    Tree *temp;
    if(root->right==nullptr)
    {
        temp=root;
        root=root->left;
        delete temp;
    }
    else if(root->left==nullptr)
    {
        temp=root;
        root=root->right;
        delete temp;
    }
    else deleteNode1(root,root->left);
}
void BinaryTreeSort::deleteNode1(Tree *root, Tree *r)
{
    Tree* temp=nullptr;
    if(root->right!=nullptr)
    {
        deleteNode1(root,root->right);
    }
    else
    {
        root->data=r->data;
        temp=r;
        r=r->left;
        delete temp;
    }
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
