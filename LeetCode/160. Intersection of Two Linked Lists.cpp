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
    
    map<ListNode*,int> m;
    
    void loopOnList(ListNode* head){
        while(head!=NULL){
            m[head]++;
            head = head->next;
        }
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        if(headA == NULL || headB == NULL)return NULL;
        
        loopOnList(headA);
        loopOnList(headB);
        
        ListNode* res = NULL;
        while(headA){
            if(m[headA] == 2) {
                res = headA;
                break;
            }
            headA = headA->next;
        }
        
        return res;
    }
};
