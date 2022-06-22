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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        while(head){
            if(map[head]){
                return true;
            }
            map[head]++;
            head = head->next;
        }
        return false;
    }
};