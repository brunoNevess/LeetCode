class Solution {
public:
    vector<string> ans;
    
    void fill(string s,int closed,int open,int n){
        
        if(open == n and closed == n) {
            ans.push_back(s);
            return;
        }
        
        if(open < n){
            s.push_back('(');
            fill(s,closed,open+1,n);
            s.pop_back();
        }
        if(closed < open){
            s.push_back(')');
            fill(s,closed+1,open,n);
            s.pop_back();
        }
        return;
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        fill(s,0,0,n);
        return ans;
    }
};