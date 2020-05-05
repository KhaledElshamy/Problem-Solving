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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int length = 0 ;
        ListNode *temp = head ;
        while(temp != NULL) {
            length++;
            temp = temp->next;
        }
        
        if(n>length)return head;
        else if(n==length)return head->next;
        else {
            int removePoint = length - n ;
            ListNode* prev = NULL;
            ListNode* current = head;
            for(int i=0;i<removePoint;i++){
                prev = current;
                current = current->next;
            }
            prev->next = current-> next;
            return head ;
        }
    }
};
