/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)  return head;
        ListNode* res= new ListNode(-1);
        res->next = head;
        ListNode*  temp = res;
        while (temp&& temp->next)
        {
            if(temp->next->val==val){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return res->next;
    }
};
// @lc code=end

