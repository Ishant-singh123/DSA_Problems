class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,bool &check){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1){
            return ;
        }
        if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1){
            check=false;
            // return ;
        }
        if(grid[i][j]==-1){
            return ;
        }
        grid[i][j]=-1;
        dfs(grid,i+1,j,check);
        dfs(grid,i-1,j,check);
        dfs(grid,i,j-1,check);
        dfs(grid,i,j+1,check);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                if(grid[i][j]==0){
                    bool check=true;
                    dfs(grid,i,j,check);
                    if(check==true){
                        cnt++;
                    }
                }
            }
        }      
        return cnt;
    }
};