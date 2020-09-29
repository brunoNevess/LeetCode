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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* p = head;
        ListNode* a = nullptr;
        bool f = false;
        while(p and p->val == val){
            a = p;
            p = p->next;
            f = true;
        }
        if(f){
            a->next = NULL;
            a = nullptr;
        }
        head = p;
        
        
        while(p){
            if (p->val == val){
                a->next = p->next;
                p->next = NULL;
                p = a->next;
            }
            else {
                a = p;
                p = p->next;
            }
        }
        return head;
        
        
    }
};