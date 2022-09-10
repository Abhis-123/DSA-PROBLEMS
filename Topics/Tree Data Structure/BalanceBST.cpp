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
    
    void dfs(TreeNode* root, vector<int>& dp){
        if(root == nullptr) return;
        dfs(root->left, dp);
        dp.push_back(root->val);
        dfs(root->right, dp);
    }
    TreeNode* build_tree_from_arr(vector<int>& dp, int x, int y){
        if(x>y) return nullptr;
        if(x==y) return new TreeNode(dp[x]);

        int mid = (x+y)/2;
        TreeNode* root = new TreeNode(dp[mid]);
        root->left = build_tree_from_arr(dp, x, mid-1);
        root->right = build_tree_from_arr(dp,mid+1, y);
        return root;
    }


    
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> dp;
        dfs(root,dp);

        return build_tree_from_arr(dp, 0, dp.size()-1);
    }
};