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
    ListNode* front = NULL;
    
    bool helper(ListNode* node){
        if(node==NULL){
            return true;
        }
        bool isPal = helper(node->next) && (node->val == front->val);
        front = front->next;
        return isPal;
    }
    bool isPalindrome(ListNode* head) {
        front = head;
        return helper(head);
    }
};