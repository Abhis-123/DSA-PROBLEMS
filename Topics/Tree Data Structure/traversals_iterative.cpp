#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{

    int data; 
    struct Node* left;
    struct Node* right;

    Node(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
};
/* Iterative function for inorder tree
   traversal */
void inOrder(struct Node *root)
{
    stack<Node *> s;
    struct Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */
}

void traverse_inorder(Node* node){

    stack<Node* > stack;
    Node* current_node = node;

    while(true){
        while(current_node){
            stack.push(current_node);
            current_node = current_node->left;
        }
        if(stack.empty()){
            break;
        }
        current_node = stack.top();
        stack.pop();
        cout <<current_node->data<<endl;

        current_node = current_node->right;
        // stack.pop();

    }


}

vector<int> postorder_traversal(Node* node){
    stack<Node* > stack;
    Node* current = node;
    Node* previous = NULL;
    vector<int> result;
    while(true){
        while(current){
            stack.push(current);
            current = current->left;
        }

        if(stack.empty()){
            break;
        }


        while(current ==NULL && !stack.empty()){
            current = stack.peek();
            if(current->right ==NULL || current->right ==previous){
                result.push_back(current->data);
                stack.pop();

                previous = current;
                current  = NULL;

            }else{
                previous = current->right;
            }
        }
    }
}


int main(){
    /**       1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
}