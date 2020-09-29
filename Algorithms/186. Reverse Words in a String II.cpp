class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(begin(s),end(s));
        
        int ini = 0,end = 0;
        for(int ini = 0;ini < s.size();ini++){
            if(s[ini]!=' '){
                end = ini;
                while(end < s.size() and s[end]!=' ') end++;
                reverse(begin(s)+ini,begin(s)+end);
                ini = end;
            }            
        }
    }
};