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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* ant = head;
        ListNode* prox = head->next;
        while(prox){
            if(ant->val == prox->val){
                ListNode* tmp = prox->next;
                ant->next = prox->next;
                prox->next = nullptr;
                prox = tmp;
            }
            else{
                ant = prox;
                prox = prox->next;
            }
        }
        return head;
    }
};