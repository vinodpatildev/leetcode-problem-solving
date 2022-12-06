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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *head1 = NULL, *head2 = NULL, *head3 = NULL, *res = NULL;
        int flag = 1;
        while(head){
            if(flag){
                if(head1 == NULL) head1 = head, res = head;
                else head1->next = head, head1 = head1->next;
            }else{
                if(head2 == NULL) head2 = head, head3 = head;
                else head2->next = head, head2 = head2->next;
            }
            flag = !flag;
            head = head->next;
        }
        head1->next = head3;
        if(head2) head2->next = nullptr;        
        return res;
    }
};