class Solution {
public:
    void dfs(vector<vector<int>>&v,int i,int j){
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size()){
            return ;
        }
        if(v[i][j]==-1 || v[i][j]==0){
            return ;
        }
        v[i][j]=-1;
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j+1);
        dfs(v,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
        }
        for(int i=0;i<grid.size();i++){
            if(grid[i][grid[0].size()-1]==1){
                dfs(grid,i,grid[0].size()-1);
            }
        }
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]==1){
                dfs(grid,0,j);
            }
        }
        for(int j=0;j<grid[0].size();j++){
            if(grid[grid.size()-1][j]==1){
                dfs(grid,grid.size()-1,j);
            }
        }
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};