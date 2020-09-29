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
    vector<int> ans;
    
    void traversal(TreeNode* root){
        if(!root) return;
        traversal(root->left);
        ans.push_back(root->val);
        traversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }
};