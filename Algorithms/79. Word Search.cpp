class Solution {
public:
    
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int M,N;
    bool found = false;
    string word;
    int visited[201][201];
    bool dfs(vector<vector<char>>& board,int x, int y,int pos){
        
        if(pos == word.size()) return true;
        if(x >= N or y >= M or x< 0 or y < 0 or visited[x][y] == 1 or board[x][y] != word[pos]) return false;
       
        
        visited[x][y] = 1;
        for(int i=0;i<dx.size();i++){
            if(dfs(board,x+dx[i],y+dy[i],pos+1))
                    return true;
        }
        visited[x][y] = 0;
        return false;
     
    }
    
    bool exist(vector<vector<char>>& board, string w) {
        M = board[0].size();
        N = board.size();
        word = w;
       // memset(visited,0,sizeof visited);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) if(board[i][j] == word[0]) if(dfs(board,i,j,0)) return true;
        //return found;
        return false;
    }
};  