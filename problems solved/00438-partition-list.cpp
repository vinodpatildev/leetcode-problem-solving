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
        ListNode *l=NULL, *r=NULL, *lp=NULL, *rp=NULL, *temp;

        while(head != NULL){
            if(head->val < x){
                if(l){
                    lp->next = head;
                    lp = head;
                }else{
                    l = head;
                    lp = l;
                }
            }else{
                if(r){
                    rp->next = head;
                    rp = head;
                }else{
                    r = head;
                    rp = r;
                }
            }
            temp = head;
            head = head->next;
            temp->next=NULL;
        }
        if(l==NULL) return r; 
        lp->next = r;      
        return l;
    }
};
// k=3
// H
// 1-> 4-> 3-> 2-> 5-> 2->NULL

// l : 1->
// r
// lp : 1->
// rp