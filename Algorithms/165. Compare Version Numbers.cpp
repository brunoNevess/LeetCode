class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n = version1.size() , m = version2.size();
        string s1,s2;
        while(true){
            s1 = "", s2 = "";
            while(i < n and version1[i]!='.') s1 += version1[i++];
            while(j < m and version2[j]!='.') s2 += version2[j++];
            int n1 = stoi(s1) , n2 = stoi(s2);
            if(n1 < n2) return -1;
            if(n1 > n2) return 1;
            i++;j++;
            if(i>=n or j>=m) break;
        }
        s1 = s2 = "";
        if(i >= n and j >=m) return 0;
        
        if(i >= n){
            while(true){
                while(j < m and version2[j]!='.') s2 += version2[j++];
                int n2 = stoi(s2);
                if( stoi(s2) != 0) return -1;
                s2 = "";
                j++;
                if(j>=m) break;
            }
        }
        else {
            while(true){
                while(i < n and version1[i]!='.') s1 += version1[i++];
                if( stoi(s1) !=0 ) return 1;
                s1 = "";
                i++;
                if(i>=n) break;
            }
        }
        
        return 0;
    }
};