class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0 ;
        int n = A.size();
        vector<bool> ans(n);
        int base = 2;
        for(int i=0;i<n;i++){
            num = (base*num + A[i])%5;
            ans[i] = num == 0;
            
        }
        return ans;
    }
};  