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
    ListNode* sortList(ListNode* head) {
        
        ListNode* p = head;
        vector<int> v;
        while(p) {
            v.push_back(p->val);
            p = p->next;
        }
        sort(v.begin(),v.end());
        p = head;int i=0;
        while(p){
            p->val = v[i];i++;p=p->next; 
        }
        return head;
        
    }
};