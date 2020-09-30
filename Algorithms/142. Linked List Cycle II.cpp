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
       if(!head) return nullptr;
        
        ListNode* t = head;
        while (t->next!= nullptr){
            if (t->next <= t) return t->next;
            t = t->next;
        }
        return nullptr;
        
    }
};