class Solution {
public:
    int titleToNumber(string s) {
        map<char,int> dic;
        for(int i = 1;i<=26;i++){
            dic['A'+i-1] = i;
        }
        if(s.size() == 1) return dic[s[0]];
        int ans = 0;
        for(int i=s.size()-1,p=0;i>=0;i--,p++){
            ans += dic[s[i]]*pow(26,p);
        }
        return ans;
    }
};