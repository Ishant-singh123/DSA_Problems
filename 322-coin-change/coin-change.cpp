class Solution {
public:
    int solver(vector<int>&coins,int amt,vector<int>&dp){
        if(amt<0){
            return 10000;
        }
        if(dp[amt]!=-1){
            return dp[amt];
        }
        if(amt==0){
            return 0;
        }
        int ans=10000;
        for(int i=0;i<coins.size();i++){
            ans=min(ans,1+solver(coins,amt-coins[i],dp));
        }
        return dp[amt]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
       int res= solver(coins,amount,dp);
       if(res==10000 && amount!=10000){
        return -1;
       }
        return res;
    }
};