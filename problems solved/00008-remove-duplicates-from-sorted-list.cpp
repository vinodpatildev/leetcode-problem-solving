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
    ListNode* removeDuplicates(ListNode* curr,int preval){
        if(curr == NULL){
            return NULL;
        }
        
        if(curr->val == preval){
            ListNode* Next = curr->next;       
            delete(curr);
            
            return removeDuplicates(Next,preval);
        }else{
            curr->next = removeDuplicates(curr->next,curr->val);
            return curr;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return removeDuplicates(head,101);
    }
};