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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *curr = NULL;

        int minIndex = -1;
        int flag = true;
        while(flag){
            for(int it=0; it<lists.size(); it++){
                if(lists[it] == NULL) continue;
                if(minIndex == -1) minIndex = it;
                else if(lists[it]->val < lists[minIndex]->val) minIndex = it;
            }
            if(minIndex != -1){
                if(head == NULL){
                    head = lists[minIndex];
                    lists[minIndex] = lists[minIndex]->next;
                    head->next = NULL;
                    curr = head;
                }else{
                    curr->next = lists[minIndex];
                    lists[minIndex] = lists[minIndex]->next;
                    curr = curr->next;
                    curr->next = NULL;
                }
                minIndex = -1;
            }else{
                flag = false;
            }
        }
        return head;
    }
};