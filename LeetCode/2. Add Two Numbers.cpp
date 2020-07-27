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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int carry = 0 , sum ;
        
        ListNode *list =  new ListNode();
        ListNode *res = list;
        
        int val1 = (l1)? l1->val:0;
        int val2 = (l2)? l2->val:0;
        sum = val1 + val2 + carry;
        carry = sum / 10 ;
        
        list->val = sum %10;
        
        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
        
        while(l1 || l2){
            int val1 = (l1)? l1->val:0;
            int val2 = (l2)? l2->val:0;
            
            sum = val1 + val2 + carry;
            carry = sum / 10 ;
            
            l1 = l1 != NULL ? l1->next : NULL;
            l2 = l2 != NULL ? l2->next : NULL;
            
            
            ListNode* temp = new ListNode();
            temp->val = sum %10;
            
            list->next = temp;
            list = list->next;
        }
        
        if(carry > 0){
            ListNode* temp = new ListNode();
            temp->val = carry;
            
            list->next = temp;
            list = list->next;
        }
       
      return res;
    }
};
