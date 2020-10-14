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
    
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left and !root->right) return root->val;
        
        if(dp.count(root)) return dp[root];
        
        int total = root->val;
        if(root->left) {
            total += rob(root->left->left);
            total += rob(root->left->right);
        }
        if(root->right){
            total += rob(root->right->right);
            total += rob(root->right->left);
        }
        int notThis = rob(root->left) + rob(root->right);
        
        return dp[root] = max(total,notThis);
        
    }
};