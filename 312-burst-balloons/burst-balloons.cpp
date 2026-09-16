class Solution {
public:
    int solver(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
           ans=max(ans, nums[i-1]*nums[k]*nums[j+1]+solver(nums,i,k-1,dp)+solver(nums,k+1,j,dp));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        vector<int>v;
        v.push_back(1);
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        vector<vector<int>>dp(v.size()+1,vector<int>(v.size()+1,-1));
        return solver(v,1,v.size()-2,dp);
    }
};