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
    
    bool crawl(TreeNode* right,TreeNode* left){
        if (right == NULL and left == NULL) return true;
        if (right == NULL and left!=NULL or (right!=NULL and left == NULL)) return false;
        if (right->val == left->val) return crawl(right->left,left->right) and crawl(right->right,left->left);
        else return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        else return crawl(root->right,root->left);
    }
};