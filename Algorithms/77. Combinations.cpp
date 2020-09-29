class Solution {
public:
    
    vector<vector<int>> out;
    int N;
  
    void solve(int pos,int k,vector<int>& v){
        if(v.size() == k){
            out.push_back(v);
            return;
        }
        for(int i=pos;i<=N;i++){
                v.push_back(i);
                solve(i+1,k,v);
                v.pop_back();
             
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        N = n;
        vector<int> v;
        solve(1,k,v);
        return out;
        
    }
};