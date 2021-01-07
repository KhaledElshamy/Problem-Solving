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
    bool flag = true ;
    int totalNumOfNodes = 0 ;
    
    ListNode* reversList(ListNode* Node) {
        ListNode* head = NULL;
        while(Node!=NULL){
            ListNode* n = new ListNode(Node->val);
            n->next = head;
            head = n;
            totalNumOfNodes++;
            Node = Node->next;
        }
        return head;
    }
    
    
    bool isPalindrom(ListNode* list1, ListNode* list2){
        int halfNodes = totalNumOfNodes/2;
        int count = 0;
        while(count <= halfNodes && list1!=NULL && list2!=NULL){
            if(list1-> val != list2->val || !flag){flag = false; return flag;}
            count++;
            list1 = list1->next;
            list2 = list2->next;
        }
        return flag;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* reversedHead = reversList(head);
        return isPalindrom(head,reversedHead);
    }
};
