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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        while(head){
            if(map[head]){
                return head;
            }
            map[head]++;
            head = head->next;
        }
        return NULL;
    }
};