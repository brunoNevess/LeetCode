#define GREY 1
#define WHITE 0
#define BLACK 2

class Solution {
public:
    stack<int> s;
    bool hasCycle = false;
    void dfs(int u,const vector<vector<int>>& g, vector<int>& color){
        
        color[u] = GREY;
        for(int i=0;i<g.size();i++){
            if(g[i][1]==u){
                if(color[g[i][0]]==WHITE)dfs(g[i][0],g,color);
                else if(color[g[i][0]] == GREY){
                    hasCycle = true;
                    return;
                }
            
            }
                    
       }
        color[u] = BLACK;
        s.push(u);
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> color(numCourses,WHITE);
        for(int i=0;i<numCourses;i++) if(color[i] == WHITE) dfs(i,prerequisites,color);
        if(hasCycle) return ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};