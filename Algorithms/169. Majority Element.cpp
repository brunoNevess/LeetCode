class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(); 
        if(n==1 or n==2) return nums[0];
        for(int j=1;j<n;j++){
            int f = 1;
            int i=j;
            while(i<n and nums[i] == nums[i-1] ) {
                f++;i++;
            }
            
            if (f > n/2) return nums[j];
            j = i;
        }  
        return -1;
    }
};