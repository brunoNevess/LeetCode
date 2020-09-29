class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums),end(nums),[&](int p1,int p2){
            string s1 = to_string(p1);
            string s2 = to_string(p2);
            return s1 + s2 > s2 + s1;
        });
        if(nums[0] == 0 and nums[nums.size()-1] == 0) return "0";
        string s = "";
        for(auto& x:nums) s+=to_string(x);
        return s;
    }
};