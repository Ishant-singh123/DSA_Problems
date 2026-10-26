class Solution {
public:
    long long dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==-1){
            return 0;
        }
        long long sum=grid[i][j];
        grid[i][j]=-1;
        sum=sum+dfs(grid,i+1,j);
        sum=sum+dfs(grid,i-1,j);
        sum=sum+dfs(grid,i,j+1);
        sum=sum+dfs(grid,i,j-1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && grid[i][j]!=-1){
                    if(dfs(grid,i,j)%k==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};