// https://www.interviewcake.com/question/cpp/balanced-binary-tree?course=fc1&section=trees-graphs
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


bool isBalanced( BinaryTreeNode* treeRoot)
{
    // determine if the tree is superbalanced
    if(!treeRoot){
        return true;
    }
    else{
        
        queue<pair<BinaryTreeNode*,int>> qp;
        qp.push({treeRoot,0});
        int maxDepth = INT_MIN;
        int minDepth = INT_MAX;
        
        while(!qp.empty()){
            BinaryTreeNode* curr = qp.front().first;
            int depth = qp.front().second;
            qp.pop();
            
            if(curr->left_){
                qp.push({curr->left_,depth+1});
            }
            if(curr->right_){
                qp.push({curr->right_,depth+1});
            }
            
            if(!curr->left_ && !curr->right_){
                if(depth>maxDepth){
                    maxDepth = depth;
                }
                if(depth<minDepth){
                    minDepth = depth;
                }
            }
            
        }
        
        if(maxDepth-minDepth>=2){
            return false;
        }
        else
        return true;
        
        
        
        
        
        
    }

}


















// tests

const lest::test tests[] = {
    {CASE("Full Tree") {
        auto root = make_unique<BinaryTreeNode>(5);
        root->insertLeft(8)->insertLeft(1);
        root->insertRight(6)->insertRight(4);
        root->left_->insertRight(2);
        root->right_->insertLeft(3);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Both leaves at the same depth") {
        auto root = make_unique<BinaryTreeNode>(3);
        root->insertLeft(4)->insertLeft(1);
        root->insertRight(2)->insertRight(9);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Leaf heights differ by one") {
        auto root = make_unique<BinaryTreeNode>(6);
        root->insertLeft(1);
        root->insertRight(0)->insertRight(7);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Leaf heights differ by two") {
        auto root = make_unique<BinaryTreeNode>(6);
        root->insertLeft(1);
        root->insertRight(0)->insertRight(7)->insertRight(8);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Three leaves total") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(5);
        root->insertRight(9)->insertRight(5);
        root->right_->insertLeft(8);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Both subtrees superbalanced") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(5);
        root->insertRight(9)->insertRight(5);
        root->right_->insertLeft(8)->insertLeft(7);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Both subtrees superbalanced two") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(2)->insertLeft(3);
        root->left_->insertRight(7)->insertRight(8);
        root->insertRight(4)->insertRight(5)->insertRight(6)->insertRight(9);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Three leaves at different levels") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertLeft(2)->insertLeft(3)->insertLeft(5);
        root->left_->insertRight(4);
        root->left_->left_->insertRight(6);
        root->insertRight(7)->insertRight(8)->insertRight(9)->insertRight(10);
        EXPECT(isBalanced(root.get()) == false);
    }},
    {CASE("Only one node") {
        auto root = make_unique<BinaryTreeNode>(1);
        EXPECT(isBalanced(root.get()) == true);
    }},
    {CASE("Linked list tree") {
        auto root = make_unique<BinaryTreeNode>(1);
        root->insertRight(2)->insertRight(3)->insertRight(4);
        EXPECT(isBalanced(root.get()) == true);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}