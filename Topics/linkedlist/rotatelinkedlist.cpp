// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

Node* rotate(Node* node,int k){
    struct Node* temp = node;
    int len =1;
    while(temp->next != NULL){ temp = temp->next; ++len;}
    struct Node* end = temp;
    k = k%len; 

}
// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}


// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
    insert(&head, 12);
	insert(&head, 11);
	insert(&head, 10);
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
    // insert(&head, 0);
    // insert(&head, -1);
	int x = 17;

	cout << "Count = "
		<< countTriplets(head, x)<<endl;

   findPairsWithGivenSum(head, x);

	return 0;
}
