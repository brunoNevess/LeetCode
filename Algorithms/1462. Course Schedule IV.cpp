#define vi vector<int>
#define pb push_back
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qr) {
        unordered_map<int,set<int> > adj;
        unordered_map<int,set<int> > p;
        vi in(n,0);
        for(auto v:pre){
                adj[v[0]].insert(v[1]);
                in[v[1]]++;      
        }

        vector<bool> ans;
        queue<int>q;
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i),cout<<i;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto nx:adj[node]){
                p[nx].insert(node);
                p[nx].insert(p[node].begin(),p[node].end());
                if(--in[nx]==0)
                    q.push(nx);
            }
        }
        for(auto it:qr){
            if(p[it[1]].find(it[0])!=p[it[1]].end())
                ans.pb(true);
            else
                ans.pb(false);
            
        }return ans;
    }
};