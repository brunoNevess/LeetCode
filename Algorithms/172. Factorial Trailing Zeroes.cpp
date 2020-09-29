class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        
        int k =  (int)(1.0*log10(n)/log10(5));
        
        for(int i=1;i<=k;i++){
            ans += (int)(1.0*n/pow(5,i));
        }
        return ans;
        
    }
};