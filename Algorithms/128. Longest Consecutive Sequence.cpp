typedef long long ll;
class Solution {
public:
    
    int dfs(int u,vector<vector<int>>& g,vector<bool>& visited){
        if(visited[u]) return 0;
        int c = 1;
        visited[u]=true;
        for(int v:g[u]){
            if(not visited[v]){
                c += dfs(v,g,visited);
            }
        }
        return c;
    }
    
    int longestConsecutive(vector<int>& nums) {        
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> s;
        for(int x:nums) s.insert(x);
        nums = vector<int>(begin(s),end(s));
        n = nums.size();
        vector<vector<int>> g(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((ll)nums[j] == (ll)nums[i]+1 or (ll)nums[i] == (ll)nums[j]+1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans = max(ans,dfs(i,g,visited));
            }
        }
        return ans;
    }
};

        //works for condensed numbers
//         int n = nums.size();
//         if(n==0) return 0;
//         long long R = *max_element(begin(nums),end(nums)) ;
//         long long L = *min_element(begin(nums),end(nums)) ;
        
//         long long len = R - L + 1;
//         vector<bool> seen(len);
//         for(int x:nums) seen[x-L] = true;
//         int ans = 0;
//         int sum = 0;
//         for(int i=0;i<seen.size();i++){
//             if(!seen[i]) sum = 0;
//             else sum += 1;
            
//             ans = max(sum,ans);
//         }
//         return ans;

// the actual best one 
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> mp;
//         for(int n : nums) mp.insert(n);
        
//         int longestL = 0;
//         for(int n : nums){
//             if(mp.find(n-1) == mp.end()){ 
//             int curNum = n;
//             int currL = 1;
//             while(mp.find(curNum+1) != mp.end()){
//                 curNum += 1;
//                 currL += 1;
//             }
//             longestL = max(longestL, currL);
//             }
//         }
//         return longestL;
//     }
// };