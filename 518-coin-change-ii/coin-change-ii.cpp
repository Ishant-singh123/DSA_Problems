class Solution {
public:
    int solver(vector<int>&coins,int indx,int amt,vector<vector<int>>&dp){
        if(indx>=coins.size()){
            return 0;
        }
        if(amt<0){
            return 0;
        }
        if(amt==0){
            return 1;
        }
        if(dp[indx][amt]!=-1){
            return dp[indx][amt];
        }
        int count=0;
        for(int i=indx;i<coins.size();i++){
            count=count+solver(coins,i,amt-coins[i],dp);
        }
        return dp[indx][amt]=count;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solver(coins,0,amount,dp);
    }
};