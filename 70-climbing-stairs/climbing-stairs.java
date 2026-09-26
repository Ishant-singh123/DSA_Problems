class Solution {
    int solver(int n,int []dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=solver(n-1,dp)+solver(n-2,dp);
    }
    public int climbStairs(int n) {
        int []dp=new int[46];
        for(int i=0;i<46;i++){
            dp[i]=-1;
        }
        return solver(n,dp);
    }
}