/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            
            vector<int> p;
            int l = q.size();
            while (l--){
                TreeNode* a = q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if (a->right) q.push(a->right);
                p.push_back(a->val);
            }
            ans.push_back(p);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};