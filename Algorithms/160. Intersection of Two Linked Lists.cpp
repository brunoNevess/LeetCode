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
    
    int listSize(ListNode* head){
        int ans = 0;
        ListNode* s = head;
        while (s!=NULL){
            s = s->next;
            ans++;
        }
        return ans;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int l1 = listSize(headA);
        int l2 = listSize(headB);
        if (l1 == 0 or l2 == 0) return NULL;
        
        ListNode* pm;
        ListNode* pM;
        if(l1>=l2){
            pM = headA;
            pm = headB; 
        } 
        else {
            pM = headB;
            pm = headA;
        }
        int steps = max(l1,l2) - min(l1,l2);
        for(int i = 0;i<steps;i++) pM = pM->next;
        while (pm != NULL and pM!=NULL and pm!=pM){
            pm = pm->next;pM = pM->next;
        }
        return pm;
        
        
    }
};