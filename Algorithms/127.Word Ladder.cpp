class Solution {
public:
    
 bool oneDistance(string &word1, string &word2){
    bool change = false;
    
    for (int i=0; i<word1.size(); i++){
        if (word1[i]!=word2[i]){
            if (change){
                return false;
            }
            change = true;
        }
    }
    
    return true;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        if (find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
        
        unordered_map<string,int> d;
        for(auto p:wordList) d[p] = INT_MAX;
        
        d[endWord] = 0;
        
        queue<string> q;
        q.push(endWord);
        while(!q.empty()){
            string current = q.front();
            q.pop();
            for(auto w:wordList){
                if (oneDistance(w,current)){
                    if (d[w] == INT_MAX){
                        d[w] = 1+d[current];
                        q.push(w);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto w:wordList){
            if(oneDistance(w,beginWord)) ans = min(ans,d[w]);
        }
        return ans == INT_MAX ? 0:ans+2;
    }
};