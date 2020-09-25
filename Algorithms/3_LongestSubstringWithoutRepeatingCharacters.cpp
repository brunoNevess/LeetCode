class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int ans = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                start = max(start,mp[s[i]]+1);
            }
            mp[s[i]] = i ;
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};