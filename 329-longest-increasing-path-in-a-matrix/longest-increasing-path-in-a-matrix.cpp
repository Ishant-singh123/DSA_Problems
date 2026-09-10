class Solution {
public:
    int dfs(vector<vector<int>>&v,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=v.size() ||j>=v[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int currmax=1;
        if(i+1>=0 && i+1<v.size() && v[i+1][j]>v[i][j]){
            currmax=max(currmax,1+dfs(v,i+1,j,dp));
        }
        if(i-1>=0 && i-1<v.size() && v[i-1][j]>v[i][j]){
            currmax=max(currmax,1+dfs(v,i-1,j,dp));
        }
        if(j+1>=0 && j+1<v[0].size() && v[i][j+1]>v[i][j]){
            currmax=max(currmax,1+dfs(v,i,j+1,dp));
        }
        if(j-1>=0 && j-1<v[0].size() && v[i][j-1]>v[i][j]){
            currmax=max(currmax,1+dfs(v,i,j-1,dp));
        }
        return dp[i][j]=currmax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=INT_MIN;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
               ans=max(ans,dfs(matrix,i,j,dp));
            }
        }
        return ans;
    }
};