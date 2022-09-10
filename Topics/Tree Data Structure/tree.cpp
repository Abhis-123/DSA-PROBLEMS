#include <iostream>

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

int main(){
/**
 *          1
 *         / \
 *        2   3
 *       / \
 *      4   5
 */

  struct Node* tree_root = new Node(1);
  tree_root->left = new Node(2);
  tree_root->right = new Node(3);
  tree_root->left->left = new Node(4);
  tree->left->right  = new Node(5);

}