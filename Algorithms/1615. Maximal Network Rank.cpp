class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> g(n,vector<bool>(n,false));
        vector<int> deg(n);
        for(auto& e: roads){
            int u = e[0];
            int v = e[1];
            deg[v]++;
            deg[u]++;
            g[u][v] = g[v][u] = true;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = deg[i]+deg[j];
                ans = max(ans,sum-g[i][j]);
            }
        }
        return ans;
    }
};
// pick two vertices such that degree[i] + degree[j] is max
// problem: shared vertices