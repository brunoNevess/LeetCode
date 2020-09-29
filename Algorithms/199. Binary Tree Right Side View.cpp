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
    
   
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v; 
        if(!root) return v;
        
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* a = q.front();
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
              
                if(n == 0) v.push_back(a->val);
            }
        }
        return v;
    }
};