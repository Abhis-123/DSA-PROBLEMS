#include <iostream>  
using namespace std;  

class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum  = new ListNode();
        ListNode* current_pointer = sum;
        
        // carry 
        int carry =0,temp_digits_sum=0, final_digits_sum=0;
        while(l1||l2){
            temp_digits_sum = l1->val + l2->val + carry;            
            carry = temp_digits_sum/10;
            if(temp_digits_sum<10){
                final_digits_sum = temp_digits_sum;
            }else{
                final_digits_sum = temp_digits_sum%10;
            }            
            current_pointer->next = new ListNode(final_digits_sum);
            current_pointer = current_pointer ->next;
            if(!l1->next && l2->next){
                l1->next = new ListNode(0); 
            }else if(l1->next && !l2->next){
                l2->next = new ListNode(0);
            }
            l1 = l1->next;
            l2 = l2->next;
            
        }
        // clear carry 
        if(carry!=0){
            current_pointer->next = new ListNode(carry);
        }
        return sum->next;
    }

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* l3 = addTwoNumbers(l1,l2);
    while(l3){
        cout<<l3->val<<endl;
        l3= l3->next;
    }

}