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
    
    void rotate(vector<int>& v,int k){
        int curr = v[0],first = 0;
        int n = v.size(),i=0,j = v.size();
        //i ---> (i+k)%M
        while(j--){
            int next = (i+k)%n;
            swap(v[next],curr);
            i = next;
            if(i == first){
                i = (i+1)%n;
                first = i;
                curr = v[i];
            }
           
        }  
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> v;
        if(!head) return nullptr;
        ListNode* h = head;
        while(h){
            v.push_back(h->val);
            h = h->next;
        }
        rotate(v,k);
        ListNode* ans = new ListNode(v[0]);
        ListNode* p = ans;
        for(int i=1;i<v.size();i++){
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return ans; 
    }
};