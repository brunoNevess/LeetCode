#define BLACK 1
#define WHITE 0
#define GRAY 2
class Solution {
public:
    
    
    
    bool hasCycle;
    Solution():hasCycle(false){}
    
    void dfs(const vector<vector<int>>& g,vector<int>& C,int u){
        C[u] = GRAY;
        for(int i=0;i<g[u].size();i++){
            if (C[g[u][i]] == GRAY) {
                hasCycle = true;
                return;
            }
            else {
                if (C[g[u][i]]==WHITE) dfs(g,C,g[u][i]);
            }
        }
        C[u] = BLACK;
        return;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> C(numCourses,WHITE);
        for(auto x:prerequisites) g[x[0]].push_back(x[1]);
        for(int i=0;i<numCourses;i++) dfs(g,C,i);
        return !hasCycle;
    }
};