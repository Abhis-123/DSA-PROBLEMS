#include <iostream>
#include <bits/stdc++.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp = curr;
        ListNode* next = head->next;
        int num_reversed = 0;
        while(next != NULL && num_reversed <k){
            current->next = prev;
            cur = next;
            prev = cur;
            next = next->next;
        }

        head = curr;
        if(next != NULL){ 
            temp->next = reverseKGroup(next, k);
        }

        return head;

    }
};