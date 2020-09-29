class Solution {
public:
    
    long long reverse(int x){
        long long ans = 0;
        while(x){
            ans = ans*10 + x%10;
            x/=10;
        }
        return ans; 
    }
    
    bool isPalindrome(int x) {
        if (x < 0) return false;
        return x == reverse(x);
    }
};