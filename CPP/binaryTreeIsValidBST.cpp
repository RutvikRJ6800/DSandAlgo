// https://www.interviewcake.com/question/cpp/bst-checker?course=fc1&section=trees-graphs
#include <iostream>
#include <memory>
#include<bits/stdc++.h>
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};




bool isBinarySearchTree(BinaryTreeNode* root, int lowerBound, int upperBound){
    if(root==NULL){
        return true;
    }
    else if(root->value_ <= lowerBound || root->value_ >= upperBound){
        return false;
    }
    else
    return(isBinarySearchTree(root->left_,lowerBound,root->value_)&&
    isBinarySearchTree(root->right_,root->value_,upperBound));
}

bool isBinarySearchTree(BinaryTreeNode* root)
{
    // determine if the tree is a valid binary search tree
    if(isBinarySearchTree(root,INT_MIN,INT_MAX)){
        return true;
    }
    else{
        return false;
    }
}


















// tests

const lest::test tests[] = {
    {CASE("Valid full tree") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(30)->insertLeft(10);
        root->insertRight(70)->insertRight(80);
        root->left_->insertRight(40);
        root->right_->insertLeft(60);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }},
    {CASE("Both subtrees valid") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(30)->insertLeft(20);
        root->insertRight(80)->insertRight(90);
        root->left_->insertRight(60);
        root->right_->insertLeft(70);
        EXPECT(isBinarySearchTree(root.get()) == false);
    }},
    {CASE("Descending linked list") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(40)->insertLeft(30)->insertLeft(20)->insertLeft(10);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }},
    {CASE("Out of order linked list") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertRight(70)->insertRight(60)->insertRight(80);
        EXPECT(isBinarySearchTree(root.get()) == false);
    }},
    {CASE("One node tree") {
        auto root = make_unique<BinaryTreeNode>(50);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}