class Solution {
public:

    string reverseWords(string s) {
        if(s.size() == 0) return {};
        
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            while(i<s.size() and s[i] == ' ') i++;
            int j = i;
            while(j<s.size() and s[j]!=' ') j++;
            reverse(s.begin()+i,s.begin()+j);
            i = j;
        }
      
        while(s[0]== ' ' ) s.erase(s.begin()); 
        
        for(int j=0;j<s.size();j++){
            while(j<s.size() and s[j]!=' ') j++;
            j++;
            while(j<s.size() and s[j] == ' ') s.erase(s.begin()+j);
            j--;
        }
        if (s[s.size()-1]==' ') s.erase(s.end()-1);
        return s;
        
    }
};