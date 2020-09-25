
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int answer;
    int dfs(TreeNode* root){
            
            if(!root) return 0;
            
            int x = dfs(root->left);
            int y = dfs(root->right);
            answer = max(answer,x+y+root->val);
            int ret = root->val + max(x,y);
            ret = max(ret,0);
            return ret;
        }
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
        
        
        
    }
};