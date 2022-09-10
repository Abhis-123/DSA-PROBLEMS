#include <bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
}

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void print_preorder(Node* node){
    /**
     * @brief Algorithm Preorder(tree)
     *   1. Visit the root.
     *  2. Traverse the left subtree, i.e., call Preorder(left-subtree)
     *  3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
     */
    if(node==NULL){
        return;
    }
    cout <<node->data <<endl;
    print_preorder(node->left);

    print_preorder(node->right);

}

void print_postorder(Node* node){
    /**
     * @brief Algorithm Postorder(tree) 
     * Traverse the left subtree
     * travrse right subtree
     * visit the node data
     */

     if(node==NULL){
         return;
     }

     print_postorder(node->left);
     print_postorder(node->right);
     cout << node->data <<endl;
}

void print_postorder(Node* node){
    /**
     * @brief Algorithm Postorder(tree) 
     * Traverse the left subtree
     * travrse right subtree
     * visit the node data
     */

     if(node==NULL){
         return;
     }

     print_postorder(node->left);
     print_postorder(node->right);
     cout << node->data <<endl;
}


void print_inorder(Node* node){
        /**
     * @brief Algorithm Postorder(tree) 
     * Traverse the left subtree
     * visit the node data
     * travrse right subtree
     */

     if(node==NULL){
         return;
     }

     print_postorder(node->left);
     cout << node->data <<endl;
     print_postorder(node->right);
}

vector<vector<int>> bft(TreeNode* root){
    
    queue<TreeNode*> q;
    vector<vector<int>> result;
    q.push_back(root);

    while(q.size()>0){
        vector<int> level;
        
        for(int i=0; i <q.size(); i++){
            TreeNode* node = q.pop();
            level.push_back(node);
            if(node->left!=NULL)q.push_back(node->left);
            if(node->right!=NULL)q.push_back(node->right);
        }

        result.push_back(level);

    }
    return result;

}

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root==NULL)return result;
        result.push_back(root->val);

        while(root){
            if(root->right!=NULL){ root = root->right;}
            else if(root->left!=NULL){ root = root->left;}
            else{
                break;
            }
            result.push_back(root->val);
        }
        return result;
    }
