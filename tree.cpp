#include "tree.h"

Tree::Tree(){

}

Tree::Tree(Person val){
    this->data=val;
    this->left=nullptr;
    this->right=nullptr;
}
Tree::Tree(Person val,Tree* left,Tree* right){
    this->data=val;
    this->left=left;
    this->right=right;
}
