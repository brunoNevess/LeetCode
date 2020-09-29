class Solution {
public:
    string convertToTitle(int n) {
        unordered_map<int,char> mp;
        for(int i=1;i<=26;i++) mp[i-1] = 'A'+(i-1);
        string ans="";
        while(n){
            ans += mp[--n%26];
            n/=26;
        }
        reverse(begin(ans),end(ans));
        return ans;
        
    }
};