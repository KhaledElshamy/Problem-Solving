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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL || head->next == NULL)return head;
        
       
        ListNode* Head =  new ListNode(0); 
        ListNode* SmallNode = Head;
        
        ListNode* Tail = new ListNode(0);
        ListNode* LargeNode = Tail;
        
        while(head != NULL){
            ListNode* next = head->next;
            if(head->val < x){
                SmallNode->next = head;
                SmallNode = SmallNode->next;
            }else {
                LargeNode->next = head;
                LargeNode = LargeNode->next;
            }
            head = next;
        }
        
        LargeNode->next = NULL;
        SmallNode->next = Tail->next;
        return Head->next;
    }
};
