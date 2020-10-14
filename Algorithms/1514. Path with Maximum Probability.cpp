typedef pair<double,int> di;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<di>> graph(n);
        int i = 0;
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            graph[u].push_back(di(succProb[i],v));
            graph[v].push_back(di(succProb[i],u));
            i++;
        }
        
        priority_queue<di> pq;
        vector<double> prob(n,0);
        prob[start] = 1;
        pq.push(di(prob[start],start));
        while(!pq.empty()){
            di tmp = pq.top();
            pq.pop();
            double p = tmp.first;
            int u = tmp.second;
            if( p < prob[u]) continue;
            for(di x:graph[u]){
                int v = x.second;
                double pp = x.first;
                if(prob[v] < prob[u]*pp) {
                    prob[v] = prob[u]*pp;
                    pq.push(di(prob[v],v));
                }
            }
        }
        return prob[end];
    }
};