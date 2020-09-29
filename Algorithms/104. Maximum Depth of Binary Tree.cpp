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
    int height(TreeNode* root,int num){
        if(root->left == NULL and root->right == NULL) return num;
        int leftH,leftR;
        leftH = leftR = -1;
        if(root->left!=NULL )leftH = height(root->left,num+1);
        if(root->right!=NULL) leftR = height(root->right,num+1);
        return max(leftH,leftR);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return height(root,1);   
    }
};