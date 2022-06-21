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
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        if(head==NULL){
            n--;
            return NULL;
        }
        head->next = removeNthFromEnd(head->next, n);
        
        ListNode* temp = head->next;
        if(n==0){
            head->next = NULL;
            delete head;
            head = temp;
        }
        n--;
        return head;
        
    }
};