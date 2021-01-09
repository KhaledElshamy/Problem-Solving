/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    int val = 100001;
    
    bool hasCycle(ListNode *head) {
        
        if(head == NULL) return false;
        if(head->val == val){flag = true;return false;}
        head->val = val;
        hasCycle(head->next);
        
        return flag;
    }
};
