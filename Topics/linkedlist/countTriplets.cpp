// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};
int countTriplets_brute(struct Node* head, int x)
{
    struct Node* ptr1, *ptr2, *ptr3;
    int count = 0;
  
    // generate all possible triplets
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
            for (ptr3 = ptr2->next; ptr3 != NULL; ptr3 = ptr3->next)
  
                // if elements in the current triplet sum up to 'x'
                if ((ptr1->data + ptr2->data + ptr3->data) == x)
  
                    // increment count
                    count++;
  
    // required count of triplets
    return count;
}
// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
	struct Node* ptr1, *ptr2, *ptr3;
	int count = 0;
    ptr1 = head;
    ptr2 = head->next;
    ptr3 = head;
    while (ptr3->next!=NULL) ptr3= ptr3->next;
    int sum = 0;
    for(ptr1; ptr1!=NULL; ptr1 = ptr1->next){
        ptr2 = ptr1->next;
        while(ptr2!=ptr3 && ptr2 &&ptr3){
            sum = ptr1->data + ptr2->data + ptr3->data;
            if(sum<x){
                ptr2 = ptr2->next;
            }else if(sum>x){
                ptr3=  ptr3->prev;
            }else {
                count++;
                ptr2 = ptr2->next;
            }
        }
    }
	return count;
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

void findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        struct Node *ptr1=head , *ptr2= head;
        int length= 1;
        while(ptr2->next){ ptr2= ptr2->next; length++;}
        // cout << "length"<<length<<endl;
        int start=1, end =1,sum;
        while(ptr1!=ptr2 && start+end<=length){
            sum = ptr1->data + ptr2->data;
            if(sum< target){
                ptr1 = ptr1->next;
                start++;
            }else if(sum> target){
                ptr2 = ptr2->prev;
                end++;
            }else{
                cout<<ptr1->data<<" "<<ptr2->data<<endl;
                ptr1 = ptr1->next;
                start++;
            }
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
