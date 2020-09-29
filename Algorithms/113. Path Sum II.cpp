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
    
    
    vector<vector<int>> ans;
    void crawl(TreeNode* root,vector<int>& v,int sumTilNow,int sum){
        if (root == NULL) return;
        v.push_back(root->val);
        int p = sumTilNow+root->val;
        if (root->left == NULL and root->right == NULL){
            if(p == sum) {
                ans.push_back(v);
            } 
            v.pop_back();
            return;
        
        }
        crawl(root->left,v,p,sum);
        crawl(root->right,v,p,sum);
        v.pop_back();
    }
        
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> v;
        crawl(root,v,0,sum);
        return ans;
    }
};