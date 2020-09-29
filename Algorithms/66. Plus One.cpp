class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1 ;
        int sum = 0;
        
        int head = digits.size()-1;
        for(int i=head;i>=0;i--){
            sum = carry+digits[i];
            ans.push_back(sum%10);
            carry = sum/10;
        }
        if(carry == 1) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};