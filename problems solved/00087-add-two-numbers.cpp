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
        ListNode* head = NULL;
        ListNode* curr = NULL;
        
        int carry = 0;
        int data = 0;
        while(l1 != NULL && l2 != NULL){
            data = l1->val + l2->val + carry ;
            l1->val = data%10;
            carry = data/10;
            if(head==NULL){
                head = l1;
            }else{
                curr->next = l1;
            }
            curr = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            data = l1->val + carry ;
            l1->val = data%10;
            carry = data/10;
            if(head==NULL){
                head = l1;
            }else{
                curr->next = l1;
            }
            curr = l1;
            l1 = l1->next;
        }
        while(l2 != NULL){
            data = l2->val + carry ;
            l2->val = data%10;
            carry = data/10;
            if(head==NULL){
                head = l2;
            }else{
                curr->next = l2;
            }
            curr = l2;
            l2 = l2->next;
        }
        if(carry != 0){
            curr->next = new ListNode(carry);
        }
        return head;
    }
};