class Solution {
public:
    
    unordered_map<int,int> dp;
    vector<vector<int>> g;
    
    int longest(int x){
        if(dp.count(x)) return dp[x];
        int l = 0;
        for(int i=0;i<g[x].size();i++){
            l = max(l,1+longest(g[x][i]));
        }
        return dp[x] = l;
    }
    bool isValid(int x,int y,int n,int m){return x>=0 and y>=0 and x<n and y<m;}
  
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        
        int m = matrix[0].size();
        
        g.resize(n*m);
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx = j + m*i;
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(isValid(nx,ny,n,m) and matrix[i][j] < matrix[nx][ny]) {
                        int idx2 = ny + nx*m;
                        g[idx].push_back(idx2);
                    }
                }
                
            }
        } 
        int ans = INT_MIN;
        for(int i=0;i<n*m;i++){
            ans = max(ans,longest(i));
        }
        return ans == INT_MIN ? 0 : ans+1;
    }
};