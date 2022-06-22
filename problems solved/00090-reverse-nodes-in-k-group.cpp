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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = NULL;
        ListNode* startNode = head;
        ListNode* endNode = NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        int count = 0;
        
        while(curr){
            if(count==k){
                count = 0;
                if(ans==NULL){
                    ans = prev;
                }else{
                    endNode->next = prev;
                }
                endNode = startNode;
                startNode = curr;
                prev = NULL;
            }           
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            count++;
        }
        if(count==k){
            if(ans==NULL){
                ans = prev;
            }else{
                endNode->next = prev;
            }
            endNode = startNode;
            startNode = curr;
            prev = NULL;
        }else{
            curr = prev;
            prev = NULL;
            next = NULL;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(ans==NULL){
                ans = prev;
            }else{
                endNode->next = prev;
            }
        }
        return ans;
    }
};