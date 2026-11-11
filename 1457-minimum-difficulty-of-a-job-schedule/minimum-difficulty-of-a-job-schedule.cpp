class Solution {
public:
    int solver(vector<int>&v,int i,int d,int maxi,vector<vector<vector<int>>>&dp){
        if(d==0 && i==v.size()){
            return 0;
        }
        if(d==0 && i<v.size()){
            return 1000000;
        }
        if(d>0 && i==v.size()){
            return 1000000;
        }
        if(dp[i][d][maxi+1]!=-1){
            return dp[i][d][maxi+1];
        }
        int ans=INT_MAX;
        ans=min(ans,solver(v,i+1,d,max(maxi,v[i]),dp));
        ans=min(ans,max(maxi,v[i])+solver(v,i+1,d-1,-1,dp));
        return dp[i][d][maxi+1]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d){
            return -1;
        }
        vector<vector<vector<int>>>dp(jobDifficulty.size(),vector<vector<int>>(d+1,vector<int>(10002,-1)));
        int res=solver(jobDifficulty,0,d,-1,dp);
        if(res==1000000){
            return -1;
        }
        return res;
    }
};