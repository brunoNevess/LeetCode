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
    
    int sum = 0;
    void crawl(TreeNode* root,int n){
        
        if (root == NULL) return;
        n = 10*n + root->val;
        if (root->left == NULL and root->right == NULL){
            sum += n;
            return;
        }
        crawl(root->left,n);
        crawl(root->right,n);
    }
    
    int sumNumbers(TreeNode* root) {
        crawl(root,0);
        return sum;
    }
};