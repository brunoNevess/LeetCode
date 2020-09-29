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
    
    bool aux(TreeNode* root,int sum,int sumTilNow){
        if (root == NULL) return false;
        int val = sumTilNow+root->val;
        if (root->left == NULL and root->right == NULL and val == sum)
            return true;
        return aux(root->left,sum,val) or aux(root->right,sum,val);
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return aux(root,sum,0);
    }
};