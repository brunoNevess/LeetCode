/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int zig = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            while(n--){
                auto x = q.front();
                q.pop();
                v.emplace_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        if(zig == 1) reverse(v.begin(),v.end());
        ans.push_back(v);
        zig = 1 - zig;
        }
        return ans;
    }
   
};