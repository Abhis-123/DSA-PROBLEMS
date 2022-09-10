#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compare(pair<int, int> p1, pair<int, int> p2){
        if(p1.second!=p2.second) return p1.second > p2.second;

        return p1.first<p2.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>> hashmap;
        int left_min = 0, right_max = 0;
        queue<pair<TreeNode*,pair<int,int>> q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto  p = q.front();q.pop();
            hashmap[p.second.first].push_back({p.first->val, p.second.second});
            // get th left and right max depths of tree
            left_min = min(left_min, p.second.first);
            right_max = max(right_max,p.second.first);
            // get the tree node 
            TreeNode* node = p.first;
            if(node->left){
                q.push({node->left,{p.second.first-1,p.second.second+1}});
            }
            if(node->right){
                q.push({node->right, {p.second.first+1,p.second.second+1}});
            }
        }
        vector<vector<int>>  res ;
        for(int i=left_min; i<=right_max; i++){
            vector<pair<int,int>> col = hashmap[i];
            sort(col.begin(),col.end(), compare);
            vector<int> temp ; for( int  i =0; i< col.size(); i++) temp.push_back(col.first);
            res.push_back(temp);
        }
        return res;
    }
};





struct returned{
    int max;
    int min;
    int is_bst;
}