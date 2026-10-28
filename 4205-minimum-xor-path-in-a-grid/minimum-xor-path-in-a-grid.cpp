class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int val,vector<vector<vector<int>>>&dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() ){
            return 1024;
        }
        val=val^grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return val;
        }
        if(dp[i][j][val]!=-1){
            return dp[i][j][val];
        }
        return dp[i][j][val]=min(dfs(grid,i+1,j,val,dp),dfs(grid,i,j+1,val,dp));
    }
    int minCost(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1024,-1)));
        return dfs(grid,0,0,0,dp);
    }
};