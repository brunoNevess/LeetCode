class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(),m = needle.size();
        if(m == 0 ) return 0;
        if(n<m) return -1;
        if(n==m) return haystack == needle ? 0 :-1;
        
        for(int i=0;i<=n-m;i++){
            if(haystack.substr(i,m) == needle) return i;
        }
        return -1;
        
    }
};