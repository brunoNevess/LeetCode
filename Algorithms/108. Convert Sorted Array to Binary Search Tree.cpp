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
    
    
     TreeNode* helper(vector<int>& nums, int l,int r){
        if (l>r) return nullptr ;
        int m = l + (r-l)/2;
         
        auto p = new TreeNode(nums[m]);
        p->right = helper(nums,m+1,r);
        p->left = helper(nums,l,m-1);
         
        return p;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};