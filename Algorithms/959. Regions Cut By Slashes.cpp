

/*
    10 --> 0 1
    divide each cell as :       0           0
                            3.      1 -- 3.    1
                                2           2            
*/
class Solution {
public:
    
    int H,W;
    vector<vector<vector<bool>>> visited;
    vector<string> grid;
    bool isValid(int x,int y){return x>=0 and x<H and y>=0 and y < W;}
    
    void dfs(int i,int j,int t){
        if(!isValid(i,j) or visited[i][j][t]) return;
        visited[i][j][t] = true;
        //for each neighbour
        if(t == 0) dfs(i-1,j,2);
        else if(t == 1) dfs(i,j+1,3);
        else if(t == 2) dfs(i+1,j,0);
        else if(t == 3) dfs(i,j-1,1);
        
        if(grid[i][j] != '/') dfs(i,j, t ^ 1);
        if(grid[i][j] != '\\') dfs(i,j,t ^ 3);
    }
    
    int regionsBySlashes(vector<string>& _grid) {
        grid = _grid;
        H = grid.size();
        W = grid[0].size();
        visited.assign(H,vector<vector<bool>>(W,vector<bool>(4,false)));
        int regions = 0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                for(int t = 0;t<4;t++){
                    if(!visited[i][j][t]){
                        dfs(i,j,t);
                        regions++;
                    }
                }
            }
        }
        return regions;   
    }
};