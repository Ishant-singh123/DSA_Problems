class Solution {
public:
    int solver(vector<vector<int>>&v,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int count=0;
        if(i+1>=0 && i+1<v.size() && v[i+1][j]>v[i][j]){
            count=count+solver(v,i+1,j,dp);
        }
        if(i-1>=0 && i-1<v.size() && v[i-1][j]>v[i][j]){
            count=count+solver(v,i-1,j,dp);
        }
        if(j-1>=0 && j-1<v[0].size() && v[i][j-1]>v[i][j]){
            count=count+solver(v,i,j-1,dp);
        }
        if(j+1>=0 && j+1<v[0].size() && v[i][j+1]>v[i][j]){
            count=count+solver(v,i,j+1,dp);
        }
        return dp[i][j]=(count+1)%1000000007;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans=(ans+solver(grid,i,j,dp))%1000000007;
            }
        }
        return ans%1000000007;
    }
};