#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}
pair<bool,pair<int,int>> helper_is_bst(Node* root){
    if(root==NULL){
        return {1, {INT_MAX, INT_MIN}};
    }
    pair<int,pair<int,int>> left = helper_is_bst(root->left);
    pair<int,pair<int,int>> right = helper_is_bst(root->right);
    int _max = max(root->data, right.second.second);
    int _min = min(left.second.first, root->data);
    bool is_bst = (root->data > left.second.second && root->data < right.second.first) && left.first && right.first;
    return {is_bst, {_min, _max}};
}

bool is_bst(Node* node) {
    auto res = helper_is_bst(node);
    return res.first;
}

