class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(char c:t) freq[c]++;
        int left = 0 , right = 0 , minLen = INT_MAX ,minStart,remaining = t.size();
        while(right < s.size()){
            if(--freq[s[right++]] >= 0) remaining--;
            while(remaining == 0){
                if(right -left < minLen){
                    minLen = right-left;
                    minStart = left;
                }
                if(++freq[s[left++]] > 0) remaining++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart,minLen);
        
    }
};