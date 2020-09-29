/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    vector<int> v;
    int c = 0;
    BSTIterator(TreeNode* root) {
      
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        while (curr or !s.empty()){
            
            while (curr){
                s.push(curr);
                curr = curr->left;
            }
            
            TreeNode* tmp = s.top();
            s.pop();
            v.push_back(tmp->val);
            curr = tmp->right;
            
        }
        
        
    }
    
    /** @return the next smallest number */
    int next() {
       
            int p = v[c];
            c++;
            return p;
          
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return c < v.size();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */