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
        
 
    bool rec(TreeNode* r,long long lower,long long upper){
        
        if(!r) return true;
        
        int curr = r->val;
        if(curr > lower and curr < upper){
            return rec(r->left,lower,curr) and rec(r->right,curr,upper);
        }
        else return false;    
    }
    
    bool isValidBST(TreeNode* root) {
        return rec(root,LLONG_MIN,LLONG_MAX);
    }
};