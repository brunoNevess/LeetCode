class Solution {
public:
 
    void find(vector<int>& nums,int i,int j,bool& found,int& ans){
        if(i>j or found) return;
        int med = i + (j-i)/2;
        int l = med - 1 < 0 ? INT_MIN : nums[med-1];
        int r = med + 1 == nums.size() ? INT_MIN :nums[med+1];
        if(nums[med] > l and nums[med] > r){
            found = true;
            ans = med;
            return;
        } 
        find(nums,i,med-1,found,ans);
        find(nums,med+1,j,found,ans);
    }
    int findPeakElement(vector<int>& nums) {
        bool found = false;
        int ans = 0;
        find(nums,0,nums.size()-1,found,ans);
        return ans;
    }
};