class Solution {
public:
    // same flood fill ki taraha kiya h 
    vector<pair<int,int>>internal;
    void dfs(vector<vector<int>>&grid,int row,int col,int color,int newcolor){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()){
            return ;
        }
        if(grid[row][col]!=color){
            return ;
        }
        grid[row][col]=-newcolor;
        dfs(grid,row+1,col,color,newcolor);
        dfs(grid,row-1,col,color,newcolor);
        dfs(grid,row,col+1,color,newcolor);
        dfs(grid,row,col-1,color,newcolor);

        if(!(row==0 || col==0 || row==grid.size()-1 || col==grid[0].size() || grid[row+1][col]!=-newcolor || grid[row-1][col]!=-newcolor || grid[row][col-1]!=-newcolor || grid[row][col+1]!=-newcolor)){
            internal.push_back({row,col});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color){
            return grid;
        }
        int oldcolor=grid[row][col];
        dfs(grid,row,col,grid[row][col],color);
        for(int i=0;i<internal.size();i++){
            grid[internal[i].first][internal[i].second]=oldcolor;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==-color){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};