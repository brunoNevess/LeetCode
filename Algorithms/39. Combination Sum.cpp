class Solution {
public:

   
    
    void helper(vector<int>& c,vector<int>& v,int target,int sum,vector<vector<int>>& ans,int init){
        if(sum == target){
           ans.push_back(v);
           return;
        }
        for(int i=init;i<c.size();i++){
            if(sum+c[i]<=target){
                cout << sum + c[i]<<endl;
                v.push_back(c[i]);
                helper(c,v,target,sum+c[i],ans,i);
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates,v,target,0,ans,0);
        return ans;
    }
};