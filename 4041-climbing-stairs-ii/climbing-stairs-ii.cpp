class Solution {
public:
    int solver(vector<int>&cost,int i,vector<int>&dp){
        if(i>=cost.size()){
            return 100000;
        }
        if(i==cost.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        ans=min(ans,cost[i+1]+1+solver(cost,i+1,dp));
        if(i+2<=cost.size()-1){
            ans=min(ans,cost[i+2]+4+solver(cost,i+2,dp));
        }
        if(i+3<=cost.size()-1){
            ans=min(ans,cost[i+3]+9+solver(cost,i+3,dp));
        }
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<costs.size();i++){
            v.push_back(costs[i]);
        }
        vector<int>dp(v.size(),-1);
        return solver(v,0,dp);
    }
};