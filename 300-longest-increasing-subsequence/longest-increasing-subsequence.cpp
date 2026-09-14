class Solution {
public:
    int solver(vector<int>&nums,int indx,int last,vector<vector<int>>&dp){
        if(indx==nums.size()){
            return 0;
        }
        if(dp[indx][last]!=-1){
            return dp[indx][last];
        }
        int ans=INT_MIN;
        if(last<nums[indx]){
            ans=max(ans,1+solver(nums,indx+1,nums[indx],dp));
        }
        ans=max(ans,solver(nums,indx+1,last,dp));
        return dp[indx][last]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(20002,-1));
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]+10001;
        }
        return solver(nums,0,0,dp);
    }
};