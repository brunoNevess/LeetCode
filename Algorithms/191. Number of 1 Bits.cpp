class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t s = 1;
        int ans = 0;
        for(int i=0;i<32;i++){
            if(s & n) ans++;
            s = s<<1;
        }
        return ans;
        
    }
};