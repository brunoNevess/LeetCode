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
        if(lists.empty()) return nullptr;
        vector<int> v;
        for(ListNode* l:lists){
            ListNode* j = l;
            while(j){
                v.push_back(j->val);
                j = j->next;
            }
        }
    
        sort(v.begin(),v.end());
        ListNode* ans = nullptr,*ptr = nullptr;
        for(int x:v){
            if(!ptr){
                ptr = new ListNode(x);
                ans = ptr;
            }
            else{
                ptr->next = new ListNode(x);
                ptr = ptr->next;
            }
        }
        return ans;
    }
};