class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        
        sort(begin(v),end(v),[&](int i,int j){
            string s1 = to_string(i);
            string s2 = to_string(j);
            
            int m = min(s1.size() , s2.size());
            for(int k=0;k<m;k++){
               if(s1[k]!=s2[k]) return s1[k] < s2[k];
                
            }
            return s1.size() < s2.size(); 
        });
        return v;      
    }
};