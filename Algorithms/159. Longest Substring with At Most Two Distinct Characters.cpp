typedef pair<int,int> ii;
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() < 2) return s.size();
        unordered_map<int,int> ind;
        int j = 0,i=0;
        int ans = -1;
        while(j<s.size()){
            char c = s[j];
            if(ind.size() < 3) ind[c] = j++;
            if(ind.size()==3){
                auto it = min_element(begin(ind),end(ind),[&](ii i1,ii i2){
                    return i1.second < i2.second;
                });
                i = it->second + 1;
                ind.erase(it);
            }
            ans = max(ans,j - i);
        }
        return ans;
    }
};