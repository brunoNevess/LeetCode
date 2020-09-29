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
        
    int count = 0;
    bool flag = false;
    bool go = false;
    void helper(ListNode* head,int n){
         if(head) helper(head->next,n);
         if(go) return;
         if (count == n+1) flag  = true;
         if(not flag){
                 count++;
                 return;
         }
            
            
        else {
                
                ListNode* tmp = head->next;
                head->next = head->next->next;
                tmp->next = nullptr;
                go = true;
                return;
        }
            
            
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        helper(head,n);
        if(not flag){
                ListNode* tmp = head->next;
                head->next = nullptr;
                return tmp;
        }
        return head;
    }
};