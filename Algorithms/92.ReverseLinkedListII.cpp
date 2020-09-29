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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p = head;
        ListNode* q ;
        for(int i=0;i<m-1;i++) p = p->next;
        q = p;
        stack<int> s;
        for(int i=0;i<n-m+1;i++) {
            s.push(p->val);
            p = p->next;
        }
        for(int i=0;i<n-m+1;i++){
            int h = s.top();
            s.pop();
            q->val = h;
            q = q->next;
        }
        return head;
        
    }
};