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
    TreeNode* build_tree(vector<int>& preorder, int& pre_index, unordered_map<int,int>& imap, int low , int high){
        if(preorder.size()==pre_index){return nullptr;}
        int idx = imap[preorder[pre_index]];
        if(idx>high || idx<low){return nullptr;}

        TreeNode* node = new TreeNode(preorder[pre_index]);
        pre_index++;
        node->left = build_tree(preorder, pre_index,imap,low,idx-1);
        node->right = build_tree(preorder, pre_index,imap, idx+1,high);
        return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> imap ;
            for(int i = 0; i < inorder.size(); i++){
                imap[inorder[i]] = i;
            }
            int pre_idx =0;
        
            return build_tree(preorder, pre_idx, imap, 0, preorder.size());
}
TreeNode* build_tree_from_preorder(vector<int>& preorder){
        vector<int> inorder= preorder;
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder);
}
};