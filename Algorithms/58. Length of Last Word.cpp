class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int k = s.size()-1;
        while(k>=0 and s[k]==' ') k --;
        while(k>=0 and s[k]!=' '){
            k--;
            l++;
        }
        return l;
    }
};