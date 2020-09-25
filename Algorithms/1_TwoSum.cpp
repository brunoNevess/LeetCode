class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> s;
        for(int i=0;i<nums.size();i++){
                if(!(s.find(target-nums[i])==s.end())){
                        vector<int> v({s[target-nums[i]],i});
                        return v;
                }
                s[nums[i]] = i;
        }
        return vector<int>();
    }
};