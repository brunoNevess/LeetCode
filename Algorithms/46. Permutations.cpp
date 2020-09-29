class Solution {
public:
    
    void backTrack(vector<vector<int>>& ans,vector<int>& v,vector<int>& nums,unordered_set<int>& s){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i])){
                v.push_back(nums[i]);
                s.insert(nums[i]);
                backTrack(ans,v,nums,s);
                v.pop_back();
                s.erase(nums[i]);
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> s;
        vector<vector<int>> ans;
        vector<int> v;
        backTrack(ans,v,nums,s);
        return ans;
    }
};