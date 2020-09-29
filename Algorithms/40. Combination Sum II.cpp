class Solution {
public:

   
    
    void helper(vector<int>& c,vector<int>& v,int target,int sum,set<vector<int>>& ans,int init){
        if(sum == target){
           ans.insert(v);
           return;
        }
        for(int i=init;i<c.size();i++){
            if(sum+c[i]<=target){
                v.push_back(c[i]);
                helper(c,v,target,sum+c[i],ans,i+1);
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        set<vector<int>> s;
        sort(candidates.begin(),candidates.end());
        helper(candidates,v,target,0,s,0);
        vector<vector<int>> ans(s.begin(),s.end());

        return ans;
    }
};